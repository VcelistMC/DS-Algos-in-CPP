#ifndef SORTS_H
#define SORTS_H

class Sorts
{
    public:
        //quad sorts
        static void insertionSort(int arr[], int n);
        static void selectionSort(int arr[], int n);
        static void bubbleSort(int arr[], int n);

        //non-comparison sorts
        static void countingSort(int arr[], int n);
        static void radixSort(int arr[], int n);

        //sub-quad sorts
        static void shellSort(int arr[], int n);
        static void mergeSort(int arr[], int n);
        static void quickSort(int arr[], int n);
        static void heapSort(int arr[], int n);
        
        //helper functions
        static void mergeSort(int arr[], int left, int right);
        static void quickSort(int arr[], int left, int high);
        static void swap(int &a, int &b);
        static void merge(int arr[], int left, int middle, int right);
        static void printArr(int arr[], int n);
        static int partition(int arr[], int left, int right);
        static void heapify(int arr[], int node, int n);
};
#endif
