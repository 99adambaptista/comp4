/*
Copyright 2019 Adam Baptista


*/

#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
    try {
        if (capacity < 1)
            throw invalid_argument
                ("Capacity cannot be less than or equal to 1.");
    } catch(invalid_argument& e) {
        cerr << "RB constuctor: capacity cannot be less than or equal to 1.";
        cerr << endl;
        throw e;
    }
    //sets a certain amount of space for items, like vector = new int[capacity];
    vector.reserve(capacity);
    for (int i = 0; i < capacity; i++)
        vector.push_back(0);
    size = 0;
    first = 0;
    last = 0;
    this->capacity = capacity;
}

int RingBuffer::ringSize() {
    return size;
}

bool RingBuffer::isEmpty() {
    if (size > 0)
        return false;
    return true;
}

bool RingBuffer::isFull() {
    if (capacity > size)
        return false;
    return true;
}

void RingBuffer::enqueue(int16_t x) {
    try {
        if (isFull())
            throw runtime_error
                ("Enqueue: can't enqueue an full ring");
    } catch (runtime_error& e) {
        cerr << "Enqueue: can't enqueue an full ring";
        cerr << endl;
        throw e;
    }
    vector[last] = x;
    if (last == capacity - 1) {
        last = 0;
    } else {
        last++;
    }
    size++;
}

int16_t RingBuffer::dequeue() {
    try {
        if (isEmpty())
            throw runtime_error
                ("Dequeue: can't dequeue en empty buffer");
    } catch (runtime_error& e) {
        cerr << "Dequeue: can't dequeue en empty buffer";
        cerr << endl;
        throw e;
    }
    temp_first = peek();
    if (first == capacity - 1) {
        first = 0;
    } else {
        first++;
    }
    size--;
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
    return vector[first];
}

/*
void RingBuffer::print() {
    for (int i = 0; i < capacity; i++)
        cout << vector[i] << endl;
    cout << endl;
}
*/

void RingBuffer::empty() {
    size = 0;
    first = 0;
    last = 0;
}
