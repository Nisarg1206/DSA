#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
    Queue()
    {
        front = rear = -1;
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};
void Queue::enqueue(int x){
    if(size==rear-1)
    {
        cout << "Queue is full" << endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue()
{
    int x = -1;
    if(rear==front)
        cout << "Queue is empty" << endl;
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}
void Queue::display()
{
    for (int i = front + 1; i <=rear;i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(80);
    q.enqueue(40);
    q.enqueue(65);

    q.display();

    q.dequeue();
    q.display();
}