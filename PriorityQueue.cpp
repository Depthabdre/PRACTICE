#include <iostream>
#include <string>
using namespace std;


struct People {
    string name;
    int age;
};

const int DefaultListSize = 10;
People queue[DefaultListSize];
int front = -1;
int rear = -1;
int queue_size = 0;

void priority_queue_enqueue(People info) {
    if (queue_size < DefaultListSize) {
        if (front == -1) { 
            front = 0;
            rear = 0;
            queue[front] = info;
            queue_size += 1;
            return;
        }

        int temp = front;
        int pos;
        bool is_found = false;

        while (!is_found) {
            if (queue[temp].age < info.age) {
                pos = temp;
                is_found = true;
            }
            if (temp == rear && !is_found) {
                is_found = true;
                pos = (temp + 1) % DefaultListSize;
            }
            temp = (temp + 1) % DefaultListSize;
        }

        temp = rear;
        while (true) {
            if (pos == ((temp + 1) % DefaultListSize)) {
                break;
            } else {
                queue[(temp + 1) % DefaultListSize] = queue[temp];
                temp = (temp + DefaultListSize - 1) % DefaultListSize;
            }
        }

        queue[pos] = info;
        rear = (rear + 1) % DefaultListSize;
        queue_size++;
    } else {
        cout << "ALERT!!!! Queue is Full!!!!\n";
    }
}

People priority_queue_dequeue() {
    if (queue_size == 0) {
        cout << "ALERT!!!! Queue is Empty!!!!\n";
        return People{"", -1};
    }
    People dequeuedValue = queue[front];
    front = (front + 1) % DefaultListSize;
    queue_size--;
    if (queue_size == 0) { 
        front = -1;
        rear = -1;
    }
    return dequeuedValue;
}

void priority_queue_display() {
    if (queue_size == 0) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Queue contents: ";
    int temp = front;
    for (int i = 0; i < queue_size; i++) { 
        cout << queue[temp].name << " ";
        temp = (temp + 1) % DefaultListSize; 
    }
    cout << endl;
}

int main() {
    int choice;
    People people;
    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. Circular Queue Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            while (true) {
                cout << "\nQueue Menu\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Back to Main Menu\n";
                cout << "Enter your choice: ";
                int queueChoice;
                cin >> queueChoice;

                if (queueChoice == 1) {
                    cout << "Enter Your Name to Enqueue: ";
                    cin >> people.name;
                    cout << "Enter Your Age: ";
                    cin >> people.age; 
                    priority_queue_enqueue(people);
                } else if (queueChoice == 2) {
                    People people_data = priority_queue_dequeue();
                    if (people_data.age != -1) {
                        cout << "The Name at Front is: " << people_data.name << "\n";
                    }
                } else if (queueChoice == 3) {
                    priority_queue_display();
                } else if (queueChoice == 4) {
                    break;
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
