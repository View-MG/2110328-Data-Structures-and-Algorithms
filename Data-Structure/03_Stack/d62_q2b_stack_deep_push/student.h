#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  expand(mCap+10);
      for (int i{0} ; i < pos ; i++) {
        mData[mSize-i] = mData[mSize-i-1];
      }
      mData[mSize-pos] = value;
      mSize++;
}

#endif
