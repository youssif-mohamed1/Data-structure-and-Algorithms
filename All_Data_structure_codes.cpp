#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#define dim 7
#define INF 1e9
const int N = 7;
int arr[N] = { 89,210,31,2,1,6,3 };

int weight[dim][dim] =
{ { 0, 3, INF, INF, INF, INF, 2 },
  { 3, 0, 2, INF, INF, INF, 5 },
  { INF, 2, 0, 7, 1, 1, 3 },
  { INF, INF, 7, 0, 6, 7, INF },
  { INF, INF, 1, 6, 0, 4, INF },
  { INF, INF, 1, 7, 4, 0, 8 },
  { 2, 5, 3, INF, INF, 8, 0 }
}, min_span[dim][dim];

struct double_linked_list_node {
	int data;
	double_linked_list_node* next, * prev;
	double_linked_list_node(int val) :data(val), next(NULL), prev(NULL) {}
};

class Double_Linked_List {
private:
	double_linked_list_node *front, *rear;
	int cnt = 0;
public:
	Double_Linked_List() {
		front = rear = NULL;
	}
	void insert_first(int val) {
		double_linked_list_node* newNode = new double_linked_list_node(val);
		if (!front) {
			front = rear = newNode;
		}
		else {
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
		cnt++;
	}
	void insert_back(int val) {
		double_linked_list_node* newNode = new double_linked_list_node(val);
		if (!front) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			newNode->prev = rear;
			rear = newNode;
		}
		cnt++;
	}
	void insert_at_index(int ind, int val) {
		double_linked_list_node* newNode = new double_linked_list_node(val);
		if (!front || ind <= 0) {
			insert_first(val);
		}
		else if (ind >= cnt) {
			insert_back(val);
		}
		else {
			double_linked_list_node* current = front, * parent = NULL;
			int index = 0;
			while (current && index < ind) {
				parent = current;
				current = current->next;
				index++;
			}
			parent->next = newNode;
			newNode->prev = parent;
			newNode->next = current;
			current->prev = newNode;
			cnt++;
		}
	}
	void insert_in_order(int val) {
		double_linked_list_node* newNode = new double_linked_list_node(val);
		if (!front) {
			front = rear = newNode;
			cnt++;
		}
		else {
			double_linked_list_node* current = front, * parent = NULL;
			while (current && current->data < val) {
				parent = current;
				current = current->next;
			}
			if (current) {
				if (current == front) {
					insert_first(val);
				}
				else {
					parent->next = newNode;
					newNode->prev = parent;
					newNode->next = current;
					current->prev = newNode;
					cnt++;
				}
			}
			else {
				insert_back(val);
			}
		}
	}
	void delete_first() {
		if (!front) {
			cout << "Empty: ";
		}
		else {
			double_linked_list_node* temp = front;
			front = front->next;
			front->next->prev = NULL;
			delete temp;
		}
		cnt--;
	}
	void delete_last() {
		if (!front) {
			cout << "Empty: ";
		}
		else {
			double_linked_list_node* temp = rear;
			rear = rear->prev;
			rear->next = NULL;
			delete temp;
		}
		cnt--;
	}
	void delete_index(int ind) {
		if (!front) {
			cout << "Empty: ";
		}
		else {
			if (ind <= 0) {
				delete_first();
			}
			else if (ind >= cnt-1) {
				delete_last();
			}
			else {
				double_linked_list_node* current = front, *parent = NULL;
				int index = 0;
				while (current && index < ind) {
					parent = current;
					current = current->next;
					index++;
				}
				parent->next = current->next;
				current->next->prev = parent;
				delete current;
			}
		}
	}
	void delete_first_occure(int val) {
		if (!front) {
			cout << "Empty: ";
		}
		else {
			double_linked_list_node* current=front, * parent=NULL;
			while (current && current->data != val) {
				parent = current;
				current = current->next;
			}
			if (current) {
				if (current == front) {
					delete_first();
				}
				else {
					parent->next = current->next;
					if (current->next) {
						current->next->prev = parent;
					}
					delete current;
				}
			}
		}
	}
	int search(int val) {
		if (!front)return -1;
		else {
			double_linked_list_node* current=front;
			int index = 0;
			while (current && current->data != val) {
				current = current->next;
				index++;
			}
			if (current) {
				return index;
			}
			else {
				return -1;
			}
		}
	}
	int size() {
		return cnt;
	}
	bool isempty() {
		return !front;
	}
	void print_first_to_last() {
		double_linked_list_node* current = front;
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void print_last_to_first() {
		double_linked_list_node* current = rear;
		while (current) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}
};

void heapify_node(int i, int n) {
	int parent = i, l = i * 2 + 1, r = i * 2 + 2;
	if (l<n && arr[parent]<arr[l]) {
		parent = l;
	}
	if (r<n && arr[parent]<arr[r]) {
		parent = r;
	}
	if (parent != i) {
		int temp = arr[parent];
		arr[parent] = arr[i];
		arr[i] = temp;
		heapify_node(parent, n);
	}
}

void heapify_tree(int n) {
	for (int i = (n / 2) - 1; i >= 0; i--) {
		heapify_node(i,n);
	}
}

void heap_sort(int n) {
	heapify_tree(n);
	for (int i = n - 1; i >= 0; i--) {
		int t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;
		heapify_tree(i);
	}
}

void all_to_all_shortest_path(int weight[][dim], int n) {
	bool flag = 0;
	do {
		flag = 0;
		for (int src = 0; src < n; src++) {
			for (int dest = 0; dest < n; dest++) {
				for (int via = 0; via < n; via++) {
					if (weight[src][dest] > weight[src][via] + weight[via][dest]) {
						weight[src][dest] = weight[src][via] + weight[via][dest];
						flag = 1;
					}
				}
			}
		}
	} while (flag);
}

int shortest_path_between_two_points(int weight[][dim], int n,int source,int dest) {
	int z[dim][3], mini=0, rmin;
	for (int i = 0; i < n; i++) {
		z[i][0] = -1; z[i][1] = INF; z[i][2] = 0;
	}
	rmin = source;
	z[rmin][0] = source;
	z[rmin][1] = 0;
	z[rmin][2] = 1;
	do {
		for (int i = 0; i < n; i++) {
			if (z[i][2] == 0 && z[i][1] > weight[rmin][i] + mini) {
				z[i][1] = weight[rmin][i] + mini;
				z[i][0] = rmin;
			}
		}
		mini = INF;
		rmin = -1;
		for (int i = 0; i < n; i++) {
			if (z[i][2] == 0 && z[i][1] < mini) {
				mini = z[i][1];
				rmin = i;
			}
		}
		z[rmin][2] = 1;
	} while (rmin != dest);
	int r = dest;
	int sum = z[dest][1];
	while (r != source) {
		cout << r<<" ";
		r = z[r][0];
	}
	cout << source;
	return sum;
}

int kruskal(int weight[][dim],int n) {
	int z[dim];
	int mini = INF, rmin, cmin, total_weight = 0, group = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			min_span[i][j] = INF;
			if (i == j) {
				min_span[i][j] = 0;
			}
		}
		z[i] = -1;
	}

	while (1) {
		mini = INF;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (weight[i][j] < mini) {
					mini = weight[i][j];
					rmin = i;
					cmin = j;
				}
			}
		}
		if (mini == INF) {
			return total_weight;
		}
		if (z[rmin] == -1 || z[cmin] == -1 || (z[rmin] != z[cmin])) {
			total_weight += mini;
			min_span[rmin][cmin] = min_span[cmin][rmin] = mini;
			if (z[rmin] == -1 && z[cmin] == -1) {
				z[rmin] = z[cmin] = ++group;
			}
			else if (z[rmin] != -1 && z[cmin] == -1) {
				z[rmin] = z[cmin];
			}
			else if (z[rmin] == -1 && z[cmin] != -1) {
				z[cmin] = z[rmin];
			}
			else {
				int temp = z[rmin];
				for (int i = 0; i < n; i++) {
					if (z[i] == temp) {
						z[i] = z[cmin];
					}
				}
			}
		}
		weight[rmin][cmin] = weight[cmin][rmin] = INF;
	}

}

int prims(int weight[][dim], int n) {
	int z[dim][3],mini=INF,rmin,cmin,total_weight=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			min_span[i][j] = INF;
			if (i == j) {
				min_span[i][j] = 0;
			}
		}
		z[i][0] = -1;
		z[i][1] = INF;
		z[i][2] = 0;
	}
	rmin = 0;
	z[0][0] = 0;
	z[0][1] = 0;
	z[0][2] = 1;
	do {
		for (int i = 0; i < n; i++) {
			if (z[i][2] == 0 && z[i][1]>weight[rmin][i]) {
				z[i][0] = rmin; z[i][1] = weight[rmin][i];
			}
		}
		mini = INF; cmin = -1;
		for (int i = 0; i < n; i++) {
			if (z[i][2] == 0 && z[i][1] < mini) {
				mini = z[i][1];
				rmin = z[i][0];
				cmin = i;
			}
		}
		if (mini == INF) {
			return total_weight;
		}
		min_span[rmin][cmin] = min_span[cmin][rmin] = mini;
		rmin = cmin;
		total_weight += mini;
		z[rmin][2] = 1;
	} while (rmin != -1);
}

struct treeNode {
	char name, father;
	int order;
} treeArray[12] = { {'A','M',2},{'B','M',1},{'C','A',1},
	{'D','H',3},	{'F','H',1},{'G','H',2},{'H','M',3},{'K','B',2},{'M','0',0},
	{'P','K',2},{'X','K',1},{'Y','B',1} };


void dfs(treeNode* arr,int n) {
	stack<char>st;
	char* sons = new char[n];
	for (int i = 0; i < n; i++) {
		if (arr[i].father == '0') {
			st.push(arr[i].name);
			break;
		}
	}
	while (!st.empty()) {
		cout << st.top()<<" ";
		char root = st.top();
		st.pop();
		int counter = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i].father == root) {
				sons[arr[i].order] = arr[i].name;
				counter++;
			}
		}
		for (int i = counter; i > 0; i--) {
			st.push(sons[i]);
		}
	}
}


void bfs(treeNode* arr, int n) {
	queue<char>q;
	char* sons = new char[n];
	for (int i = 0; i < n; i++) {
		if (arr[i].father == '0') {
			q.push(arr[i].name);
			break;
		}
	}
	while (!q.empty()) {
		cout << q.front()<<" ";
		char temp = q.front();
		q.pop();
		int counter = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i].father == temp) {
				sons[arr[i].order] = arr[i].name;
				counter++;
			}
		}
		for (int i = 1; i <= counter; i++) {
			q.push(sons[i]);
		}
	}
}

void insertion_sort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		for (int j = i - 1; j >= 0 && temp < arr[j]; j--) {
			int t = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = t;
		}
	}
}

void selection_sort(int* arr, int n) {
	for (int i = 0; i < n-1; i++) {
		int min_loc = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_loc]) {
				min_loc = j;
			}
		}
		int t = arr[i];
		arr[i] = arr[min_loc];
		arr[min_loc] = t;
	}
}

void bubble_sort(int* arr, int n) {
	bool flag = 0;
	int i = 0;
	while (!flag) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = 1;
			}
		}
		i++;
		if (!flag)break;
		else flag = 0;
	}
}

void merge_two_list(int*arr, int left, int le, int right, int re) {
	int* res = new int[le - left + re - right];
	int l = left, r = right,i=0;
	while (l < le && r < re) {
		if (arr[l] < arr[r]) {
			res[i] = arr[l];
			l++;
		}
		else {
			res[i] = arr[r];
			r++;
		}
		i++;
	}
	while (l < le) { res[i] = arr[l]; l++; i++; }
	while (r < re) {res[i] = arr[r];r++; i++; }
	for (int i = 0; i < le - left + re - right; i++) {
		arr[left + i] = res[i];
	}
}

void merge_sort(int* arr, int start, int end) {
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge_two_list(arr, start, mid+1, mid + 1, end+1);
}

void quick_sort(int* arr, int left, int right) {
	if (left >= right)
		return;
	int pivot = arr[left], k1 = left, k2 = right;
	while (k1 <= k2) {
		while (k1 <= right && arr[k1] <= pivot)k1++;
		while (k2 >= left && arr[k2] > pivot)k2--;
		if (k1 < k2) {
			int t = arr[k1];
			arr[k1] = arr[k2];
			arr[k2] = t;
		}
	}
	arr[left] = arr[k2];
	arr[k2] = pivot;
	quick_sort(arr, left, k2 - 1);
	quick_sort(arr, k2 + 1, right);
}

struct degree {
	int id;
	char g;
}deg[N] = {{1,'B'},{2,'C'} ,{3,'A'} ,{4,'A'} ,{5,'B'} ,{6,'D'} ,{7,'E'} };

void count_sort(degree* arr, int n) {
	int count[6] = {};
	for (int i = 0; i < n; i++) {
		count[arr[i].g - 'A']++;
	}
	for (int i = 1; i < 6; i++) {
		count[i] +=count[i - 1];
	}
	degree* res = new degree[n];
	for (int i = n - 1; i >= 0; i--) {
		res[--count[arr[i].g - 'A']] = arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = res[i];
	}
}

void radix_sort(int* arr, int n) {
	int digits = 1;
	for (int k = 1; k <= 3; k++) {
		int count[10] = {};
		for (int i = 0; i < n; i++) {
			count[(arr[i] / digits) % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		int* res = new int[n];
		for (int i = n-1;i>=0; i--) {
			res[--count[(arr[i] / digits) % 10]] = arr[i];
		}
		for (int i = 0; i < n; i++) {
			arr[i] = res[i];
		}
		digits *= 10;
	}
}

struct node {
	int data;
	node* left, * right;
	node(int val) :data(val), left(NULL), right(NULL) {}
};

class binary_search_tree {
public:
	node* root;
	binary_search_tree() {
		root = NULL;
	}
	void insert_data(int val, node*& root) {
		if (!root) {
			root = new node(val);
		}
		else {
			if (val > root->data) {
				if (!root->right) {
					node* temp = new node(val);
					root->right = temp;
				}
				else {
					insert_data(val, root->right);
				}
			}
			else if (val < root->data) {
				if (!root->left) {
					node* temp = new node(val);
					root->left = temp;
				}
				else {
					insert_data(val, root->left);
				}
			}
		}
	}
	void pre_order(node* root) {
		if (root) {
			cout << root->data << " ";
			pre_order(root->left);
			pre_order(root->right);
		}
	}
	void in_order(node* root) {
		if (root) {
			in_order(root->left);
			cout << root->data << " ";
			in_order(root->right);
		}
	}
	void post_order(node* root) {
		if (root) {
			post_order(root->left);
			post_order(root->right);
			cout << root->data << " ";
		}
	}
	bool search(int val,node*root) {
		if (!root)return -1;
		else {
			if (val == root->data) {
				return 1;
			}
			else if (val > root->data) {
				search(val, root->right);
			}
			else {
				search(val, root->left);
			}
		}
	}
	void delete_node(int val, node*& root) {
		if (root) {
			if (val > root->data) {
					delete_node(val, root->right);
			}
			else if (val < root->data) {
					delete_node(val, root->left);
			}
			else {
				if (!root->left) {
					node* temp = root->right;
					delete root;
					root = temp;
				}
				else if (!root->right) {
					node* temp = root->left;
					delete root;
					root = temp;
				}
				else {
					node* temp = root->right;
					while (temp->left) {
						temp = temp->left;
					}
					root->data = temp->data;
					delete_node(temp->data, root->right);
				}
			}
		}
	}
};

void print_matrix(int mat[][dim], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mat[i][j] == INF) {
				cout << "# ";
			}
			else {
				cout << mat[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	
}