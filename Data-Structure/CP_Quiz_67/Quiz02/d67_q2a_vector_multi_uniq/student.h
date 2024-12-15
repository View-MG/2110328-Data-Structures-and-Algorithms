#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include<bits/stdc++.h>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  std::vector<int> itr;
  for(auto &it : itrs){
    itr.push_back(it-this->begin());
  }
  std::map<int,bool> found;
  std::sort(itr.begin(),itr.end());
  int idx=0,index_d=0,count_del=0;
  T *arr = new T[mCap]();
  for (int i{0} ;i < mSize;i++) {
    if(idx<itr.size() && i==itr[idx]){
      if(!found[mData[i]]){
        arr[index_d++] = mData[i];
        found[mData[i]] = true;
      }else count_del++;
      idx++;
    }else arr[index_d++] = mData[i];
  }
  delete [] mData;
  mData = arr;
  mSize -=count_del;
}

#endif
