#include<iostream>
using namespace std;

template<typename T>
struct Node { // node for the linked list
    T data; // Data stored at the current node
    Node* next; // Pointer to the next node in the linked list
    Node(T val) : data(val), next(NULL) {} // Constructor for the struct, initializes data and sets next to NULL
};

template<typename T>
class Queue_using_Linked_list {
private:
    Node<T>* head;
    Node<T>* rear; // Pointer to the head of the queue using linked list
    int count = 0;
public:
    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            rear = head;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    void pop() {
        if (!head) {
            cout << "Runtime error: stack underflow";
        }
        else {
            if (head->next) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            else {
                head = NULL;
                rear = head;
            }
            count--;
        }
    }
    T front() {
        if (!head) {
            cout << "Runtime error: stack is empty";
            return -1;
        }
        else {
            return head->data;
        }
    }

    int size() {
        return count;
    }

    bool empty() {
        return head == rear;
    }
};

void test() {
    Queue_using_Linked_list<int> q;

    // Scenario 1: Testing an empty queue
    cout << "Scenario 1: Testing an empty queue" << endl;
    cout << q.front() << " (Expected: Runtime error -1)" << endl;
    cout << q.size() << " (Expected: 0)" << endl;
    cout << (q.empty() ? "Empty" : "Not Empty") << " (Expected: Empty)" << endl;

    // Scenario 2: Enqueuing elements
    cout << "\nScenario 2: Enqueuing elements" << endl;
    q.push(1);
    cout << "Front after enqueue(1): " << q.front() << " (Expected: 1)" << endl;
    cout << "Size after enqueue(1): " << q.size() << " (Expected: 1)" << endl;
    cout << "Empty after enqueue(1): " << (q.empty() ? "Empty" : "Not Empty") << " (Expected: Not Empty)" << endl;

    q.push(2);
    cout << "Front after enqueue(2): " << q.front() << " (Expected: 1)" << endl;
    cout << "Size after enqueue(2): " << q.size() << " (Expected: 2)" << endl;

    q.push(3);
    cout << "Front after enqueue(3): " << q.front() << " (Expected: 1)" << endl;
    cout << "Size after enqueue(3): " << q.size() << " (Expected: 3)" << endl;

    // Scenario 3: Dequeuing elements
    cout << "\nScenario 3: Dequeuing elements" << endl;
    q.pop();
    cout << "Front after dequeue: " << q.front() << " (Expected: 2)" << endl;
    cout << "Size after dequeue: " << q.size() << " (Expected: 2)" << endl;

    q.pop();
    cout << "Front after dequeue: " << q.front() << " (Expected: 3)" << endl;
    cout << "Size after dequeue: " << q.size() << " (Expected: 1)" << endl;

    q.pop();
    cout << "Front after dequeue: " << q.front() << " (Expected: Runtime error)" << endl;
    cout << "Size after dequeue: " << q.size() << " (Expected: 0)" << endl;
    cout << "Empty after dequeue: " << (q.empty() ? "Empty" : "Not Empty") << " (Expected: Empty)" << endl;
}
int main() {
    test(); // Run the test function
    return 0;
}
