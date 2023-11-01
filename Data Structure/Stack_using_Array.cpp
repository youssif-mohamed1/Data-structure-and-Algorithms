#include <iostream>
using namespace std;

//Maximum Default Size of Stack using array
const int MAX_SIZE=1000;

template<typename T>
class Stack {
private:
    int t = 0,
        count = 0,
        max_size;
public:

    T* arr;
    
    Stack() {  // default constructor 
        arr = new T[MAX_SIZE];
        max_size = MAX_SIZE;
    }

    Stack(int size) { // overloaded constructor for initializing the array
        arr = new T[size];
        max_size = size;
    }

    Stack(const Stack& other) {
        this->arr = new T[MAX_SIZE]; // Allocate a new array
        this->t = other.t;
        for (int i = 0; i < this->t; i++) { // copying each element
            this->arr[i] = other.arr[i];
        }
    }

    void operator= (const Stack& other) {
        if (this != &other) {  // Check for self-assignment
            delete[] this->arr;  // Deallocate the current array
            this->arr = new T[other.maxSize()];  // Allocate a new array
            this->t = other.t;
            for (int i = 0; i < this->t; i++) {
                this->arr[i] = other.arr[i]; // copying each element
            }
        }
    }

    T top() { // to get the top element of the stack
        if (!this->empty()) {
            return arr[t - 1];
        }
        else {
            throw runtime_error("Stack Under FLow");
        }
    }

    bool empty() { // to check whether the stack is empty or not
        return this->t == 0;
    }

    int size() { // to get the number of elements in the stack
        return this->count;
    }

    void push(T element) { // to push element in the stack
        if (this->t == MAX_SIZE) {
            throw runtime_error("Stack Over FLow");
        }
        else {
            arr[this->t] = element;
            count++;
            t++;
        }
    }

    void pop() { // to pop the top element of the stack
        if (!this->empty()) {
            --this->t;
        }
        else {
            throw runtime_error("Stack Under FLow");
            count--;
        }
    }

    void clear() { // to clear all the stack
        this->t = 0;
    }

    int maxSize() {
        return this->max_size;
    }

    ~Stack() {
        delete arr;
    }
};

void print(Stack<int>s) {
    while (!s.empty())
    {
        // print top element in stack 
        cout << s.top() << " ";
        // remove top element in stack 
        s.pop();
    }
}

int main()
{
    Stack<int>s(3);
    s.push(10);
    s.push(20);
    s.push(30);

    //print top element of stack after popping 
    cout << "Top element is : " << s.top() << endl;

    //print all elements in stack : 
    cout << "Elements present in stack : ";
    print(s);

    // clear the stack
    s.clear();

    cout << (s.empty() ? "\nStack is empty\n" : "\nStack is not empty\n");

    s.push(10);
    s.push(20);
    s.push(30);

    Stack<int>b(s); // coping using copy constructor
    cout << "stack Copied by using copy constructor: ";
    print(b);

    Stack<int>c=b;
    cout << "\nstack Copied by using Assignment Operator: ";
    print(c);

    return 0;
}
