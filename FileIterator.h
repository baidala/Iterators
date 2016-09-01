#ifndef FILEITERATOR_H
#define FILEITERATOR_H

#include <iostream>
#include <fstream>

#define MINSIZE 1

class IOFileException {}; 
class OutOfMemoryException {};     

template <class Type>
class FileIterator {
private:
    int size;
    int last;
    int currentIndex;
    Type currentValue;
    Type* buff;
    std::ifstream file;
    
    	
public:
    FileIterator( const char *in ) {
        this->size = MINSIZE;
        
        this->buff = (Type*)malloc(this->size*sizeof(Type));

        if ( !buff ) {    	
            throw OutOfMemoryException();     
        } 
        
        this->file.open(in);
        
        if (file.good()) {
        	this->file >> buff[0];
            this->currentIndex = 0;
        } else {
            throw IOFileException();
        }
    }
    ~FileIterator(){
        this->file.close();
        this->currentValue = 0;
        this->currentIndex = 0;
        this->last = 0;
        this->size = 0;
        free(this->buff); 
    }

    void next(){
        Type* newBuff;
        int newSize = size + 1;
        
        if ( over() ) {
		    return;
		}
        this->currentIndex += 1;
        
        if ( currentIndex == size ) {
            if ( !file.good()) {
		    	this->currentIndex = this->last;
		    	return;
			}
            newBuff = (Type*)realloc(this->buff, newSize*sizeof(Type));         
            
            if ( !newBuff ) {    	
                throw OutOfMemoryException();     
            }
            this->buff = newBuff;
            
            this->file >> buff[currentIndex];
        
        	if ( file.rdstate() == std::ios_base::goodbit ){
            	this->size = newSize; 
	        }
        }
        
    }
    void prev() {
        if ( currentIndex < 0 ) {
	    	this->currentIndex = 0;
	    	return;
		}
		this->currentIndex -= 1; 

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
        this->last = this->size - 1;
        
        if ( currentIndex < 0 ) {
	    	this->currentIndex = 0;
	    	return true;
		}
		if ( currentIndex > last ) {
		    this->currentIndex = this->last;
		    return true;
		}
		
        return false; 
    }
    
    const int getIndex() {
        return this->currentIndex;
    }
    
    const Type value() {
	    return this->buff[currentIndex];
	}
    	
   	const Type operator*(){ 
	    return value(); 
	}



};



#endif //FILEITERATOR_H
