#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::find(T k) const {
  for(int i{0} ; i<mSize ; i++){
    if(mData[i] == k) return true;
  }
  return false;
}

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::find_level(T k) const {
  for(int i{mSize-1} ; i>=0 ; i--){
    if(mData[i] == k){
      int level{0};
      while(i>0){ 
        i = (i-1)/2; 
        level++; 
      }
      return level;
    }
  }
  return -1;
}

#endif

