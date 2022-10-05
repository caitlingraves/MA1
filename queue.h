#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;
// define default capacity of the queue
#define SIZE 10
// Class for queue

class queue
{
    //FIX: add private to make sure that the variables are not seen outside of queue
private:
    int* arr;// array to store queue elements
    int capacity; // maximum capacity of the queue
    int front;// front points to front element in the queue (if any)
    int rear;// rear points to last element in the queue
    int count;// currePnt size of the queue
public:
    //queue(int size = SIZE);  // constructor
    //~queue();    // destructor
    //void dequeue();
    //void enqueue(int x);
    //int peek();
    //int size();
    //bool isEmpty();
    //bool isFull();
    //FIX: need a ; after }
    //};
    // Constructor to initialize queue
    queue(int size = SIZE)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    // Destructor to free memory allocated to the queue
    ~queue()
    {
        delete arr; // you are not required to test this function;
        // however, are there issues with it?
        //Needs: 
        //delete[] arr;
    }
    // Utility function to remove front element from the queue
    void dequeue()
    {
        // check for queue underflow
        if (isEmpty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            return;
        }
        //FIX had cout < "", changed to cout << ""
        cout << "Removing " << arr[front] << '\n';
        //FIX: should make sure the item is destroyed:
        arr[front] = 0;
        //FIX: Make sure front is not being changed if there is no next node:
        if (front != rear) {
            front = (front + 1) % capacity;
        }
        //FIX: Make sure that rear is put in correct location when the array is dequeued and then enqueued:
        else {
            rear = -1;
        }
        count--;
    }
    // Utility function to add an item to the queue
    void enqueue(int item)
    {
        // check for queue overflow
        //FIX: it was isFul(), fixed to isFull()
        if (isFull())
        {
            cout << "OverFlow\nProgram Terminated\n";
            return;
        }
        cout << "Inserting " << item << '\n';
        rear = (rear + 1) % capacity;
        //FIX: Item is not inserted correctly, should insert item and not size:
        //arr[rear] = size();
        arr[rear] = item;
        count++;
    }
    // Utility function to return front element in the queue
    int peek()
    {
        if (isEmpty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            //FIX: Causes a build error with linux:
            return -33686019;// numeric_limits<int>::min();
        }
        //It is supposed to show front element, instead it shows the rear:
        //return arr[rear];
        return arr[front];
    }
    //While debugging I found an issue with size() which made isEmpty() also not work
    // Utility function to return the size of the queue
    int size()
    {
        //Should not add 1, should just return count:
        //return count + 1;
        return count;
    }
    // Utility function to check if the queue is empty or not
    bool isEmpty()
    {
        return (size() == 0);
    }
    // Utility function to check if the queue is full or not
    bool isFull()
    {
        //size() needs to be fixed and it should not subtract 1:
        //FIX: has to be ==, not just =
        //return (size() - 1 == capacity);
        return (size() == capacity);
    }
};
#endif