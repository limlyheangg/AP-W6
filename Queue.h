#include "Node.h"
using namespace std;
class Queue {
private:
    Node* front;     // Pointer to the front of the queue
    Node* rear;      // Pointer to the rear of the queue
    int length;      // Keeps track of the queue size
public:
    Queue() {       // Constructor
        length = 0;
    }
    ~Queue() {      // Destructor to free memory
        while (!isEmpty()) {
            dequeue();   // Deallocate all nodes
        }
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }
    // Dequeue the front element from the queue
    void dequeue() {
        Node* head = front;
       
        if(length > 0) {
            front = head->next;
            length--;
        }
    }


    // Peek the front element without removing it
    int peek() {
        if(length <= 0)
        {
            return -1;
        }
        else{
        
        return front->data;
        }
        
        
    }
    // Check if the queue is empty
    bool isEmpty() {
        return length == 0;
    }
    // Get the current length of the queue
    int size() {
        return length;
    }

    // Convert the queue to a string representation
    std::string toString() {

        Node* str = front;
        std::string result = " ";
        while (str!=NULL)
        {
            result += std::to_string(str->data) + " ";
            str = str->next;
           
        }
        return result;
    }

};