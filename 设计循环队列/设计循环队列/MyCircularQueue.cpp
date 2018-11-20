//
//  MyCircularQueue.cpp
//  设计循环队列
//
//  Created by ifuwo on 2018/11/20.
//  Copyright © 2018 ifuwo. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    // store elements
    vector<int> data;
    // size of the queue
    int data_size;
    // a pointer to indicate the head position
    int p_head;
    // a pointer to indicate the tail position
    int p_tail;
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data_size = k;
        data = vector<int>(k);
        p_head = p_tail = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (p_tail == -1) {
            p_head = p_tail = p_tail + 1;
            data[p_tail] = value;
            return true;
        }
        if (p_tail + 1 == p_head) {
            return false;
        }
        if (p_tail + 1 >= data_size) {
            if (p_head == 0) {
                return false;
            }
            p_tail = 0;
            data[p_tail] = value;
            return true;
        }
        p_tail++;
        data[p_tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (p_head == -1) {
            return false;
        }
        if (p_head == p_tail) {
            p_head = p_tail = -1;
            return true;
        }
        p_head++;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[p_head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[p_tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (p_head == -1) {
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (p_tail + 1 >= data_size) {
            if (p_head == 0) {
                return true;
            }
        }
        if (p_tail + 1 == p_head) {
            return true;
        }
        return false;
    }
};
