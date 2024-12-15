#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  std::vector<std::vector<T>> splitStack;
  for(int vec = 0; vec < k; vec++){
    std::vector<T> data;
    int end = mSize - vec - 1;
    int start = end % k;
    if(start >= mSize) {splitStack.push_back(data); continue;}
    for(int i = start; i <= end; i += k) { data.push_back(mData[i]); }
    splitStack.push_back(data);
  }
  return splitStack;
}

#endif