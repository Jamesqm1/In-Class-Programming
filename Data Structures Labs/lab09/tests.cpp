/*
    tests.cpp

    Tests for the Queue class. 

    Code for CSCI 262 lab 3 - Queues

    Author: C. Painter-Wakefield
*/

#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;

int NUM_PASSED = 0;

void test_true(bool expr, string desc);

/* 
   NOTE: Make sure your ARRAY_SZ constant in Queue.h is set such that your
   Queue has a capacity of exactly 5 elements.
*/

int main() {
    Queue<char> q, p;
    Queue<string> words, letters;
    Queue<int> one, two;
    
    
    
    
    
    
    
    
    cout << endl <<endl;
    
    cout << "-------------------------Queue<char>------------------------" << endl << endl;
    
    q.enqueue('q');
    q.dequeue();
    test_true(q.is_empty(),"Queue<char> q is empty");
    for(int i = 0; i< 4;i++){
        q.enqueue(i);
    }
    test_true(!q.is_empty(),"Queue<char> q can alocate new memory");
    p = Queue<char>(q);
    for(int i =0; i<4; i++){
        p.dequeue();
    }
    test_true(p.is_empty(),"Queue<char> p successfully copied from q");
    cout << endl <<endl;
    
    
    
    
    cout << "-------------------------Queue<string>----------------------"<<endl<<endl;
    
    
    words.enqueue("words");
    words.dequeue();
    test_true(words.is_empty(),"Queue<string> words is empty");
    for(int i = 0; i< 10;i++){
        string s = std::to_string(i);
        words.enqueue(s);
    }
    test_true(!words.is_empty(),"Queue<string> words can alocate new memory");
    letters = Queue<string>(words);
    for(int i =0; i<10; i++){
        letters.dequeue();
    }
    test_true(letters.is_empty(),"Queue<string> letters successfully copied from words");
    
    cout << endl <<endl;
    
    
    
    
    cout << "-------------------------Queue<int>-------------------------"<<endl<<endl;
    
    
    
    one.enqueue(1);
    one.dequeue();
    test_true(one.is_empty(),"Queue<int> one is empty");
    for(int i = 0; i< 120;i++){
        one.enqueue(i);
    }
    test_true(!one.is_empty(),"Queue<int> one can alocate new memory");
    two = Queue<int>(one);
    for(int i =0; i<120; i++){
        two.dequeue();
    }
    test_true(two.is_empty(),"Queue<int> two successfully copied from one");
    
    cout << endl <<endl<< endl <<endl;
    
    
    return 0;
}

void test_true(bool expr, string desc) {
    if (!expr) {
        cerr << "FAILED test: ";
    } else {
        cerr << "Passed test: ";
        NUM_PASSED++;
    }
    cerr << '"' << desc << '"' << endl;
}

