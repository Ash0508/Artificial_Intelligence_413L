#include <iostream>
#define MAX 1000

class MyStack {
    int top;

public:
    int a[MAX];

    MyStack() {
        top = -1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool MyStack::push(int x) {
    if (top >= (MAX - 1)) {
        std::cout << "Stack Overflow" << std::endl;
        return false;
    } else {
        a[++top] = x;
        std::cout << x << " Pushed into Stack" << std::endl;
        return true;
    }
}

int MyStack::pop() {
    if (top < 0) {
        std::cout << "Stack underflow" << std::endl;
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

int MyStack::peek() {
    if (top < 0) {
        std::cout << "Stack underflow" << std::endl;
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool MyStack::isEmpty() {
    return (top < 0);
}

int main() {
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(30);
    s.push(40);
    s.push(30);
    std::cout << s.pop() << " Popped Element" << std::endl;
    std::cout << s.peek() << std::endl;
    return 0;
}




#include<iostream>
using namespace std;
#define MAX 1000
class Queue
{
   int front,rear;
   int a[MAX];
   public:
    Queue()
    {
        front=rear=-1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }
    void enqueue(int x)
    {
        if(isFull())
        {
            std::cout<<" Queue is Already full "<<std::endl;
            return ;
        }
        if(isEmpty())
        {
            front=rear=0;
        }
        else{
            rear=(rear+1)%MAX;
        }
        a[rear]=x;
        std::cout<<" Added in the Queue "<<std::endl;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            std::cout<<" Queue is Empty "<<std::endl;
            return;
        }
        std::cout<<" Dequeued Element is "<<a[front]<<std::endl;
        if(front==rear)
        {
            front=rear=-1;
        }
        else{
            front=(front+1)%MAX;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            std::cout<<" Queue is Empty Cannot be peek "<<std::endl;
            return -1;
        }
        return a[front];
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    // q.enqueue(40);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;

}
