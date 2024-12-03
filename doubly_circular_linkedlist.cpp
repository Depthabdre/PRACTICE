#include <iostream>
using namespace std;

struct student
{
    char name[20];
    student *next;
    student *prev;
};
student *start = NULL;
student *tail = NULL;
void insertAtTheBeg(student *p)
{
    if (start == NULL) {
        start = p;
        p->next = p;
        p->prev = p;
        tail = p;
    } else {
        student *temp = start;
        p->next = start;
        p->prev = tail;
        temp->prev = p;
        start = p;
        tail->next = start;
    }
}
void insertAtTheEnd(student *p)
{
    if (start == NULL)
    {
        start = p;
      
    }
    else
    {
        student *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
        p->prev = temp;
        p->next = NULL;
      
    }
}
void insertAtAnyPosition(student *p, int pos) {
    // Handle invalid position or empty list
    if (pos < 1 || (pos > 1 && start == NULL)) {
        cout << "Invalid position or the list is empty.\n";
        return;
    }

    // Handle insertion at the start
    if (pos == 1) {
        if (start != NULL) {
            start->prev = p;
        }
        p->next = start;
        p->prev = NULL;
        start = p;
        return;
    }

    // Traverse to the node just before the desired position
    student *temp = start;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            cout << "Position out of bounds.\n";
            return;
        }
        temp = temp->next;
    }

    // Handle insertion at the end
    if (temp->next == NULL) {
        temp->next = p;
        p->prev = temp;
        p->next = NULL;
        return;
    }

    // Insert in the middle
    p->next = temp->next;        // Point new node's next to temp's next
    temp->next->prev = p;        // Update next node's prev to point to the new node
    p->prev = temp;              // Point new node's prev to temp
    temp->next = p;              // Update temp's next to the new node
}

void DeleteFirstNode()
{
    student *p = start;
    start = p->next;
    p->next->prev = NULL;
    delete p;
}
void DeleteLasttNode()
{
    student *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;
    student *q = temp->next;
    temp->next = NULL;
    q->prev = NULL;
    delete q;
}
void DeleteParticularNode(int pos) {
   
    if (pos < 1 || start == NULL) {
        cout << "Invalid position or the list is empty.\n";
        return;
    }

   // Handle deletion of the first node
    if (pos == 1) {
        student *q = start;
        start = start->next; 
        if (start != NULL) {
            start->prev = NULL; 
        }
        delete q;
        return;
    }

    // Traverse to the node just before the one to delete
    student *temp = start;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) { 
            cout << "Invalid position.\n";
            return;
        }
        temp = temp->next;
    }

    // Handle deletion of the last node
    if (temp->next->next == NULL) { 
        student *q = temp->next;
        temp->next = NULL; 
        delete q;
        return;
    }
      // Delete a middle node
    student *q = temp->next;
    temp->next = temp->next->next;          
    temp->next->prev = temp;                
    delete q;                              
}

void forWardTraverse() {
    student *temp = start;  

    if (start == NULL) {
        cout << "There is no element to display\n";
    } else {
        while (temp != NULL) { 
            cout << temp->name << " ";
            temp = temp->next; 
        }
        cout << endl; 
    }
}

void backWardTraverse() {
    student *temp = start;

    if (start == NULL) {
        cout << "There is no element to display\n";
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) { 
        cout << temp->name << " ";
        temp = temp->prev; 
    }

    cout << endl; 
}





int main() {
    int choice;
    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int insertChoice, position;
            student *newStudent = new student();
            cout << "Enter student's name: ";
            cin >> newStudent->name;

            cout << "Insert Menu\n";
            cout << "1. Insert at the beginning\n";
            cout << "2. Insert at the end\n";
            cout << "3. Insert at a particular position\n";
            cout << "Enter your choice: ";
            cin >> insertChoice;

            if (insertChoice == 1) {
                insertAtTheBeg(newStudent);
            } else if (insertChoice == 2) {
                insertAtTheEnd(newStudent);
            } else if (insertChoice == 3) {
                cout << "Enter position to insert: ";
                cin >> position;
                insertAtAnyPosition(newStudent, position);
            } else {
                cout << "Invalid insert option.\n";
            }
        }
        else if (choice == 2) {
            int deleteChoice, position;
            cout << "Delete Menu\n";
            cout << "1. Delete at the beginning\n";
            cout << "2. Delete at the end\n";
            cout << "3. Delete at a particular position\n";
            cout << "Enter your choice: ";
            cin >> deleteChoice;

            if (deleteChoice == 1) {
                DeleteFirstNode();
            } else if (deleteChoice == 2) {
                DeleteLasttNode();
            } else if (deleteChoice == 3) {
                cout << "Enter position to delete: ";
                cin >> position;
                DeleteParticularNode(position);
            } else {
                cout << "Invalid delete option.\n";
            }
        }
        else if (choice == 3) {
            cout << "List contents (Forward): ";
            forWardTraverse();
        }
        else if (choice == 4) {
            cout << "List contents (Backward): ";
            backWardTraverse();
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}