#include <iostream>
using namespace std;

class Qnode {
public:
	int value;
	Qnode* next;

	Qnode(int value) {
		this->value = value;
		next = nullptr;
	}
};

class Queue {
private:
	Qnode* first;
	Qnode* last;
	int length;

public:
	Queue(int value) {
		Qnode* newNode = new Qnode(value);
		first = newNode;
		last = newNode;
		length = 1;
	}

	void printQueue() {
		Qnode* temp = first;
		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	void getFirst() {
		cout << "First: " << first->value << endl;
	}

	void getLast() {
		cout << "Last: " << last->value << endl;
	}

	void getLength() {
		cout << "Length: " << length << endl;
	}

	void enqueue(int value) {
		Qnode* newNode = new Qnode(value);
		if (length == 0) {
			first = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
		length++;
	}
	int dequeue() {
		if (length == 0) return INT_MIN;
		Qnode* temp = first;
		int dequeueValue = first->value;
		if (length == 1) {
			first = nullptr;
			last = nullptr;
		}
		else {
			first = first->next;
		}
		delete temp;
		length--;
		return dequeueValue;
	}
};