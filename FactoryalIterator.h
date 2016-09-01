#ifndef FACTORYALITERATOR_H
#define FACTORYALITERATOR_H 

#include <iostream>

class InvalidLimitException {};

class FactoryalIterator { 
	private: 
    	int length;
    	int last;
    	int currentIndex;
    	unsigned long long currentValue;
    	void calcValue();
   	public: 
    	FactoryalIterator(int length); 
    	~FactoryalIterator(); 
    	void next();
    	void prev();
    	int getIndex(); 
    	void operator++();
    	void operator++(int);
    	void operator--();
    	void operator--(int);
    	bool over();
    	unsigned long long value();
    	int operator*();
    	
};


#endif //FACTORYALITERATOR_H
