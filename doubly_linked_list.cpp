#include <iostream>
using namespace std;

struct student
{
    char name[20];
    student *next;
    student *prev;
};
student *start = NULL;
void insertAtTheBeg(student *p)
{
    if (start == NULL) {
        start = p;
        p->next = NULL;
        p->prev = NULL;
    } else {
        student *temp = start;
        p->next = start;
        p->prev = NULL;
        temp->prev = p;
        start = p;
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
void insertAtAnyPosition(student *p, int pos)
{
    student *temp = start;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    student *q = temp;
    p->next = temp->next;
    temp->next->prev = p;
    p->prev = q;
    q->next = p;
    
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
void DeleteParticularNode(int pos)
{
    student *temp = start;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    student *q = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;
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