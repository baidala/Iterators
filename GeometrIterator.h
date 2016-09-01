#ifndef GEOMETRITERATOR_H
#define GEOMETRITERATOR_H 

#include <iostream>
#include <cmath>

class InvalidArgException {};

class GeometrIterator { 
	private: 
    	int length;
    	int step; 
    	unsigned long long first;
    	int currentIndex;
    	unsigned long long currentValue;
    	void calcValue();
   	public: 
    	GeometrIterator(int first, int step, int length); 
    	~GeometrIterator(); 
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


#endif //GEOMETRITERATOR_H
