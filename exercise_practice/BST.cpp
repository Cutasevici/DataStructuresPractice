#include <iostream>
using namespace std;

class Tnode {
public:
	int value;
	Tnode* left;
	Tnode* right;

	Tnode(int value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};

class BST {
public:
	Tnode* root;
public:
	BST() {	
		root = nullptr;
	}

	bool insert(int value) {
		Tnode* newNode = new Tnode(value);
		if (root == nullptr) {
			root = newNode;
			return true;
		}
		Tnode* temp = root;
		while (true) {
			if (newNode->value == temp->value) return false;
			if (newNode->value < temp->value) {
				if (temp->left == nullptr) {
					temp->left = newNode;
					return true;
				}
				temp = temp->left;
			}
			else {
				if (temp->right == nullptr) {
					temp->right = newNode;
					return true;
				}
				temp = temp->right;
			}
		}
	}
	int getMax() {
		if (root == nullptr) {
			cout << "Tree is empty." << endl;
			return INT_MIN;
		}

		Tnode* current = root;
		while (current->right != nullptr) {
			current = current->right;
		}

		return current->value;
	}
};