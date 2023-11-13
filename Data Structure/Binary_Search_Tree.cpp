#include <iostream>

using namespace std;

struct node {
    int data;
    node* left, * right;
    node(int val) : left(nullptr), right(nullptr), data(val) {}
};

class binary_search_tree {
private:
    node* find_min_right_sub_tree(node* n) {
        while (n->left) {
            n = n->left;
        }
        return n;
    }
public:
    node* root;
    binary_search_tree() : root(nullptr) {}

    void insert(int val, node*& place) {
        node* newNode = new node(val);
        if (!place) {
            place = newNode;
            return;
        }
        if (val < place->data) {
            insert(val, place->left);
        }
        else if (val > place->data) {
            insert(val, place->right);
        }
    }

    void pre_order(node* n) {
        if (!n)
            return;
        cout << n->data << " ";
        pre_order(n->left);
        pre_order(n->right);
    }

    void in_order(node* n) {
        if (!n)
            return;
        in_order(n->left);
        cout << n->data << " ";
        in_order(n->right);
    }

    void post_order(node* n) {
        if (!n)
            return;
        post_order(n->left);
        post_order(n->right);
        cout << n->data << " ";
    }

    void delete_node(int val, node*& n) {
        if (!n)
            return;
        if (val < n->data) {
            delete_node(val, n->left);
        }
        else if (val > n->data) {
            delete_node(val, n->right);
        }
        else {
            if (!n->left) {
                node* temp = n->right;
                delete n;
                n = temp;
            }
            else if (!n->right) {
                node* temp = n->left;
                delete n;
                n = temp;
            }
            else {
                node* rep = find_min_right_sub_tree(n->right);
                n->data = rep->data;
                delete_node(rep->data, n->right);
            }
        }
    }
};


signed main() {
    /*
         5
        / \
      3     8
     / \   / \
    1  4  7   9
     \   /
      2 6
    pre_order:   5 3 1 2 4 8 7 6 9
    in_order:    1 2 3 4 5 6 7 8 9
    Post_order:  2 1 4 3 6 7 9 8 5

    */
	binary_search_tree bst;
    bst.insert(5,bst.root);
    bst.insert(3, bst.root);
    bst.insert(8, bst.root);
    bst.insert(1, bst.root);
    bst.insert(9, bst.root);
    bst.insert(7, bst.root);
    bst.insert(6, bst.root);
    bst.insert(2, bst.root);
    bst.insert(4, bst.root);

    bst.pre_order(bst.root);
    cout << endl;

    bst.in_order(bst.root);
    cout << endl;

    bst.post_order(bst.root);
    cout << endl;

    // pre_order after removing the root expected: 6 3 1 2 4 8 7 9
    bst.delete_node(5, bst.root);
    bst.pre_order(bst.root);
    return 0;
}