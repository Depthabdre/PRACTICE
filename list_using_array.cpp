#include <iostream>
using namespace std;

const int DefaultListSize = 10;

class AList
{
private:
    int maxSize;
    int listSize;
    int curr;
    int *listArray;

public:
    AList(int size = DefaultListSize)
    {
        maxSize = size;
        listSize = curr = 0;
        listArray = new int[maxSize];
    }

    ~AList() { delete[] listArray; }

    void clear()
    {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new int[maxSize];
    }

    void setStart() { curr = 0; }

    void setEnd() { curr = listSize; }

    void prev()
    {
        if (curr != 0)
            curr--;
    }

    void next()
    {
        if (curr < listSize)
            curr++;
    }

    int length() { return listSize; }

    bool setPos(int pos)
    {
        if ((pos >= 0) && (pos <= listSize))
        {
            curr = pos;
            return true;
        }
        return false;
    }

    void getValue(int position)
    {
        if (listSize < position)
            cout<<" there is no value at this position \n";
        else{
            cout<<"The value at index "<<position<<" is "<<listArray[position];
        }
        
    }

    bool insertAtPosition(int value, int position)
    {
        if (listSize == maxSize)
            return false;
        for (int i = listSize; i > position; i--)
            listArray[i] = listArray[i - 1];
        listArray[position] = value;
        listSize++;
        return true;
    }
    bool insertAtBeginning(int &value)
    {
        if (listSize == maxSize)
            return false;
        else
        {
            for (int i = listSize - 1; i >= 0; i--)
            {
                listArray[i + 1] = listArray[i];
            }
            listArray[0] = value;
        }
        return true;
    }

    bool insertAtEnd(int item)
    {
        if (listSize == maxSize)
            return false;
        listArray[listSize++] = item;
        return true;
    }

    bool deleteAtBeginning()
    {
        if (listSize == 0)
            return false;
        for (int i = 0; i < listSize - 1; i++)
            listArray[i] = listArray[i + 1];
        listSize--;
        return true;
    }
    bool deleteAtEnd()
    {
        if (listSize == 0)
            return false;
        else
        {
            listSize--;
        }
        return true;
    }
    bool deleteAtPosition(int position)
    {
        if (listSize == 0)
            return false;
        else{
            for (int i = position; i < listSize;i++){
                listArray[i] = listArray[i+1];
            }
            listSize--;
        }
        return true;
    }
    void display(){
        for(int i =0 ; i < listSize;i++){
            cout<<listArray[i]<<", ";
        }
    }
};

int main()
{
    AList myList;
    int choice;
    while (true)
    {
        cout << "Main Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Get Value\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int insertChoice, value, position;
            cout << "Insert Menu\n";
            cout << "1. Insert at the beginning\n";
            cout << "2. Insert at the end\n";
            cout << "3. Insert at a particular position\n";
            cout << "Enter your choice: ";
            cin >> insertChoice;

            cout << "Enter value to insert: ";
            cin >> value;

            if (insertChoice == 1)
            {
                bool temp = myList.insertAtBeginning(value);
            }
            else if (insertChoice == 2)
            {
                bool temp = myList.insertAtEnd(value);
            }
            else if (insertChoice == 3)
            {
                cout << "Enter position to insert: ";
                cin >> position;
                bool temp = myList.insertAtPosition(value, position);
            }
            else
            {
                cout << "Invalid insert option.\n";
            }
        }
        else if (choice == 2)
        {
            int deleteChoice, position;
            cout << "Delete Menu\n";
            cout << "1. Delete at the beginning\n";
            cout << "2. Delete at the end\n";
            cout << "3. Delete at a particular position\n";
            cout << "Enter your choice: ";
            cin >> deleteChoice;

            if (deleteChoice == 1)
            {
                bool temp = myList.deleteAtBeginning();
            }
            else if (deleteChoice == 2)
            {
                bool temp = myList.deleteAtEnd();
            }
            else if (deleteChoice == 3)
            {
                cout << "Enter position to delete: ";
                cin >> position;
                bool temp = myList.deleteAtPosition(position);
            }
            else
            {
                cout << "Invalid delete option.\n";
            }
        }
        else if (choice == 3)
        {
            int position;
            cout << "Enter position to get value: ";
            cin >> position;
            myList.getValue(position);
        }
        else if (choice == 4)
        {
            myList.display();
        }
        else if (choice == 5)
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}


