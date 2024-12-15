#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  int k = K>=k ? mSize : K;
  T *arr = new T[mCap]();
      for (size_t i=0 ; i<k ; i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mSize -=k;
}
template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  std::stack<T> result;
  int n=mSize;
  int k = K>=k ? mSize : K;
  for(int i{n-k} ; i<mSize ; i++){
    result.push(mData[i]);
  }
  mSize -=k;
  return result;
}

#endif
