#include<iostream>

using namespace std;

struct node {
    int data;
    node* next, * prev;
    node(int val) :data(val), next(nullptr), prev(nullptr) {}
};

class Double_Linked_List {
public:
    node* front, * rear;

    Double_Linked_List() : front(nullptr), rear(nullptr) {}

    void insert_first(int val) {
        node* newNode = new node(val);
        if (!front) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insert_back(int val) {
        node* newNode = new node(val);
        if (!front) {
            front = rear = newNode;
        }
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void insert_at_index(int ind, int val) {
        if (ind <= 0) {
            insert_first(val);
        }
        else {
            node* newNode = new node(val);
            node* current = front;
            node* parent = nullptr;
            int index = 0;
            while (current && index < ind) {
                index++;
                parent = current;
                current = current->next;
            }
            if (!current) {
                insert_back(val);
            }
            else {
                newNode->next = current;
                newNode->prev = parent;
                parent->next = newNode;
                current->prev = newNode;
            }
        }
    }

    void insert_data_in_order(int val) {
        if (!front) {
            insert_first(val);
        }
        else {
            node* newNode = new node(val);
            node* current = front;
            node* parent = nullptr;
            while (current && current->data < val) {
                parent = current;
                current = current->next;
            }
            if (!current) {
                insert_back(val);
            }
            else {
                if (!parent) {
                    insert_first(val);
                }
                else {
                    newNode->next = current;
                    newNode->prev = parent;
                    parent->next = newNode;
                    current->prev = newNode;
                }
            }
        }
    }

    void delete_first() {
        if (!front) {
            cout << "Empty list!" << endl;
        }
        else {
            node* temp = front;
            if (front->next) {
                front = front->next;
                front->prev = nullptr;
            }
            else {
                front = rear = nullptr;
            }
            delete temp;
        }
    }

    void delete_back() {
        if (!front) {
            cout << "Empty list!" << endl;
        }
        else {
            node* temp = rear;
            if (rear->prev) {
                rear = rear->prev;
                rear->next = nullptr;
            }
            else {
                front = rear = nullptr;
            }
            delete temp;
        }
    }

    void delete_index(int ind) {
        if (!front) {
            cout << "Empty list!" << endl;
        }
        else {
            if (ind <= 0) {
                delete_first();
                return;
            }
            node* current = front;
            node* parent = nullptr;
            int index = 0;
            while (current && index < ind) {
                index++;
                parent = current;
                current = current->next;
            }
            if (!current) {
                delete_back();
            }
            else {
                if (current->next) {
                    parent->next = current->next;
                    current->next->prev = parent;
                }
                else {
                    parent->next = nullptr;
                    rear = parent;
                }
                delete current;
            }
        }
    }

    void delete_first_data_occure(int val) {
        if (!front) {
            cout << "Empty list!" << endl;
        }
        else {
            node* current = front;
            node* parent = nullptr;
            while (current && current->data != val) {
                parent = current;
                current = current->next;
            }
            if (!current) {
                cout << "Value not found!" << endl;
            }
            else {
                if (current->next) {
                    if (parent) {
                        parent->next = current->next;
                        current->next->prev = parent;
                    }
                    else {
                        delete_first();
                    }
                }
                else {
                    if (parent) {
                        parent->next = nullptr;
                        rear = parent;
                    }
                    else {
                        front = rear = nullptr;
                    }
                    delete current;
                }
            }
        }
    }

    int get_size() const {
        int cnt = 0;
        node* current = front;
        while (current) {
            cnt++;
            current = current->next;
        }
        return cnt;
    }

    bool isempty() const {
        return !front;
    }

    void delete_list() {
        while (!isempty()) {
            delete_first();
        }
    }

    int search(int val) const {
        if (!front) {
            return -1;
        }
        else {
            node* current = front;
            int ind = 0;
            while (current && current->data != val) {
                ind++;
                current = current->next;
            }
            if (!current) {
                return -1;
            }
            else {
                return ind;
            }
        }
    }

    void print_from_first_to_last() const {
        node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_from_last_to_first() const {
        node* current = rear;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

void testDoubleLinkedList() {
    Double_Linked_List d;
    d.insert_first(0);
    d.insert_back(1);
    d.insert_back(2);
    d.insert_back(3);
    d.insert_at_index(4, 4);
    d.insert_data_in_order(- 1);
    d.delete_back();
    d.delete_first();
    d.delete_first_data_occure(0);
    d.delete_index(3);
    d.print_from_first_to_last();
    cout << d.search(1);
    d.delete_list();
}

int main() {
    testDoubleLinkedList();
    return 0;
}

