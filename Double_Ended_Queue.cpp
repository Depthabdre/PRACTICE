#include <iostream>
using namespace std;

// Constants for deque operations
const int DefaultListSize = 10;
int deque[DefaultListSize];
int front = -1;
int rear = -1;
int deque_size = 0;

// Function to check if the deque is full
bool isFull() {
    return deque_size == DefaultListSize;
}

// Function to check if the deque is empty
bool isEmpty() {
    return deque_size == 0;
}

// Enqueue at the front
void EnqueueFront(int num) {
    if (isFull()) {
        cout << "ALERT!!!! Deque is Full!!!!\n";
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else {
        front = (front + DefaultListSize - 1) % DefaultListSize; // Move front backward circularly
    }
    deque[front] = num;
    deque_size++;
    cout << "Enqueued " << num << " at the front successfully.\n";
}

// Enqueue at the rear
void EnqueueRear(int num) {
    if (isFull()) {
        cout << "ALERT!!!! Deque is Full!!!!\n";
        return;
    }
    if (rear == -1) { // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % DefaultListSize; // Move rear forward circularly
    }
    deque[rear] = num;
    deque_size++;
    cout << "Enqueued " << num << " at the rear successfully.\n";
}

// Dequeue from the front
int DequeueFront() {
    if (isEmpty()) {
        cout << "ALERT!!!! Deque is Empty!!!!\n";
        return -1;
    }
    int dequeuedValue = deque[front];
    front = (front + 1) % DefaultListSize; // Move front forward circularly
    deque_size--;
    if (deque_size == 0) { // Reset pointers if deque becomes empty
        front = rear = -1;
    }
    return dequeuedValue;
}

// Dequeue from the rear
int DequeueRear() {
    if (isEmpty()) {
        cout << "ALERT!!!! Deque is Empty!!!!\n";
        return -1;
    }
    int dequeuedValue = deque[rear];
    rear = (rear + DefaultListSize - 1) % DefaultListSize; // Move rear backward circularly
    deque_size--;
    if (deque_size == 0) { // Reset pointers if deque becomes empty
        front = rear = -1;
    }
    return dequeuedValue;
}

// Display the contents of the deque
void DisplayDeque() {
    if (isEmpty()) {
        cout << "Deque is Empty!\n";
        return;
    }
    cout << "Deque contents: ";
    int temp = front;
    for (int i = 0; i < deque_size; i++) {
        cout << deque[temp] << " ";
        temp = (temp + 1) % DefaultListSize; // Move forward circularly
    }
    cout << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. Enqueue Front\n";
        cout << "2. Enqueue Rear\n";
        cout << "3. Dequeue Front\n";
        cout << "4. Dequeue Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int num;
        switch (choice) {
            case 1:
                cout << "Enter number to enqueue at the front: ";
                cin >> num;
                EnqueueFront(num);
                break;
            case 2:
                cout << "Enter number to enqueue at the rear: ";
                cin >> num;
                EnqueueRear(num);
                break;
            case 3:
                num = DequeueFront();
                if (num != -1) {
                    cout << "The Number dequeued from the front is: " << num << "\n";
                }
                break;
            case 4:
                num = DequeueRear();
                if (num != -1) {
                    cout << "The Number dequeued from the rear is: " << num << "\n";
                }
                break;
            case 5:
                DisplayDeque();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
