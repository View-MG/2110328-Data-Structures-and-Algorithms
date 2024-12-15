#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<bits/stdc++.h>
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
    sort(data.begin(),data.end());
    T *arr = new T[mCap+data[data.size()-1].first];
    int count{0},idx{0};
    for(int i=0 ; i<mSize ; i++){
      if(i == data[idx].first){
        arr[count++] = data[idx++].second;
        arr[count++] = mData[i];
      }else arr[count++] = mData[i];
    }
    while(idx != data.size()){
      arr[count++] = data[idx++].second;
    }
    delete [] mData;
    mData = arr;
    mSize = count;
} 

#endif
