#include<iostream>
#include<vector> // for vector
#include<deque> // for deque
#include<queue> // for queue
#include<stack> // for stack
#include<cstring> // for memset

using namespace std;
const int N = 1e5 + 5; // max size
int n; // the size of the graph
vector<int>adj[N]; // adjacency list
bool vis[N], // visited list
recursion_stack[N]; // recursion stack list for the cyclce detection in directed graph
stack<int>topsort; // topological sort stack
deque<int>ans; // the answer of the topological sort

class Graph {
public:
	Graph() {}
	void reset(int n) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear(); // reset all elements of the adjacency list to 0
			vis[i] = 0; // clear the visited array
		}
	}

	void add_edge_directed(int a, int b) {
		adj[a].push_back(b);
	}

	bool topological_sort(int i) {
		vis[i] = 1; // mark node as visited
		recursion_stack[i] = 1;
		topsort.push(i); // push the node in the stack
		for (auto it : adj[i]) {
			if (!vis[it]) {
				if (topological_sort(it)) {
					return 1;
				}
			}
			else if (recursion_stack[it] = 1) {
				return 1; // cycle detected
			}
		}
		ans.push_front(topsort.top()); // push the leaves to the front 
		topsort.pop(); // pop the node from the stack
		recursion_stack[i] = 0; // removing node from stack array
		return 0; // cycle not detected
	}
};

signed main() {
	cin >> n;
	Graph graph;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); // add edge directed from a to b 
	}
	bool can_not_be_sorted=graph.topological_sort(1); // start topological sort
	if (can_not_be_sorted) {
		cout << "Can not Be Sorted"; return 0;
	}
	for (auto it : ans) { // print the sorted elements
		cout << it << " ";
	}cout << endl;
}