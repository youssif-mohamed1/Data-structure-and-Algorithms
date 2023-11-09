#include<iostream>
#include<queue>

using namespace std;

struct node {
    int name, father, order; // Properties of each node
};

void bfs(node* tree, int n) { // Breadth-First Search function
    queue<int> q; // Queue to store nodes to be visited
    int* sons = new int[n]; // Array to store child nodes

    // Find the root and push it onto the queue
    for (int i = 0; i < n; i++) {
        if (tree[i].father == -1) {
            q.push(tree[i].name);
            break;
        }
    }

    while (!q.empty()) { // Continue until the queue is empty
        int father = q.front(); // Get the front node from the queue
        cout << father << " "; // Print the name of the node
        q.pop(); // Pop the node from the queue
        int counter = 0;

        // Iterate through the tree to find child nodes
        for (int i = 0; i < n; i++) {
            if (tree[i].father == father) {
                sons[tree[i].order] = tree[i].name; // Store child node names
                counter++;
            }
        }

        // Push child nodes onto the queue in order
        for (int i = 1; i <= counter; i++) {
            q.push(sons[i]);
        }
    }
}

signed main() {
    int n;
    cin >> n;
    node* tree = new node[n];

    // Input the tree structure
    for (int i = 0; i < n; i++) {
        cin >> tree[i].name >> tree[i].father >> tree[i].order;
    }

    bfs(tree, n); // Perform BFS and print the result
}

/* input
name father order
0      5     1
1     -1     0
2      1     1
3      2     2
4      0     1
5      1     2
6      7     1
7      2     1
8      3     1
9      0     2
*/