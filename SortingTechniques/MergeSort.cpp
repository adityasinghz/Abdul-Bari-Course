#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int n, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[n];
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
            B[k++] = arr[j++];
        else
            B[k++] = arr[i++];
    }
    while (i <= mid)
        B[k++] = arr[i++];
    while (j <= high)
        B[k++] = arr[j++];

    for (int l = low; l <= high; l++)
        arr[l] = B[l];
}

void MergeSort(int arr[], int n, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(arr, n, low, mid);
        MergeSort(arr, n, mid + 1, high);
        Merge(arr, n, low, mid, high);
    }
}

int main()
{
    int n = 10;
    int arr[n]{32, 65, 11, 22, 34, 5, 6, 1, 2, 0};
    MergeSort(arr, n, 0, n - 1);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
}