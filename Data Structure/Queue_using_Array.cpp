#include<iostream>

using namespace std;

// the default max size of the queue
const int MAX_SIZE = 1000;

template<typename T>
class Queue {
private:
    int f = 0,
        b = 0,
        count = 0,
        max_size;
public:
    T* arr;
    Queue() {  // default constructor 
        arr = new T[MAX_SIZE];
        max_size = MAX_SIZE;
    }

    Queue(int size) { // overloaded constructor for initializing the array
        arr = new T[size];
        max_size = size;
    }

    Queue(const Queue& other) : max_size(other.max_size), f(other.f), b(other.b), count(other.count) { // copy constructor
        arr = new T[max_size]; // Allocate a new array with the same size
        for (int i = 0; f + i <= b; i++) {
            this->arr[i] = other.arr[f + i]; // Copy elements
        }
    }

    void operator= (const Queue& other) { // Assignment Operator
        if (this != &other) {  // Check for self-assignment
            delete[] this->arr;  // Deallocate the current array
            this->f = other.f;
            this->b = other.b;
			this->count=other.count;
            this->max_size = b.maxSize();
            for (int i = this->f; i < this->b; i++) { // copying each element
                this->arr[i] = other.arr[i];
            }
        }
    }

    T front() { // to get the top element of the queue
        if (!this->empty()) {
            return arr[this->f];
        }
        else {
            throw runtime_error("Stack Under FLow");
        }
    }

    bool empty() { // to check whether the queue is empty or not
        return this->f == this->b;
    }

    int size() { // to get the number of elements in the queue
        return this->count;
    }

    void push(T element) { // to push element in the queue
        if (this->b == MAX_SIZE) {
            throw runtime_error("Stack Over FLow");
        }
        else {
            arr[this->b] = element;
            count++;
            b++;
        }
    }

    void pop() { // to pop the top element of the queue
        if (!this->empty()) {
            ++this->f;
            count--;
        }
        else {
            throw runtime_error("Stack Under FLow");
        }
    }

    void clear() { // to clear all the queue
        this->f = this->b = 0;
    }

    int maxSize() {
        return this->max_size;
    }

    ~Queue() {
        if (arr != NULL) {
            delete arr;
        }
    }
};

void print(Queue<int>&q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
int main() {
    Queue<int>q1(5);
    q1.push(5);
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.pop();
    //print first element of queue after popping 
    cout << "Top element is : " << q1.front() << endl;

    //print all elements in Queue : 
    cout << "Elements present in stack : ";
    print(q1);

    // clear the Queue
    q1.clear();

    cout << (q1.empty() ? "\nStack is empty\n" : "\nStack is not empty\n");
    Queue<int>q(3);
    q.push(10);
    q.push(20);
    q.push(30);

    Queue<int>q2(q); // coping using copy constructor
    cout << "stack Copied by using copy constructor: ";
    print(q2);

    Queue<int>c = q;
    cout << "\nstack Copied by using Assignment Operator: ";
    print(c);

    return 0;
}