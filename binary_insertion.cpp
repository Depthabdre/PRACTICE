#include <iostream>
using namespace std;
void binary_insertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int left = 0, right = i - 1;
        int key = arr[i];

        // Perform binary search to find the correct insertion point
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (arr[middle] > key)
                right = middle - 1;
            else
                left = middle + 1;
        }

        // Shift elements to the right to make room for `key`
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        // Insert `key` at the correct position
        arr[left] = key;
    }
}

int main(){
    int arr[12] = {3, 1, 32, 1, 2, 3, 42, 4, 2, 3, 2, 2};
    int n = 12;
    binary_insertion(arr,12);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<",";
    }


}