#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  int m = mSize > 7 ? 7 : mSize;
  std::vector<T> v(mData,mData+m);
  std::sort(v.begin(),v.end(),mLess);
  return v[v.size()-k];
}

#endif

