#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H 

#include <iostream>

class InvalidSizeException {};

template <typename Type>
class ArrayIterator { 
	private: 
    	int size;
    	int last;
    	int currentIndex;
    	Type currentValue;
    	const Type* array;
    	
    	void calcValue() {
		    this->currentValue = array[currentIndex];
		} 
   	public: 
    	ArrayIterator(const Type* arrayIn, int size ): size(size), currentIndex(0) {
    		if ( size < 0 ) {
    			throw InvalidSizeException();
	    	}
    		this->array = arrayIn;
    		this->currentValue = array[currentIndex];
    		this->last = this->size - 1;
    	} 
    	
    	~ArrayIterator() {
 			this->size = 0;
			this->currentIndex = 0;
			this->currentValue = 0;
		    this->last = 0;
		    this->array = NULL;
		} 
    	
    	void next(){ 
 		   if ( over() ) { 
    			return; 
		    } 
		    this->currentIndex += 1;
		    this->calcValue();
		}
    	
    	void prev() { 
		    if ( over() ) { 
	    	return; 
		    } 
		    this->currentIndex -= 1;
		    this->calcValue();
     
		}

    	const int getIndex(){ 
		    return this->currentIndex; 
		} 
    	
    	void operator++(){ 
		    next(); 
		}
    	
    	void operator++(int){ 
		    operator++(); 
		}
    	
    	void operator--(){ 
		    prev(); 
		}
    	
    	void operator--(int){ 
		    operator--(); 
		}
    	
    	bool over(){ 
			if ( currentIndex < 0 ) {
	    		this->currentIndex = 0;
			    this->currentValue = array[currentIndex];
				return true;
			}
			if ( currentIndex > last ) {
				this->currentIndex = this->last;
				this->calcValue();
				return true;
			}
			return false; 
		}
    	
    	const Type value() {
		    return this->currentValue;
		}
    	
    	const Type operator*(){ 
		    return value(); 
		}
    	
};


#endif //ARRAYITERATOR_H
