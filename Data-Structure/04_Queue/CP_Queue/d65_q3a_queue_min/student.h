#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  std::sort(pos.begin(),pos.end());
  T mins = mData[(pos[0]+mFront)%mCap];
  int idx=1;
  for(int i{1} ; i<pos.size() ; i++){
    if(pos[idx] >= mSize) return mins;
    mins = comp(mData[(pos[idx]+mFront)&mCap],mins) ? mData[(pos[idx]+mFront)&mCap] : mins ;
  }
  return mins;
}

#endif
