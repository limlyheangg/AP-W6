#include "Node.h"
#include <string.h>
using namespace std;

class Stack {
private:
    Node* top;     // Pointer to the top of the stack
    int length;      // Keeps track of the stack size

public:
    Stack() {       // Constructor
        this->length = 0;
        this->top = nullptr; 
    }

    ~Stack() {      // Destructor to free memory
        while (!isEmpty()) {
            pop();   // Deallocate all nodes
        }
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);

        if (top == NULL) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }

        length++;
    }

    // Pop the top element from the stack
    void pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* pop = top;
        top = top->next;
        delete[] pop;
        length--;
    }

    // Peek the top element without removing it
    int peek() {
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
       return length == 0; 
    }

    // Get the current length of the stack
    int size() {
        return length;
    }
    // Convert the stack to a string representation
    string toString() {
        string result = "Output: ";
        Node* currentNode = top;
        while (currentNode != NULL) {
            result += to_string(currentNode->data);
            result += ", ";
            currentNode = currentNode->next;
        }
        result += "\b\b";
        return result;
    }
};