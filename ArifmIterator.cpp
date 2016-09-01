#include "ArifmIterator.h"

ArifmIterator::ArifmIterator(int first, int step, int length) : first(first), currentValue(first), step(step), length(length), currentIndex(1) {
    if ( length < 0 ) {
    	throw InvalidLimitException();
    }
} 

ArifmIterator::~ArifmIterator() {
	this->length = 0;
	this->currentIndex = 0;
	this->currentValue = 0;
	this->step = 0;
    this->first = 0;
}
	
void ArifmIterator::next() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex += 1;
    this->calcValue();
    
     
}

void ArifmIterator::prev() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex -= 1;
    this->calcValue();
     
}

void ArifmIterator::operator++() { 
    next(); 
} 

void ArifmIterator::operator++(int) { 
    operator++(); 
} 

void ArifmIterator::operator--() { 
    prev(); 
} 

void ArifmIterator::operator--(int) { 
    operator--(); 
}

bool ArifmIterator::over() { 
	if ( currentIndex < 1 ) {
	    this->currentIndex = 1;
	    this->currentValue = this->first;
		return true;
	}
	if ( currentIndex > length ) {
		this->currentIndex = this->length;
		this->calcValue();
		return true;
	}
	return false; 
} 

void ArifmIterator::calcValue() {
	
	this->currentValue = this->first + this->step * ( this->currentIndex - 1 );
	

} 


int ArifmIterator::value() {
    return this->currentValue;
}

int ArifmIterator::operator*() { 
    return value(); 
}  

int ArifmIterator::getIndex() { 
    return this->currentIndex; 
}  



