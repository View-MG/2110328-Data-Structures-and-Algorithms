#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <set>

template <typename T>
void CP::vector<T>::uniq() {
  T *arr = new T[mCap]();
  std::set<T> uniqq;
  int count=0;
  uniqq.insert(mData[0]);
  arr[count++] = mData[0];
  for(int i=0 ; i<mSize ; i++){
    if(uniqq.find(mData[i]) == uniqq.end()){
      arr[count++] = mData[i];
    }
    uniqq.insert(mData[i]);
  }
  delete [] mData;
  mData = arr;
  mSize = count;
}

#endif
