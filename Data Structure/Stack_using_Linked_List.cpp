#include<iostream>
using namespace std;

template<typename T>
struct Node { // node for the linked list
    T data; // Data stored at the current node
    Node* next; // Pointer to the next node in the linked list
    Node(T val) : data(val), next(NULL) {} // Constructor for the struct, initializes data and sets next to NULL
};

template<typename T>
class Stack_using_Linked_list {
private:
    Node<T>* head; // Pointer to the head of the stack using linked list
    int count = 0; 
public:
    void push(T val) {
        Node<T>* newNode = new Node<T>(val); // Create a new node with the given value
        newNode->next = head; // Make the new node point to the current head
        head = newNode; // Update the head to be the new node
        count++; 
    }

    void pop() {
        if (!head) {
            cout << "RunTime error: stack underflow"; // Display an error message if the stack is empty
        }
        else {
            Node<T>* temp = head; // Create a temporary pointer to the current head
            if (head->next) {
                head = head->next; // Update the head to point to the next node
            }
            else {
                head = NULL; // Set the head to NULL to indicate an empty stack
            }
            delete temp; // Delete the old head node to free memory
            count--; 
        }
    }

    int size() {
        return count; 
    }

    bool empty() {
        return head == NULL; // Return true if the stack is empty (head is NULL), otherwise false
    }

    T top() {
        if (!head) {
            cout << "RunTime error: stack underflow"; // Display an error message if the stack is empty
        }
        else {
            return head->data; // Return the data at the current head (top of the stack)
        }
    }

    void clear() {
        while (!empty()) {
            pop(); // Pop elements until the stack is empty
        }
    }

    ~Stack_using_Linked_list() {
        clear(); // Destructor that clears the stack to free memory when the object is destroyed
    }
};

void print(Stack_using_Linked_list<int> st) {
    while (!st.empty()) {
        cout << st.top() << " "; // Print the top element of the stack and pop it
        st.pop();
    }
}

void test() {
    Stack_using_Linked_list<int> st; // Create a stack of integers
    cout << (st.empty() ? "Empty\n" : "Not Empty\n"); // Check if the stack is empty and print the result
    cout << "Stack size: " << st.size() << std::endl; // Print the size of the stack

    // Push some elements and check the size
    st.push(1);
    st.push(2);
    st.push(3);
    cout << (st.empty() ? "Empty\n" : "Not Empty\n");
    cout << "Stack size after pushing elements: " << st.size() << std::endl;

    //print(st);
    cout << endl;
    // Pop elements and check size
    st.pop();
    std::cout << "Popped one element. Stack size: " << st.size() << std::endl;
    st.pop();
    std::cout << "Popped one element. Stack size: " << st.size() << std::endl;
    //print(st);
    cout << endl;
    st.pop();
    std::cout << "Popped one element. Stack size: " << st.size() << std::endl;
    cout << (st.empty() ? "Empty\n" : "Not Empty\n");

    // Test stack underflow
    st.pop();
    //print(st);
    cout << endl;
    // Push and pop elements again
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    std::cout << "Stack size after pushing elements: " << st.size() << std::endl;
    std::cout << "Top element: " << st.top() << std::endl;

    st.pop();
    st.pop();
    std::cout << "Popped two elements. Stack size: " << st.size() << std::endl;
    std::cout << "New top element: " << st.top() << std::endl;

    // Clear the stack and check if it's empty
    st.clear();
    cout << (st.empty() ? "Empty\n" : "Not Empty\n");
    std::cout << "Stack size after clearing: " << st.size() << std::endl;
}

int main() {
    test(); // Run the test function
    return 0;
}
