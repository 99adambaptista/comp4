/*
Copyright 2019 Adam Baptista


*/

#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
    try {
        if (capacity <= 1)
            throw invalid_argument
                ("Capacity cannot be less than or equal to 1.");
    } catch(invalid_argument& e) {
        cerr << "RB constuctor: capacity cannot be less than or equal to 1.";
        cerr << endl;
        throw e;
    }
    this->capacity = capacity;
    vector = new int[capacity];
    for (int i = 0; i < capacity; i++)
        vector[i] = -1;
}

int RingBuffer::size() {
    return sizeof(vector);
}

bool RingBuffer::isEmpty() {
    // check if any of the elements are not equal to 0
    for (int i = 0; i < capacity; i++)
        if (vector[i] == 0)
            return false;
    return true;
}

bool RingBuffer::isFull() {
    // check if any of the elements are equal to 0
    for (int i = 0; i < capacity; i++)
        if (vector[i] != 0)
            return false;
    return true;
}

void RingBuffer::enqueue(int16_t x) {
    try {
        if (isFull())
            throw runtime_error
                ("Dequeue: can't enqueue an empty ring");
    } catch (runtime_error& e) {
        cerr << "Dequeue: can't enqueue an empty ring";
        cerr << endl;
        throw e;
    }
    int i = 0;
    while (i < capacity) {
        if (vector[i] == -1) {
            vector[i] = x;
            return;
        } else {
            i++;
        }
    }
}

int16_t RingBuffer::dequeue() {
    try {
        if (isEmpty())
            throw runtime_error
                ("Enqueue: can't enqueue to a full ring");
    } catch (runtime_error& e) {
        cerr << "Enqueue: can't enqueue to a full ring";
        cerr << endl;
        throw e;
    }
    temp_first = vector[0];
    // shift all elements up one in the queue
    for (int i = 1; i < capacity; i++)
        vector[i-1] = vector[i];
    // set the last element as -1
    vector[capacity-1] = -1;
    return temp_first;
}

int16_t RingBuffer::peek() {
    try {
        if (isEmpty())
            throw runtime_error
                ("Peek: can't peek at an empty ring");
    } catch (runtime_error& e) {
        cerr << "Peek: can't peek at an empty ring";
        cerr << endl;
        throw e;
    }
    return vector[0];
}

void RingBuffer::print() {
    for (int i = 0; i < capacity; i++)
        cout << vector[i] << endl;
    cout << endl;
}
