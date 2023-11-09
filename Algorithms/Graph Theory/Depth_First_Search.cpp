#include<iostream>
#include<stack>

using namespace std;

const int N = 10;
int mx;
bool vis[N];

struct node {
    int name, father, order;
};

void dfs_iterative(node* tree, int n) { // DFS using iteration
    stack<int> st; // Stack to keep track of nodes
    int* sons = new int[n]; // Array to store child nodes

    // Find the root and push it onto the stack
    for (int i = 0; i < n; i++) {
        if (tree[i].father == -1) {
            st.push(tree[i].name);
            break;
        }
    }

    while (!st.empty()) { // Continue until the stack is empty
        int father = st.top(); // Get the top node from the stack
        cout << father << " "; // Print the name of the node
        st.pop(); // Pop the node from the stack
        int counter = 0;

        // Iterate through the tree to find child nodes
        for (int i = 0; i < n; i++) {
            if (tree[i].father == father) {
                sons[tree[i].order] = tree[i].name; // Store child node names
                counter++;
            }
        }

        // Push child nodes onto the stack in reverse order
        for (int i = counter; i > 0; i--) {
            st.push(sons[i]);
        }
    }
}

void dfs_recursive(int adj[][N], int i) { // Recursive DFS
    vis[i] = 1; // Mark the node as visited
    cout << i << " "; // Print the name of the node
    for (int j = 1; j < mx; j++) {
        // Recursively visit unvisited and valid adjacent nodes
        if (!vis[adj[i][j]] && adj[i][j] != -1) {
            dfs_recursive(adj, adj[i][j]);
        }
    }
}

signed main() {
    int n;
    cin >> n;
    int adj[N][N];

    // Initialize the adjacency matrix with -1
    for (int i = 0; i < N * N; ++i) {
        adj[i / N][i % N] = -1;
    }

    node* tree = new node[n];
    int root;

    // Input the tree structure and build the adjacency matrix
    for (int i = 0; i < n; i++) {
        cin >> tree[i].name >> tree[i].father >> tree[i].order;
        if (tree[i].father == -1)
            root = tree[i].name;
        else
            adj[tree[i].father][tree[i].order] = tree[i].name;
        mx = max(mx, tree[i].order + 1);
    }

    // Perform iterative DFS and print the result
    dfs_iterative(tree, n);
    cout << endl;

    // Perform recursive DFS and print the result
    dfs_recursive(adj, root);
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