#include "testQueue.h"

//Test cases:

//Tests to find the size of a nonempty queue, should return 2:
void test::sizeTestCase() {
    cout << "size() test case:" << endl << "Size should return 2." << endl;
    //Create queue of size 2:
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    //Display results
    cout << "Current size() is: " << q1.size() << endl;    
    if (2 == q1.size()) {
        cout << "Successfully got size(). Passed." << endl << endl;
    }
    else {
        cout << "Unsuccessfully got size(). Not passed." << endl << endl;
    }
}
//Tests to find if an empty queue is empty, should return true:
void test::isEmptyTestCase() {
    cout << "isEmpty() test case:" << endl << "Queue should return true for empty." << endl;
    //Create queue:
    queue q1;
    //Display results:
    cout << "Is queue empty? " << q1.isEmpty() << endl;
    if (q1.isEmpty() == true) {
        cout << "Successfully got isEmpty(). Passed." << endl << endl;
    }
    else {
        cout << "Unsuccessfully got isEmpty(). Not passed." << endl << endl;
    }
}
//Tests to find if a queue is full, should return true:
void test::isFullTestCase() {
    cout << "isFullTestCase() test case:" << endl << "Queue should return true for empty." << endl;
    //Create queue of size 10:
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.enqueue(10);
    //Display results:
    cout << "Is queue full? (1 for true, 0 for false) " << q1.isFull() << endl;    
    if (q1.isFull() == 1) {
        cout << "Successfully got isFullTestCase(). Passed." << endl << endl;
    }
    else {
        cout << "Unsuccessfully got isFullTestCase(). Not passed." << endl << endl;
    }
}
//The following have two test cases per function:

//Tests a queue without any items, should successfully dequeue:
void test::dequeueTest1() {
    cout << "dequeue() test case 1, dequeues an empty queue:" << endl << "Queue should show a message for being empty and size should be 0." << endl;
    //Create a queue
    queue q1;
    int size = q1.size();
    q1.dequeue();
    cout << "Size was " << size << ", size is now " << q1.size() << "." << endl;
    if (q1.size() == 0) {
        cout << "Successfully dequeued(). Passed." << endl << endl;
    }
    else {
        cout << "Unuccessfully dequeued(). Not passed." << endl << endl;
    }

}
//Tests a queue with an item, size should change from 1 to 0:
void test::dequeueTest2() {
    cout << "deequeue() test case 2, dequeues a nonempty queue:" << endl << "Queue should change from size 1 to 0." << endl;
    //Create a queue of size 2:
    queue q1;
    int size = q1.size();
    q1.enqueue(1);
    q1.dequeue();
    cout << "Size was " << size << ", size is now " << q1.size() << "." << endl;
    if (q1.size() == 0) {
        cout << "Successfully dequeued(). Passed." << endl << endl;
    }
    else {
        cout << "Unuccessfully dequeued(). Not passed." << endl << endl;
    }
}

//Tests adding multiple items to a queue:
void test::enqueueTest1() {
    cout << "enqueue() test case 1, tests adding an item to a nonempty queue:" << endl << "Queue should show the last queue added, 2, with peek() when dequeued once." << endl;
    //Create queue:
    queue q1;
    q1.enqueue(1);
    int first = q1.peek();
    q1.enqueue(2);
    q1.dequeue();
    cout << "First queue was " << first << ", last queue added is " << q1.peek() << endl;
    if (q1.peek() == 2) {
        cout << "Successfully enqueued(). Passed." << endl << endl;
    }
    else {
        cout << "Unuccessfully enqueued(). Not passed." << endl << endl;
    }

}
//Tests adding an item to an empty queue:
void test::enqueueTest2() {
    cout << "enqueue() test case 3, tests adding an item to a full (10 item) queue:" << endl << "Queue should display full queue message and size should remain 10." << endl;
    //Create queue:
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.enqueue(10);
    int size = q1.size();
    q1.enqueue(11);
    cout << "Size was " << size << ", size is now " << q1.size() << endl;
    if (q1.size() == size) {
        cout << "Does not insert another queue." << endl;
        cout << "Successfully enqueued(). Passed." << endl << endl;
    }
    else {
        cout << "Unuccessfully enqueued(). Not passed." << endl << endl;
    }
}
//Tests peeking an empty queue:
void test::peekTest1() {
    cout << "peek() test case 1, tests peeking an empty queue:" << endl << "peek() should return the numeric minimum limits number." << endl;
    //Create queue:
    queue q1;
    cout << "Peaked node is " << q1.peek() << endl;
    if (q1.peek() == -33686019) {
        cout << "Successfully got peek(). Passed." << endl << endl;
    }
    else {
        cout << "Unsuccessfully got peek(). Not Passed." << endl << endl;
    }
}
//Tests peeking a queue with items, true if 1:
void test::peekTest2() {
    cout << "peek() test case 2, tests peeking a nonempty queue:" << endl << "peek() should return the number 1." << endl;
    //Create queue:
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.peek();
    cout << "Peaked node is " << q1.peek() << endl;
    if (q1.peek() == 1) {
        cout << "Successfully got peek(). Passed." << endl << endl;
    }
    else {
        cout << "Unsuccessfully got peek(). Not Passed." << endl << endl;
    }
}