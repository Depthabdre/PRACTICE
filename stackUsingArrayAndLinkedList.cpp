#include <iostream>
using namespace std;

// Linked list node structure
struct Node {
    int data;
    Node* next;
};

// Array stack global variables
const int DefaultListSize = 10;
int stack_size = 0;
int top = -1;
int stack_array[DefaultListSize];

// Array-based stack functions
void stack_array_push(int num) {
    if (stack_size >= DefaultListSize) {
        cout << "ALERT!!!! Stack is Full!!!!\n";
    } else {
        stack_array[++top] = num;
        stack_size++;
        cout << "Pushed: " << num << " (stack_array)\n";
    }
}

int stack_array_pop() {
    if (stack_size <= 0) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return -1;
    } else {
        int pop_ele = stack_array[top--];
        stack_size--;
        cout << "Popped: " << pop_ele << " (stack_array)\n";
        return pop_ele;
    }
}

void stack_array_display() {
    if (stack_size <= 0) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return;
    }
    cout << "stack_array elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack_array[i] << " ";
    }
    cout << "\n";
}

int stack_array_peek() {
    if (stack_size <= 0) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return -1;
    } else {
        cout << "Top element: " << stack_array[top] << " (stack_array)\n";
        return stack_array[top];
    }
}

// Linked list stack global pointer
Node* stack_linked_list = nullptr;

// Linked list-based stack functions
void stack_linked_list_push(int num) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = stack_linked_list;
    stack_linked_list = newNode;
    cout << "Pushed: " << num << " (stack_linked_list)\n";
}

void stack_linked_list_pop() {
    if (stack_linked_list == nullptr) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return;
    }
    Node* temp = stack_linked_list;
    cout << "Popped: " << stack_linked_list->data << " (stack_linked_list)\n";
    stack_linked_list = stack_linked_list->next;
    delete temp;
}

void stack_linked_list_display() {
    if (stack_linked_list == nullptr) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return;
    }
    Node* temp = stack_linked_list;
    cout << "stack_linked_list elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void stack_linked_list_peek() {
    if (stack_linked_list == nullptr) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return;
    }
    cout << "Top element: " << stack_linked_list->data << " (stack_linked_list)\n";
}

// Main menu
int main() {
    int choice;
    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. stack_array Operations\n";
        cout << "2. stack_linked_list Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            while (true) {
                cout << "\nstack_array Menu\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Peek\n";
                cout << "4. Display\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                int stackChoice, num;
                cin >> stackChoice;

                if (stackChoice == 1) {
                    cout << "Enter number to push: ";
                    cin >> num;
                    stack_array_push(num);
                } else if (stackChoice == 2) {
                    stack_array_pop();
                } else if (stackChoice == 3) {
                    stack_array_peek();
                } else if (stackChoice == 4) {
                    stack_array_display();
                } else if (stackChoice == 5) {
                    break;
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } else if (choice == 2) {
            while (true) {
                cout << "\nstack_linked_list Menu\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Peek\n";
                cout << "4. Display\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                int stackChoice, num;
                cin >> stackChoice;

                if (stackChoice == 1) {
                    cout << "Enter number to push: ";
                    cin >> num;
                    stack_linked_list_push(num);
                } else if (stackChoice == 2) {
                    stack_linked_list_pop();
                } else if (stackChoice == 3) {
                    stack_linked_list_peek();
                } else if (stackChoice == 4) {
                    stack_linked_list_display();
                } else if (stackChoice == 5) {
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