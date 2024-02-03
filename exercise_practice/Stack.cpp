#include <iostream>
using namespace std;

class SNode {
public:
	int value;
	SNode* next;

	SNode(int value) {
		this->value = value;
		next = nullptr;
	}
};


class Stack {
private:
	SNode* top;
	int height;

public:
	Stack(int value) {
		SNode* newNode = new SNode(value);
		top = newNode;
		height = 1;
	}

	void printStack() {
		SNode* temp = top;
		while (temp) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	void getTop() {
		cout << "Top: " << top->value << endl;
	}
	void getHeight() {
		cout << "Height: " << height << endl;
	}

	void push(int value) {
		SNode* newNode = new SNode(value);
		newNode->next = top;
		top = newNode;
		height++;
	}

	int pop() {
		if (height == 0) return INT_MIN;

		SNode* temp = top;
		int poppedValue = top->value;
		top = top->next;
		delete temp;
		height--;

		return poppedValue;
	}
};