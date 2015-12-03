
//
// Zübeyr Furkan Eryilmaz
// 21202676
// CS 202 - 01
// Assignment 3
//

#include "heap.h"

heap::heap(){
    // Creates a heap that can take maximum 100 elements and makes initializations
    heapArr = new int[100];
    maxNumberOfElements = 100;
    numberOfComparisons = 0;
    free = 0;

}
heap::heap( int numberOfElements){
    // Creates a heap that can take maximum specified number of elements and makes initializations
    maxNumberOfElements = numberOfElements;
    heapArr = new int[maxNumberOfElements];
    numberOfComparisons = 0;
    free = 0;
}

heap::~heap(){
    //Destroys the heap(array)
    delete heapArr;

}

void heap::insert(const int a){ // O(logn)
    // Inserts given integer to the heap and rebuild the heap to make it maxheap

    if ( free == maxNumberOfElements)
        return;

    heapArr[free] = a;

    //Rebuild part
    int parent = (free - 1)/ 2;

    int child = free;

    //
    while ( parent >= 0 && heapArr[parent] < heapArr[child]){ // O(logn)

        swap(heapArr[parent],heapArr[child]);

        child = parent;
        parent = (parent-1)/2;

        numberOfComparisons++;

    }

    free ++;

}

int heap::maximum(){
    // Returns the element that has maximum value
    if ( free == 0)
    {
        return -1;
    }

    return heapArr[0];

}

int heap::popMaximum(){ // O(logn)

    // Returns and deletes maximum value and rebuild the heap to make it maxheap
    if (free == 0)
    {
        return -1;
    }

    int max = maximum();

    free--;

    heapArr[0] = heapArr[free];

    //Rebuild part
    int parent = 0;
    int child = 2*parent + 1;
    int rightChild;

    while( child < free) // O(logn)
    {
        rightChild = child + 1;

        if ( rightChild < free && heapArr[rightChild] > heapArr[child])
            child = rightChild;

        if ( heapArr[child] > heapArr[parent])
            swap(heapArr[child], heapArr[parent]);

        numberOfComparisons += 2;

        parent = child;
        child = 2*parent+1;

    }

    return max;

}

int heap::getComparisons(){
    // Returns number of comparisons
    return numberOfComparisons;

}

void heap::swap(int &a, int &b){
    //Swaps a and b
    int temp = a;
    a = b;
    b = temp;

}
