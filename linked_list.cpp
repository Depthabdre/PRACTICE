#include <iostream>
using namespace std;

struct student
{
    char name[20];
    student *next;
};
student *start = NULL;
void insertAtTheBeg(student *p)
{
    if (start == NULL) 
    {
        start = p;
        p->next = NULL;
    }
    else
    {
        p->next = start; 
        start = p;       
    }
}

void insertAtTheEnd(student *p)
{
    if (start = NULL)
    {
        start = p;
      
    }
    else
    {
        student *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
      
    }
}
void insertAtAnyPosition(student *p, int pos)
{
    student *temp = start;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    p->next = temp->next;
    temp = p;
}
void DeleteFirstNode()
{
    student *p = start;
    start = p->next;
    delete p;
}
void DeleteLasttNode()
{
    student *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;
    student *q = temp;
    q = q->next;
    temp->next = NULL;
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
    delete q;
}
void forWardTraverse()
{
    student *temp = start;
    if (start == NULL)
    cout<<" There is no element to display\n";
    else{
    cout << temp->name << " ";
    while (temp->next != NULL)
    {
        cout << temp->name << " ";
        temp = temp->next;
    }
    }
    cout << endl;
}
void backWardTraverse()
{
    student *temp = start;
    int cur = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        cur += 1;
    }
    for (int i = 1; i <= cur; i++)
    {
        student *q = start;
        for (int j = i + 2; j <= cur; j++)
        {
            q = q->next;
        }
        cout<<temp->name<<" ";
        temp=q;
    }
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