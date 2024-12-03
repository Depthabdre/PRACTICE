#include <iostream>
using namespace std;

// Linked list node structure
struct Node {
    int data;
    Node* next;
};


Node* topPtr = nullptr; // its is head pointer points to the top of stack whoch is found in the first elemnt in the stack

// Linked list-based stack functions
void topPtr_push(int num) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = topPtr; // element always add to the first or head pointer
    topPtr = newNode;
    cout << "Pushed: " << num << " (topPtr)\n";
}

int topPtr_pop() {
    if (topPtr == nullptr) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return 0;
    }
    Node* temp = topPtr;
    // cout << "Popped: " << topPtr->data << " (topPtr)\n";
    int pop_ele = topPtr->data;
    topPtr = topPtr->next;
    delete temp;
    return pop_ele;
}

void topPtr_display() {
    if (topPtr == nullptr) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return;
    }
    Node* temp = topPtr;
    cout << "topPtr elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void topPtr_peek() {
    if (topPtr == nullptr) {
        cout << "ALERT!!!! Stack is Empty!!!!\n";
        return;
    }
    cout << "Top element: " << topPtr->data << " (topPtr)\n";
}
void Check_Palidrome(){
    int arr[5];
    cout<<"Enter Number: ";
    for(int i =0;i<5;i++){
        cin>>arr[i];
        topPtr_push(arr[i]);
    }
    for(int i =0;i<5;i++){
        if(arr[i] == topPtr_pop())
        continue;
        else{
            cout<<"The Number Is Not Palindrome";
            return;
        }
    }
    cout<<"The NUmber is Palindrome\n";
}



int main() {
    int choice;
    while (true) {
        cout << "\nStack Applications Menu\n";
        cout << "1. Check Palindrome\n";
        cout << "2. Convert Decimal to Binary\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Infix to Post fix Converter\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Number to check for palindrome: ";
            Check_Palidrome();
            // Call your palindrome check function here
        } else if (choice == 2) {
            cout << "Enter decimal number to convert to binary: ";
            // Call your decimal-to-binary function here
        } else if (choice == 3) {
            cout << "Enter postfix expression to evaluate: ";
            // Call your postfix evaluation function here
        } else if (choice == 4) {
            cout << "Enter infix expression to evaluate: ";
            // Call your infix evaluation function here
        } else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

