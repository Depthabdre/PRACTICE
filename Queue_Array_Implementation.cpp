#include <iostream>
using namespace std;

// Constants for array operation on queue
const int DefaultListSize = 10;
int queue_size = 0;
int top = -1;
int queue[DefaultListSize];
int front = -1;
int rear = -1;

// for linked list 
struct Node {
    int data;
    Node* next;
};
Node* topPtr = nullptr;
Node* tailptr = nullptr;


void queue_array_enqueue(int num) {
    if (queue_size < DefaultListSize) {
        rear += 1; 
        queue[rear] = num;
        if (front == -1) {
            front += 1;
        }
        queue_size++;
        cout << "Enqueued " << num << " successfully.\n"; 
    } else {
        cout << "ALERT!!!! Queue is Full!!!!\n";
    }
}


int queue_array_dequeue() {
    if (queue_size == 0) {
        cout << "ALERT!!!! Queue is Empty!!!!\n";
        return -1; 
    }
    int dequeuedValue = queue[front++];
    queue_size--;
    return dequeuedValue;
}


void queue_array_display() {
    if (queue_size == 0) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Queue contents: ";
    for (int i = front; i <= rear; i++) { 
        cout << queue[i] << " ";
    }
    cout << endl;
}


void queuePtr_enqueue(Node* value) {
    value->next = nullptr; 
    if (topPtr == nullptr) { 
        topPtr = value;
        tailptr = value;
    } else {
        tailptr->next = value; 
        tailptr = value;       
    }
    cout << "Enqueued " << value->data << " successfully.\n"; 
}

void queuePtr_dequeue() {
    if (topPtr == nullptr) { 
        cout << "ALERT!!!! Queue is Empty!!!!\n";
        return;
    }

    Node* temp = topPtr; 
    topPtr = topPtr->next; 

    if (topPtr == nullptr) { 
        tailptr = nullptr; 
    }

    delete temp; 
    cout << "Dequeued successfully.\n";
}

void queuePtr_display() {
    if (topPtr == nullptr) {
        cout << "Queue is Empty!\n";
        return;
    }
    Node* temp = topPtr;
    cout << "Queue contents: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. queue_array Operations\n";
        cout << "2. queuePtr Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            while (true) {
                cout << "\nqueue_array Menu\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Back to Main Menu\n";
                cout << "Enter your choice: ";
                int queueChoice, num;
                cin >> queueChoice;

                if (queueChoice == 1) {
                    cout << "Enter number to enqueue: ";
                    cin >> num;
                    queue_array_enqueue(num);
                } else if (queueChoice == 2) {
                    int num = queue_array_dequeue();
                    if (num != -1) { 
                        cout << "The Number at Front is : " << num << "\n";
                    }
                } else if (queueChoice == 3) {
                    queue_array_display();
                } else if (queueChoice == 4) {
                    break;
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } else if (choice == 2) {
            while (true) {
                cout << "\nqueuePtr Menu\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Back to Main Menu\n";
                cout << "Enter your choice: ";
                int queueChoice, num;
                cin >> queueChoice;

                if (queueChoice == 1) {
                    Node* value = new Node();
                    cout << "Enter number to enqueue: ";
                    cin >> value->data;
                    queuePtr_enqueue(value);
                } else if (queueChoice == 2) {
                    queuePtr_dequeue();
                } else if (queueChoice == 3) {
                    queuePtr_display();
                } else if (queueChoice == 4) {
                    break;
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
