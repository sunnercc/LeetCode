//
//  main.cpp
//  设计循环队列
//
//  Created by ifuwo on 2018/11/20.
//  Copyright © 2018 ifuwo. All rights reserved.
//

#include "MyCircularQueue.cpp"

int main() {
    MyCircularQueue circularQueue(3); // 设置长度为3
    
    bool res;
    int num;
    
    res = circularQueue.enQueue(1);  // 返回true
    printf("%d\n", res);
    
    res = circularQueue.enQueue(2);  // 返回true
    printf("%d\n", res);
    
    res = circularQueue.enQueue(3);  // 返回true
    printf("%d\n", res);
    
    res = circularQueue.enQueue(4);  // 返回false,队列已满
    printf("%d\n", res);
    
    num = circularQueue.Rear();  // 返回3
    printf("%d\n", num);
    
    res = circularQueue.isFull();  // 返回true
    printf("%d\n", res);
    
    res = circularQueue.deQueue();  // 返回true
    printf("%d\n", res);
    
    res = circularQueue.enQueue(4);  // 返回true
    printf("%d\n", res);
    
    num = circularQueue.Rear();  // 返回4
    printf("%d\n", num);
    
    return 0;
}

