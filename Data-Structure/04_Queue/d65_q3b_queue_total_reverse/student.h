#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

void CP::queue<T>::reverse() {
  if(aux == 0){
    mFront = (mFront + mSize - 1) % mCap;
    aux = 1;
  }else if(aux == 1){
    mFront = (mFront - mSize + 1 + mCap) % mCap;
    aux = 0;
  }
}
const T& CP::queue<T>::front() const {
  return mData[mFront];
}
const T& CP::queue<T>::back() const {
  return mData[((aux == 0) ? (mFront + mSize - 1) : (mFront - mSize + 1 + mCap)) % mCap];
}
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize + 1);
  mData[((aux == 0) ? (mFront + mSize) : (mFront - mSize + mCap)) % mCap] = element;
  mSize++;
}
void CP::queue<T>::pop() {
  mFront = ((aux == 0) ? (mFront + 1) : (mFront - 1 + mCap)) % mCap;
  mSize--;
}

#endif