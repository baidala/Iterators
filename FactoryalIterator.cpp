#include "FactoryalIterator.h"

#define ZEROFACT 1

FactoryalIterator::FactoryalIterator(int length) : currentValue(ZEROFACT), length(length), currentIndex(0) {
    if ( length < 0 ) {
    	throw InvalidLimitException();
    }
    this->last = length - 1;
} 

FactoryalIterator::~FactoryalIterator() {
	this->length = 0;
	this->currentIndex = 0;
	this->currentValue = 0;
	this->last = 0;
}
	
void FactoryalIterator::next() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex += 1;
    this->calcValue();
    
     
}

void FactoryalIterator::prev() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex -= 1;
    this->calcValue();
     
}

void FactoryalIterator::operator++() { 
    next(); 
} 

void FactoryalIterator::operator++(int) { 
    operator++(); 
} 

void FactoryalIterator::operator--() { 
    prev(); 
} 

void FactoryalIterator::operator--(int) { 
    operator--(); 
}

bool FactoryalIterator::over() { 
	if ( currentIndex < 0 ) {
	    this->currentIndex = 0;
	    this->currentValue = ZEROFACT;
		return true;
	}
	if ( currentIndex > last ) {
		this->currentIndex = this->last;
		this->calcValue();
		return true;
	}
	return false; 
} 

void FactoryalIterator::calcValue() {
	this->currentValue = ZEROFACT;
    
    for ( int i = 1; i <= this->currentIndex; i++ ) {
        this->currentValue *= i;
    }
} 

unsigned long long FactoryalIterator::value() {
    return this->currentValue;
}

int FactoryalIterator::operator*() { 
    return value(); 
}  

int FactoryalIterator::getIndex() { 
    return this->currentIndex; 
}  



