#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const{
  int i{0};
  for(int count{0} ; count<mSize%k; count++)
  {
    std::queue<T> temp;
    for(int amount{0} ; amount<(mSize/k)+1; amount++){
       temp.push(mData[(mFront+i)%mCap]); 
       i++; 
    }
    output.push_back(temp);
  }
  for(int count{0} ; count < k-(mSize%k); count++)
  {
    std::queue<T> temp;
    for(int amount{0}; amount < mSize/k; amount++){
      temp.push(mData[(mFront+i)%mCap]); 
      i++; 
      }
    output.push_back(temp);
  }
}

#endif
