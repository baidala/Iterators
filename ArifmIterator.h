#ifndef ARIFMITERATOR_H
#define ARIFMITERATOR_H 

#include <iostream>

class InvalidLimitException {};

class ArifmIterator { 
	private: 
    	int length;
    	int step; 
    	int first;
    	int currentIndex;
    	int currentValue;
    	void calcValue();
   	public: 
    	ArifmIterator(int first, int step, int length); 
    	~ArifmIterator(); 
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


#endif //ARIFMITERATOR_H
