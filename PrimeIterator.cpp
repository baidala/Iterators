#include "PrimeIterator.h"

#define MAX_VAL 1000000

PrimeIterator::PrimeIterator(int limit) : limit(limit), currentIndex(1) {
    int sqrt_max_val;
    this->flags = 0;
    this->currentValue = 2;
    
    if ( limit < 0 || limit > MAX_VAL) {
    	throw InvalidLimitException();
    }
    
    sqrt_max_val = (int)sqrt((double)MAX_VAL);
       
    flags = new char [MAX_VAL+1];
    
    if ( !flags ){
    	throw OutOfMemoryException();
    }
    memset(flags, 0, MAX_VAL+1);
    
    for( ; currentValue <= sqrt_max_val; ){
    	
	    for (int i = currentValue * currentValue; i <= MAX_VAL; i += currentValue)
    	flags[i] = true;
		
    	for ( currentValue++; currentValue <= sqrt_max_val && flags[currentValue]; ++currentValue ) ;
    }
    
    this->currentValue = 2;
    
} 

PrimeIterator::~PrimeIterator() {
	this->limit = 0;
	this->currentIndex = 0;
	this->currentValue = 0;
	free(this->flags);
}
	
void PrimeIterator::next() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex += 1;
    this->calcValue();
     
}

void PrimeIterator::prev() { 
    if ( over() ) { 
    	return; 
    } 
    this->currentIndex -= 1;
    this->calcPrevValue();
     
}

void PrimeIterator::operator++() { 
    next(); 
} 

void PrimeIterator::operator++(int) { 
    operator++(); 
} 

void PrimeIterator::operator--() { 
    prev(); 
} 

void PrimeIterator::operator--(int) { 
    operator--(); 
}

bool PrimeIterator::over() { 
	if ( currentIndex < 1 ) {
	    this->currentIndex = 1;
	    this->calcValue();
		return true;
	}
	if ( currentIndex > limit ) {
		this->currentIndex = limit;
		this->calcPrevValue();
		return true;
	}
	return false; 
} 

void PrimeIterator::calcValue() {
    for ( currentValue++; flags[currentValue] && currentValue <= MAX_VAL; currentValue++);
         
} 

void PrimeIterator::calcPrevValue() {
    for ( currentValue--; flags[currentValue] && currentValue >= 2; currentValue--);
         
}

int PrimeIterator::value() {
    return this->currentValue;
}

int PrimeIterator::operator*() { 
    return value(); 
}  

int PrimeIterator::getIndex() { 
    return this->currentIndex; 
}  



