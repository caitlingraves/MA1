// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn
#include "queue.h"
#include "testQueue.h"

//ATTRIBUTES: There were several poor designs in the code. 
// One of them was writing the code for all the queue function bodies in the header file. A good design would use a seperate .cpp file to write the function bodies in so that the functions can be declared correctly in the header.
// Another poor design decision wasnot including enough comments to describe questionable decisions. For example, count + 1 is returned originally by size and there were no comments describing why we may need to add 1 for returning. This may have also resulted in a logic error. Logic errors can be avoided with better commenting to make sure that the user understands they are getting the correct output. Also it would be useful to know why return numeric_limits<int>::min() is being returned in peek() with a comment.
// There were poor design decisions with the code in the data type selection. You cannot have more than ten items in the array used. Meanwhile, if you tried to use nodes while building the queue there would be unlimited number of items you can put into the queue. Not having enough room in the queue for a certain amount of items will cause those items to be lost as they will not fit in the queue. In this way, using nodes with the queue would be a far better design structure.
// Some parts of the program were missing needed checks such as with enqueue not checking if the rear and front were at the same queue. Not having these checks is bad design because it can mess up where the rear is when dequeue and enqueue are called sufficient times. We need these checks in our code so that we will not get errors in results and cause the whole queue to have wrong values.
// The dequeue and enqueue functions are not very testable as they do not return a value showing if the item was successfully dequeued or not. Bad testability is another design value that is present in this code. A bool returned value would really help the code to see if the item was able to be put onto the code as the queue already has a set size with it being an array.

// main function
int main()
{
    //The main issue with the functions in queue was that size() was incorrectly returning. Most of the functions were reliant on queue and this would cause issues in the other functions. By changing size(), peek(), and isFull() I was able to fix the queue code. In size() I had to change it to return count and not count + 1. Having a value of 1 shows that there is something in the queue when an empty queue should return 0. In isFull() it should return (size() == capacity) and not return (size() - 1 == capacity). If ten items have been added to the queue the size should be 10 and not 9 after we fix size(). peek() should be fixed so that it returns the front of the queue and not the rear according to the instructions. It should return arr[front] and not return arr[rear] to get the correct queue. ......
    test t1;
    // call your test functions here!
    t1.sizeTestCase();
    t1.isEmptyTestCase();
    t1.isFullTestCase();
    //The following have two test cases per function
    t1.dequeueTest1();
    t1.dequeueTest2();
    t1.enqueueTest1();
    t1.enqueueTest2();
    t1.peekTest1();
    t1.peekTest2();
    return 0;
};