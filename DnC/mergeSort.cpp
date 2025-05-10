#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted halves into a sorted array
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid;    // size of right subarray

    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy any remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return; // base case

    int mid = left + (right - left) / 2;

    // Divide
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Conquer (merge)
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
