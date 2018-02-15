#ifndef STACK_H
#define STACK_H


class Stack
{
public:
    friend class StackIter;
    Stack();
    void push(int in);
    int pop();
    bool isEmpty();

private:
    int items[10];
    int sp;
};




#endif // STACK_H
