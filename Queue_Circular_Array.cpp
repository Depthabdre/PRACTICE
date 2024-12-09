#include <iostream>
using namespace std;

// Constants for array operation on queue
const int DefaultListSize = 10;
int queue_size = 0;
int queue[DefaultListSize];
int front = -1;
int rear = -1;

// Circular queue enqueue function
void queue_array_enqueue(int num) {
    if (queue_size < DefaultListSize) {
        rear = (rear + 1) % DefaultListSize; 
        queue[rear] = num;
        if (front == -1) { 
            front = 0;
        }
        queue_size++;
        cout << "Enqueued " << num << " successfully.\n";
    } else {
        cout << "ALERT!!!! Queue is Full!!!!\n";
    }
}

// Circular queue dequeue function
int queue_array_dequeue() {
    if (queue_size == 0) {
        cout << "ALERT!!!! Queue is Empty!!!!\n";
        return -1;
    }
    int dequeuedValue = queue[front];
    front = (front + 1) % DefaultListSize;
    queue_size--;
    if (queue_size == 0) { 
        front = -1;
        rear = -1;
    }
    return dequeuedValue;
}


void queue_array_display() {
    if (queue_size == 0) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Queue contents: ";
    int temp = front;
    for (int i = 0; i < queue_size; i++) { 
        cout << queue[temp] << " ";
        temp = (temp + 1) % DefaultListSize; 
    }
    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. Circular_queue Operations\n";
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
                        cout << "The Number at Front is: " << num << "\n";
                    }
                } else if (queueChoice == 3) {
                    queue_array_display();
                } else if (queueChoice == 4) {
                    break;
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } else if (choice == 3){
            break
        }
    }
}
