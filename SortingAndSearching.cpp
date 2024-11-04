#include <iostream>
using namespace std;

// Linear Search
void LinearSearch(int arr[], int size, int key)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            cout << "Key found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Key not found." << endl;
    }
}

// Binary Search (array must be sorted before using this function)
int BinarySearch(int arr[], int size, int key)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            cout << "Key found at index " << mid << endl;
            return mid;
        }
        if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "Key not found." << endl;
    return -1;
}

void simpleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void BinaryInsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        for (int j = i - 1; j >= left; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}


void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[16] = {6, 3, 5, 6, 4, 2, 1};
    int size = 7;
    int key = 2;
    int choice;

menu:
    cout << "Main Menu \n 1. Search \n 2. Sort\n 3. Exit\n";
    cin >> choice;

    if (choice == 1)
    {
        int choice2;
        cout << "Search Menu \n 1. Linear \n 2. Binary\n 3. Back\n";
        cin >> choice2;

        if (choice2 == 1)
        {
            LinearSearch(arr, size, key);
        }
        else if (choice2 == 2)
        {
            simpleSort(arr, size); // Sort before binary search
            BinarySearch(arr, size, key);
        }
        else
        {
            goto menu;
        }
    }
    else if (choice == 2)
    {
        cout << "Sort Menu\n1. Insertion Sort\n2. Binary Insertion Sort\n3. Simple Sort\n4. Bubble Sort\n5. Selection Sort\n6. Back\n";
        cin >> choice;

        if (choice == 1)
        {
            InsertionSort(arr, size);
        }
        else if (choice == 2)
        {
            BinaryInsertionSort(arr, size);
        }
        else if (choice == 3)
        {
            simpleSort(arr, size);
        }
        else if (choice == 4)
        {
            BubbleSort(arr, size);
        }
        else if (choice == 5)
        {
            SelectionSort(arr, size);
        }
        else
        {
            goto menu;
        }
    }

    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "End of program.\n";

    return 0;
}
