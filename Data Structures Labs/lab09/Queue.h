#ifndef _Queue_h
#define _Queue_h

/*
    Queue.h
        
    class definition for the Queue class.

    assignment: CSCI 262 Lab 9 - queue2        

    author: 

    last modified: 3/15/2018
*/
template <class T>
class Queue {
public:
	// max elements in queue
	static const size_t ARRAY_SZ = 5;
    // constructor
	Queue() { _front = 0; _back = 0; _size = 0; _data = new T[ARRAY_SZ]; _capacity=ARRAY_SZ;}
	Queue(const Queue<T>& c){
		_front = c._front;
		_back  = c._back;
		_size  = c._size;
		_capacity = c._size;
		_data  = new T[c._size];
		for(int i = 0;i<c._size;i++){
			_data[i]=c._data[i];
		}
	}
	// enqueue: add a T to the end of the queue if room and return true;
    // if not enough room, return false
	void enqueue(T c) {
		if(_back>=_capacity){
			allocate_new_array();
		}
		_data[_back]=c;
		_back++;
		_size++;
		
	}
		
    // dequeue: if queue is not empty, remove the front element from the queue;
    // if queue is empty, return false and do nothing.
	bool dequeue()  { 
		if (is_empty()) { return false; }
		_front++;
        _size--;
		return true;
	}

    // front: return the front element in the queue
	T front()    { return _data[_front]; }

    // is_empty: return whether or not the queue is empty
	bool is_empty() { return _size == 0; }

private:
	T* _data;
    int  _size;
    int _capacity;
	int  _front;
	int  _back;
	int length(T* a){
		if(sizeof(a)==0){
			return 0;
		}
		return (sizeof(a)/sizeof(a[0]));
	}
	void allocate_new_array(){
		_capacity*=2;
		T* a = new T[_capacity];
		for(int i =_front; i<length(_data);i++){
			a[i] = _data[i];
		}
		delete[] _data;
		_data = a;
		
	
	}
	
};

#endif
