#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    T *arr = new T[mCap]();
    int count=0,check=0;
    for(int i=0 ; i<mSize ; i++){
      if(check != pos.size() && i == pos[check]) check++;
      else arr[count++] = mData[i];
    }
    delete [] mData;
    mData = arr;
    mSize = count;
}

#endif
