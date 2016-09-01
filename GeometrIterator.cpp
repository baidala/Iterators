#include "GeometrIterator.h"

GeometrIterator::GeometrIterator(int first, int step, int length) : first(first), currentValue(first), step(step), length(length), currentIndex(1) {
    if ( length < 0 ) {
    	throw InvalidArgException();
    }
    if ( first < 0 ) {
    	throw InvalidArgException();
    }
} 

GeometrIterator::~GeometrIterator() {
	this->length = 0;
	this->currentIndex = 0;
	this->currentValue = 0;
	this->step = 0;
	this->first = 0;

}
	
void GeometrIterator::next() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex += 1;
    this->calcValue();
    
     
}

void GeometrIterator::prev() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex -= 1;
    this->calcValue();
     
}

void GeometrIterator::operator++() { 
    next(); 
} 

void GeometrIterator::operator++(int) { 
    operator++(); 
} 

void GeometrIterator::operator--() { 
    prev(); 
} 

void GeometrIterator::operator--(int) { 
    operator--(); 
}

bool GeometrIterator::over() { 
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

void GeometrIterator::calcValue() {
	this->currentValue = this->first *  (unsigned long long)pow(this->step, this->currentIndex - 1 );
} 


unsigned long long GeometrIterator::value() {
    return this->currentValue;
}

int GeometrIterator::operator*() { 
    return value(); 
}  

int GeometrIterator::getIndex() { 
    return this->currentIndex; 
}  



