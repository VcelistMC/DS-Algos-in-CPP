#include "Sorts.h"
#include <iostream>
using namespace std;

void Sorts::printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void Sorts::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Sorts::insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int k = i;
        for(; k > 0 && temp < arr[k-1]; k--)
            arr[k] = arr[k-1];
        arr[k] = temp;
    }
    printArr(arr, n);
};

void Sorts::selectionSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int minPos = i;
        for(int k = minPos; k < n; k++)
            minPos = arr[minPos] > arr[k]? k : minPos;
        swap(arr[minPos], arr[i]);
    }
    printArr(arr, n);
}

void Sorts::bubbleSort(int arr[], int n)
{
    bool swapped;
    do
    {
        swapped = false;
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
    printArr(arr, n);
}

void Sorts::merge(int arr[], int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int leftAuxArr[leftSize];
    int rightAuxArr[rightSize];
    
    for(int i = 0; i < leftSize; i++)
        leftAuxArr[i] = arr[left + i];
    for(int i = 0; i < rightSize; i++)
        rightAuxArr[i] = arr[middle + i + 1];

    int i = 0, j = 0, k = left;
    while(i < leftSize && j < rightSize)
    {
        if(leftAuxArr[i] < rightAuxArr[j])
        {
            arr[k] = leftAuxArr[i];
            i++;
        }
        else
        {
            arr[k] = rightAuxArr[j];
            j++;
        }
        k++;
    }

    while(i < leftSize)
        arr[k++] = leftAuxArr[i++];
    while(j < rightSize)
        arr[k++] = rightAuxArr[j++];
}

void Sorts::mergeSort(int arr[], int left, int right)
{
    if(left >= right)
        return;
    int middle = (right + left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

void Sorts::mergeSort(int arr[], int n)
{
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
}

void Sorts::shellSort(int arr[], int n)
{
    for(int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && temp < arr[j-gap]; j-= gap)
                arr[j] = arr[j - gap];
        arr[j] = temp;
        }
    }
    printArr(arr, n);
}

void Sorts::quickSort(int arr[], int n)
{
    quickSort(arr, 0, n-1);
    printArr(arr, n);
}

int Sorts::partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[right]);
    return (i + 1);
}

void Sorts::quickSort(int arr[], int left, int right)
{
    if(left >= right)
        return;
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}

void Sorts::heapSort(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, i, n);
    
    for(int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
    printArr(arr, n);
}

void Sorts::heapify(int arr[], int node, int n)
{
    int largest = node;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    if(leftChild < n && arr[largest] < arr[leftChild] )
        largest = leftChild;
    if(rightChild < n && arr[largest] < arr[rightChild])
        largest = rightChild;
    
    if(node != largest)
    {
        swap(arr[node], arr[largest]);
        heapify(arr, largest, n);
    }
}

void Sorts::countingSort(int arr[], int n)
{
    int maxPos = 0;
    for(int i = 0; i < n; i++)
        maxPos = arr[maxPos] < arr[i] ? i : maxPos;

    int count[arr[maxPos] + 1];
    
}