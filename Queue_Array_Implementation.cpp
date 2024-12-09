#include <iostream>
using namespace std;

const int DefaultListSize = 10;
int queue_size = 0;
int top = -1;
int queue[DefaultListSize];
int front = -1;
int rear = -1;
enqueue(int value)
{
    rear += 1 if (queue_size < DefaultListSize - 1)
    {
        queue[rear] = value;
        if (font == -1)
            font += 1
        queue_size+=1;
    }
    else
    {
        cout << "ALERT!!!! Queue is Full!!!!\n";
    }
}
int dequeue(){
    if (queue_size == 0){
        cout << "ALERT!!!! Queue is Empty!!!!\n";
        return;
    }
    return queue[front++];
}