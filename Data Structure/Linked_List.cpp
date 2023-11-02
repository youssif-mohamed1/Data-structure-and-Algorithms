#include<iostream>

using namespace std;

template<typename T>
struct Node { // node for Linked List
    T data; // data at the current node 
    Node* next; // pointer to the next node
    Node(T val) :data(val), next(NULL){} // constructor for the struct
};

template<typename T>
class Linked_list {
private:
    Node<T>* head;
public:
    Linked_list() :head(NULL) {} // default constructor

    void push_front(T val) { // push element front in the linked list
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T val) { // push element back in the linked list
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode; // if empty
        }
        else {
            Node<T>* current = head;
            while (current->next) { // for reaching last element
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void pop_back() { // remove last element
        if (!head) {
            cout << "Run time error: empty vector";
        }
        else {
            if (!head->next) { // if only one element
                delete head;
                head = NULL;
            }
            else {
                Node<T>* current = head;
                Node<T>* past = NULL;
                while (current->next) { // for reaching last element
                    past = current;
                    current = current->next;
                }
                delete current;
                past->next = NULL;
            }
        }
    }
    
    void pop_front() { // remove first element
        if (!head) {
            cout << "Run time error: empty vector";
        }
        else {
            Node<T>* oldNode = head;
            head = head->next;
            delete oldNode;
        }
    }

    int get_item_index(T val) {
        if (!head) { // if empty
            return -1;
        }
        else {
            int index = 0;
            Node<T>* current = head;
            while (current && current->data != val) { // linear search for the element
                current = current->next;
                index++;
            }
            return (current && current->data == val ? index : -1);
        }
    }

    void insert_in_order(T val) { //insert element according to the order
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            Node<T>* past = NULL;
            while (current && current->data < val) { // searching for the correct place
                past = current;
                current = current->next;
            }
            if (current) {
                if (current == head) { // if the first element is greater
                    push_front(val);
                }
                else {
                    Node<T>* temp = current;
                    past->next = newNode;
                    newNode->next = temp;
                }
            }
            else {
                push_back(val);
            }
        }
    }

    void delete_index(int ind) { // delete element in the index
        if (!head) { // if empty
            cout << "Run time error: empty vector";
        }
        else {
            int index = 0;
            Node<T>* current = head;
            Node<T>* past = NULL;
            while (current && index < ind) { // searhing for the element
                past = current;
                current = current->next;
                index++;
            }
            if (current) {
                if (current == head) { // if this is the first element
                    head = head->next;
                    delete current;
                }
                else {
                    if (current->next) {
                        past->next = current->next;
                    }
                    else { // if it is the last element
                        past->next = NULL;
                    }
                    delete current;
                }
            }
        }
    }

    void insert_index(T val, int ind) { // inserting value at index
        Node<T>* newNode = new Node<T>(val);
        if (ind <= 0) { // if the index is the first of the list
            push_front(val);
        }
        else {
            if (!head) { // if empty 
                head = newNode;
            }
            else {
                int index = 0;
                Node<T>* current = head;
                Node<T>*past = NULL;
                while (current && index < ind) { // searching for the element in that index to shift it
                    past = current;
                    current = current->next;
                    index++;
                }
                if (current) { // if there is an element in that index
                    Node<T>* temp = current;
                    past->next = newNode;
                    newNode->next = temp;
                }
                else { // if no elements in that index
                    past->next = newNode;
                }
            }
        }
    }

    void delete_item(T val) {
        if (head) { // if not empty
            Node<T>* current = head;
            Node<T>*past = NULL;
            while (current && current->data != val) { // searching for the value
                past = current;
                current = current->next;
            }
            if (current) {
                if (current == head) { // if it is the first element
                    head = head->next;
                    delete current;
                }
                else {
                    if (current->next) {
                        past->next = current->next;
                    }
                    else { // if it is the last element
                        past->next = NULL;
                    }
                    delete current;
                }
            }
        }
    }

    void display() { // printing all values of the list
        if (head) {
            Node<T>* current = head;
            while (current) {
                cout << current->data << " ";
                current = current->next;
            }
        }
    }

    bool empty() {
        return !head;
    }

};

void test() {
    Linked_list<int> l;

    cout << "Pushing elements to the front of the list: ";
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.insert_in_order(4);
    l.insert_in_order(2);
    l.insert_in_order(0);
    l.display(); // Should print "0 1 2 2 3 4"
    cout << endl;

    cout << "Pushing elements to the back of the list: ";
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.display(); // Should print "1 2 3 4 5 6"
    cout << endl;

    cout << "Pop the front element: ";
    l.pop_front();
    l.display(); // Should print "2 3 4 5 6"
    cout << endl;

    cout << "Pop the back element: ";
    l.pop_back();
    l.display(); // Should print "2 3 4 5"
    cout << endl;

    cout << "Insert an element at index 2: ";
    l.insert_index(9, 2);
    l.display(); // Should print "2 3 9 4 5"
    cout << endl;

    cout << "Delete an element at index 3: ";
    l.delete_index(3);
    l.display(); // Should print "2 3 9 5"
    cout << endl;

    cout << "Find index of value 9: " << l.get_item_index(9) << endl; // Should print "2"

    cout << "Delete the value 9: ";
    l.delete_item(9);
    l.display(); // Should print "2 3 5"
    cout << endl;

    cout << "Find index of value 9 (after deletion): " << l.get_item_index(9) << endl; // Should print "-1"
}

int main() {
    test();
    return 0;
}
