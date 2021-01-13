#ifndef SORT
#define SORT

#include "sortadt.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>class Sort: public SortADT<T>{
private:

public:
    Sort(){
    }
    ~Sort(){

    }
    void show(T* array, int size){
        for (int i = 0; i <size; ++i) {
            cout<<"["<<array[i]<<"]"<<" ";
        }
        cout<<endl;
    }
    T* bubbleSort(T* array,int size){
        for(int i=size-1; i >= 1; i--) {

            for( int j=0; j < i ; j++) {

                if(array[j]>array[j+1])
                    std::swap(array[j], array[j + 1]);
            }
        }
        return array;
    }
    T* insSort(T* array,int size){
        for (int i = 1; i < size; ++i)
            for (int j = i; (j>0) && (array[j]<array[j-1]) ; j--)
                std::swap(array[j], array[j - 1]);
        return array;
    }
    T* selSort(T* array,int size){
        for (int i = 0; i < size-1; ++i) {
            int low = i;
            for (int j = size-1; j > i; --j)
                if(array[j]<array[low])
                    low = j;
            std::swap(array[i], array[low]);
        }
        return array;
    }
    void merge(T A[], T temp[], int left, int right) {
        if (left == right) return;
        int mid = (left+right)/2;
        merge(A, temp, left, mid);
        merge(A, temp, mid+1, right);
        for (int i=left; i<=right; i++)
            temp[i] = A[i];

        int i1 = left; int i2 = mid + 1;
        for (int curr=left; curr<=right; curr++) {
            if (i1 == mid+1)
                A[curr] = temp[i2++];
            else if (i2 > right)
                A[curr] = temp[i1++];
            else if (temp[i1]<temp[i2])
                A[curr] = temp[i1++];
            else A[curr] = temp[i2++];
        }
    }
    T* mergeSort(T* array, int size) {
        static T* temp = NULL;
        if (temp == NULL) temp = new T[size];
        merge(array, temp, 0, size-1);
        return array;
    }

    void inssort2(T A[], int n, int incr) {
        for (int i=incr; i<n; i+=incr)
            for (int j=i; (j>=incr) &&(A[j] < A[j-incr]); j-=incr)
                std::swap(A[j], A[j-incr]);
    }
    void shell(T A[], int n) {
        for (int i=n/2; i>2; i/=2)
            for (int j=0; j<i; j++)
                inssort2(&A[j], n-j, i);
        inssort2(A, n, 1);
    }
    T* shellSort(T* array, int n) {
        shell(array, n);
        return array;
    }
};

#endif // SORT

