#include <iostream>
using namespace std;

class DNode {
public:
    int value;
    DNode* next;
    DNode* prev;

    DNode(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    int length;
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList(int value) {
        DNode* newNode = new DNode(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList() {
        DNode* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void append(int value) {
        DNode* newNode = new DNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void prepend(int value) {
        DNode* newNode = new DNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void display() {
        DNode* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void intertwine(DoublyLinkedList& otherList) {
        if (!otherList.head) {
            return;
        }

        DNode* thisCurrent = head;
        DNode* otherCurrent = otherList.head;

        while (thisCurrent && otherCurrent) {
            DNode* thisNext = thisCurrent->next;
            DNode* otherNext = otherCurrent->next;

            thisCurrent->next = otherCurrent;
            otherCurrent->prev = thisCurrent;

            if (thisNext) {
                otherCurrent->next = thisNext;
                thisNext->prev = otherCurrent;
            }
            else {
                tail = otherCurrent;
            }

            thisCurrent = thisNext;
            otherCurrent = otherNext;
        }

        length += otherList.length;

        otherList.head = nullptr;
        otherList.tail = nullptr;
        otherList.length = 0;
    }
};

