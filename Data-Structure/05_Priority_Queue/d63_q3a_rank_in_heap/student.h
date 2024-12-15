#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  int count{0};
  for(int i{0} ; i<mSize ; i++){
    if(mLess(mData[pos],mData[i])) {
      count++;
    }
  }
  return count;
}

#endif
