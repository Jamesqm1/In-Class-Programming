#ifndef _Queue_h
#define _Queue_h

/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab 3 - Queues        

    author: 

    last modified: 9/7/2017
*/

#include <cstdlib>

class Queue {
public:
	// max elements in queue
	static const size_t ARRAY_SZ = 5;

	Queue() {
		_data[ARRAY_SZ]={};
		front_index=0;
		next_empty_index=0;
		total_elements=0;
	}

	bool enqueue(char c) {
		if(total_elements==ARRAY_SZ){
			return false;
		}
		_data[next_empty_index]=c;
		next_empty_index++;
		next_empty_index%=5;
		total_elements++;
		return true;
	}
	
	bool dequeue()  {
		if(is_empty()){
			return false;
		}
		front_index++;
		front_index%=5;
		total_elements--;
		return true;
	}
	
	char front()    {
		if(!is_empty()){
			return _data[front_index];
		}
		return '\0';
	}
	
	bool is_empty() {
		if(total_elements==0){
			return true;
		}
		return false;
	}

private:
	char _data[ARRAY_SZ];
	int front_index;
	int next_empty_index;
	int total_elements;
};

#endif
