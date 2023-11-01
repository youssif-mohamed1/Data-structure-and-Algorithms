#include<iostream>

using namespace std;

// the default max size of the queue
const int MAX_SIZE = 1000;

template<typename T>
class Circular_queue {
private:
    int f = 0,
        b = 0,
        count = 0,
        max_size;
public:
    T* arr;

    Circular_queue() {  // default constructor 
        arr = new T[MAX_SIZE];
        max_size = MAX_SIZE;
    }

    Circular_queue(int size) { // overloaded constructor for initializing the array
        arr = new T[size];
        max_size = size;
    }

    Circular_queue(const Circular_queue& other) : max_size(other.max_size), f(other.f), b(other.b), count(other.count) { // copy Constructor
        arr = new T[max_size]; // Allocate a new array with the same size
        for (int i = 0; i < count; i++) {
            this->arr[i] = other.arr[(f + i) % max_size]; // Copy elements with proper circular indexing
        }
    }

    void operator= (const Circular_queue& other) { //Assignment Operator
        if (this != &other) {  // Check for self-assignment
            delete[] this->arr;  // Deallocate the current array
            this->f = other.f;
            this->b = other.b;
            this->count = other.count;
            this->max_size = other.max_size;
            arr = new T[max_size];
            for (int i = 0; i < count; i++) {
                this->arr[i] = other.arr[(f + i) % max_size]; // Copy elements with proper circular indexing
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
        return count==0;
    }

    int size() { // to get the number of elements in the queue
        return this->count;
    }

    void push(T element) { // to push element in the queue
        if (count == max_size) {
            throw runtime_error("Stack Over FLow");
        }
        else {
            arr[this->b % max_size] = element;
            count++;
            b++;
        }
    }

    void pop() { // to pop the top element of the queue
        if (!this->empty()) {
            ++this->f;
            f %= max_size;
            count--;
        }
        else {
            throw runtime_error("Stack Under FLow");
        }
    }

    void clear() { // to clear all the queue
        this->f = this->b = 0;
        count = 0;
    }

    int maxSize() {
        return this->max_size;
    }

    ~Circular_queue() {
        delete arr;
    }
};

void print(Circular_queue<int>q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

void test() {  // testing for the Circular Queue
    
    // Test case 1: Basic operations
    Circular_queue<int> q1(3);
    q1.push(5);
    cout << q1.front() << endl;
    q1.push(10);
    q1.push(20);
    cout << "The size is: " << q1.size() << endl;;
    q1.pop();
    cout << "Front after Pop: " << q1.front() << endl;
    q1.clear();
    cout << (q1.empty() ? "Empty\n" : "NOT Empty\n");
    cout << "Size after Clearing: " << q1.size() << endl;

    // Test case 2: Circular behavior
    Circular_queue<int> q2(3);
    q2.push(5);
    q2.push(10);
    q2.push(20);
    cout << "elements in the queue: ";
    print(q2);
    q2.pop();
    q2.push(30);
    cout << "\nelements in the queue: ";
    print(q2);
    cout << "\nSize is: " << q2.size() << endl;
    cout << "Front: " << q2.front() << endl;
    q2.pop();
    q2.pop();
    cout << "Front after 2 pops: " << q2.front() << endl;

    // Test case 3: Copy constructor and assignment operator
    Circular_queue<int> q3(q2);  // Copy constructor
    q3.size();
    cout<<"Front element of the copied queue using copy constructor: "<<q3.front();

    Circular_queue<int> q4;
    q4 = q2;  // Assignment operator
    cout<<"\nSize of the copied queue using assignment operator: "<<q4.size();
    cout << "\nFront element of the copied queue using assignment operator: " << q4.front();

    // Test case 4: Overflow and underflow
    Circular_queue<int> q5(2);
    q5.push(5);
    q5.push(10);
    //q5.push(20);  // Should throw "Queue Overflow"
    q5.pop();
    q5.pop();
    //q5.pop();  // Should throw "Queue Underflow"
    return;
}


int main() {
    test();
    return 0;
}
