#include<iostream>
using namespace std;

struct queueNode
{
	int data;
	queueNode *next;
};

class LinkedListQueue
{
private:
	queueNode *front, *rear;
public:
	LinkedListQueue()
	{
		front = rear = NULL;
	}
	void enqueue(int dd)
	{
		queueNode *temp;
		temp = new queueNode;
		temp->data = dd;
		temp->next = NULL;
		if(rear == NULL)		front = rear = temp;
		else
			{
				rear->next = temp;
				rear = temp;
		}
	}
	int dequeue(void)
	{
		queueNode *temp;
		int dd;
		dd = front->data;
		temp = front;
		front = front->next;
		delete temp;
		if(front == NULL)		rear = NULL;
		return dd;
	}
	bool isEmpty(void)
	{
		return front == NULL;
	}
	void printQueue(void)
	{
		queueNode *temp;
		cout << "All data in queue : ";
		for(temp = front ; temp != NULL ; temp = temp->next)
			cout << temp->data << "\t";
		cout << "\n";
	}
	int getNumberOfElements(void)
	{
		int counter;
		queueNode *temp;
		counter = 0;
		for(temp = front ; temp != NULL ; temp = temp->next)		
			counter++;
		return counter;
	}
};


void test() {
	// put yout own tests
}

int main() {
    test(); // Run the test function
    return 0;
}
