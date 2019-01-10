#include<iostream>
using namespace std;
int queue[100], capacity, front, rear, size, temp;
void clear()
{
	front = 0;
	rear = 0;
	size = 0;
}

bool isempty()
{
	if (size == 0)
		return 0;
}

void enqueue(int val)
{
	if (size == capacity)
		return;
	queue[rear] = val;
	rear = (rear + 1) % capacity;
	size++;
	return;
}

void dequeue()
{
	if (isempty())
		return ;
	temp = queue[front];
	front = (front + 1) % capacity;
	size--;
}

void display()
{
	for (int i = 0; i < size; i++)
	{
		cout << queue[i]<<" ";
	}
	cout << endl;
}

int main()
{
	cin >> capacity;
	clear();
	bool isempty();
	enqueue(10);
	display();
	cout << front << " " << rear << endl;
	enqueue(20);
	display();
	cout << front << " " << rear << endl;
	enqueue(30);
	display();
	cout << front << " " << rear << endl;
	enqueue(40);
	display();
	cout << front << " " << rear << endl;
	enqueue(50);
	display();
	cout << front << " " << rear << endl;
	dequeue();
	display();
	cout << front << " " << rear << endl;
	dequeue();
	display();
	cout << front << " " << rear << endl;

}