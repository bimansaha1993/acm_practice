#include<iostream>
using namespace std;

int front = 0, rear = 0, queue[100], capacity;

void enqueue(int a)
{
	if (capacity == rear)
		cout << "queue is full" << endl;
	else
	{
		queue[rear] = a;
		rear++;
	}
}

int dequeue()
{
	if (front == rear)
	{
		cout << "queue is empty" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < rear - 1; i++)
		{
			queue[i] = queue[i + 1];
		}
		rear--;
	}
}

int display()
{
	if (front == rear)
	{
		cout << "queue is empty" << endl;
		return 0;
	}
	else
	{
		for (int i = front; i < rear; i++)
		{
			cout << queue[i]<<" ";
		}
		cout << endl;
	}
	return 0;
}


int main()
{
	cin >> capacity;
	display();
	enqueue(10);
	display();
	enqueue(20);
	display();
	enqueue(30);
	display();
	enqueue(40);
	display();
	enqueue(50);
	display();
	dequeue();
	display();
	dequeue();
	display();
	//dequeue();
	//display();
	//dequeue();
	//display();
	cout << queue[front] << " " << queue[rear] << endl;
	
}