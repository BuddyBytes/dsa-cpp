#include <iostream>
#include <array>
using namespace std;

template <size_t StackMaxSize>

class Queue {
    private:
    int stackRear;
    int stackFront;
    array<int , StackMaxSize> stackArray;


    public:
    Queue(){
        stackRear = -1 ;
        stackFront = -1 ;
        stackArray.fill(0);
    }


    // check if the stack is empty for avoiding underflow error
    bool isEmpty(){
        // we need to check if the read-end equal front-end
        return stackRear == stackFront == -1 ;
    }

    // check if the stack is full for avoiding overflow error
    bool isfull(){
        // we need to check if the rear-end equal the size of stack
        return stackRear == StackMaxSize - 1;

        // for circular queue
        /*
         * we need to calculate the rear by this formula = (rear+1) % queue size
         * compare this with front-end
         * Demo Code :
                return ( (rear+1) % (queue size) == front );
         * */
    }

    // implements adding to stack function is called as : Enqueue
    void enqueue(int value){
         /*
            for adding a value into stack we need to check in 3 steps

            check if the stack is full for avoiding overflow
            check if the stack is empty : we need to move the front-end and rear-end to the next index and store the value
            else :
            just increament the index value of rear-end and store the value
          */

         if (isfull()){
             throw runtime_error("stack overflow");
         }
         else if(isEmpty()){
             stackRear = stackFront = 0 ;
         }
         else {
             stackRear++;

             // for circular Queue
             /*
              * calculate (rear+1) % queue size
              * Demo Code
                    stackRear = (rear + 1 ) % queue size
              * */
         }
         stackArray[stackRear] = value;
    }


    // impelemnts remove from queue function
    void dequeue(){ // remove elements from queue
        /*
            for  removing element from queue we need 3 conditions

            check if queue is not empty for avoiding stack underflow
            check if rear-end and front-end had the same value and making them both -1
            else
            increament the front-end value and make the previus value hold null or 0
         */

        if(isEmpty()){
            throw runtime_error("stack underflow");
        }
        else if(stackFront == stackRear){
            stackRear = stackFront = -1 ;
        }
        else {
            stackArray[stackFront] = 0 ;
            // for circular Queue
            /*
             * calculate (front+1) % queue size
             * Demo Code
                   stackFront = (front + 1 ) % queue size
             * */
        }
    }

    int countQueueElement(){
        return ((stackRear - stackFront) + 1 );
    }
    void displayQueueElements(){
        for (int i = static_cast<int>(StackMaxSize) - 1; i >=0 ; i--) {
            cout << to_string(stackArray[i]) << endl ;
        }
    }
};

int main(){
    Queue<3> queue;
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(3);
    queue.displayQueueElements();
    cout << to_string(queue.countQueueElement()) << endl ;
    return 0;
}