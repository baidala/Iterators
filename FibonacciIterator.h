#ifndef FIBONACCIITERATOR_H
#define FIBONACCIITERATOR_H 

#include <iostream>

class InvalidLimitException {};

class FibonacciIterator { 
	private: 
    	int length;
    	int last;
    	long prevValue;
    	int currentIndex;
    	long currentValue;
    	void calcNextValue();
    	void calcPrevValue();
   	public: 
    	FibonacciIterator(int length); 
    	~FibonacciIterator(); 
    	void next();
    	void prev();
    	int getIndex(); 
    	void operator++();
    	void operator++(int);
    	void operator--();
    	void operator--(int);
    	bool over();
    	long value();
    	int operator*();
    	
};


#endif //FIBONACCIITERATOR_H
