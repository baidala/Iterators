#ifndef PRIMEITERATOR_H
#define PRIMEITERATOR_H 

#include <iostream>
#include <memory>
#include <cmath>

class InvalidLimitException {};
class OutOfMemoryException {};

class PrimeIterator { 
	private: 
    	int limit; 
    	int currentIndex;
    	int currentValue;
    	char *flags;
    	void calcValue();
    	void calcPrevValue();
	public: 
    	PrimeIterator(int limit); 
    	~PrimeIterator(); 
    	void next();
    	void prev();
    	int getIndex(); 
    	void operator++();
    	void operator++(int);
    	void operator--();
    	void operator--(int);
    	bool over();
    	int value();
    	int operator*();
    	
};


#endif //PRIMEITERATOR_H
