#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <cmath>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  if(mSize == 0) return -1;
  if(mSize == 1) return 0;
  int idx{1},count{0};
  while(idx<mSize){
    count++;
    idx += (pow(2,count));
  }
  return count;
}

#endif

