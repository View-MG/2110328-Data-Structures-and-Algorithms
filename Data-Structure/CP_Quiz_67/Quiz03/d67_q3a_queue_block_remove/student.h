#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    T *arr = new T[mCap]();
    int idx=0;
    for(int i{0} ; i<mSize ; i++){
        if(!(from <= i && i <= to)) arr[idx++] = mData[(mFront + i) % mCap];
    }
    int del = to - from+1;
    delete [] mData;
    mData = arr;
    mFront = 0;
    mSize -= del;
    return;
}
#endif