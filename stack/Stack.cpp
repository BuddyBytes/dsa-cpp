#include <iostream>
#include <array>
using namespace std;

template<size_t StackMaxSize>
class Stack {
    private:
    int top;
    array<int , StackMaxSize> stackArray;


    public:
    Stack() : top(-1) {
        stackArray.fill(0);
    }

    // check if stack is empty
    bool isEmpty(){
        const int initailValueOfStack = -1 ;
        return top == initailValueOfStack;
    }
    
};


int main() {
    return 0;
}