#include "FibonacciIterator.h"

#define FZERO 0
#define FONE  1

FibonacciIterator::FibonacciIterator(int length) : currentValue(FZERO), length(length), currentIndex(0) {
	this->prevValue = 0;
	
	if ( this->length > 0 ) {
		this->last = this->length - 1;
	} else {
		this->last = this->length + 1;
	}
} 

FibonacciIterator::~FibonacciIterator() {
	this->length = 0;
	this->currentIndex = 0;
	this->currentValue = 0;
	this->prevValue = 0;
}
	
void FibonacciIterator::next() { 
    if ( over() ) { 
    	return; 
    } 
    if ( this->length > 0 ) {
	    this->currentIndex += 1;
    	this->calcNextValue();
    } else {
	    this->currentIndex -= 1;
    	this->calcNextValue();
    }
    
     
}

void FibonacciIterator::prev() { 
    if ( over() ) { 
    	return; 
    } 
    if ( this->length > 0 ) {
	    this->currentIndex -= 1;
    	this->calcPrevValue();
    } else {
	    this->currentIndex += 1;
    	this->calcPrevValue();
    }
     
}

void FibonacciIterator::operator++() { 
    next(); 
} 

void FibonacciIterator::operator++(int) { 
    operator++(); 
} 

void FibonacciIterator::operator--() { 
    prev(); 
} 

void FibonacciIterator::operator--(int) { 
    operator--(); 
}

bool FibonacciIterator::over() { 
	if ( length > 0 ) { 
		if ( currentIndex < 0 ) {
	    	this->currentIndex = 0;
	    	this->currentValue = FZERO;
			return true;
		}
		if ( currentIndex > last ) {
			this->currentIndex = this->last;
			this->calcPrevValue();
			return true;
		}
		return false;
	} else {
	    if ( currentIndex < last ) {
	    	this->currentIndex = this->last;
	    	this->calcPrevValue();
			return true;
		}
		if ( currentIndex > 0 ) {
			this->currentIndex = 0;
			this->currentValue = FZERO;
			return true;
		}
		return false;
	}
} 

void FibonacciIterator::calcNextValue() {
	int temp = 0;
	
	if ( this->currentIndex == 1 || this->currentIndex == -1 ) {
	    this->currentValue = FONE;
	} else if ( this->length > 0 ) {
	    temp = this->currentValue;
	    this->currentValue += this->prevValue;
	    this->prevValue = temp;
	} else {
	    temp = this->currentValue;
	    this->currentValue = this->prevValue - this->currentValue;
	    this->prevValue = temp;
	}
} 

void FibonacciIterator::calcPrevValue() {
	int temp = 0;
	
	if ( this->currentIndex == 1 || this->currentIndex == -1 ) {
	    this->currentValue = FONE;
	} else if ( this->currentIndex == 0 ) {
	    this->currentValue = FZERO;
	} else if ( this->length > 0 ) {
	    temp = this->prevValue;
	    this->prevValue = this->currentValue - this->prevValue;
	    this->currentValue = temp;
	} else {
	    temp = this->prevValue;
	    this->prevValue = this->currentValue + this->prevValue;
	    this->currentValue = temp;
	}
} 

long FibonacciIterator::value() {
    return this->currentValue;
}

int FibonacciIterator::operator*() { 
    return value(); 
}  

int FibonacciIterator::getIndex() { 
    return this->currentIndex; 
}  



