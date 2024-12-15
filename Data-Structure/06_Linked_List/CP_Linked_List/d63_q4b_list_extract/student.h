#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  auto it = a;
  while(it != b){
    if(it->data == value){
      auto deleteIt = it;
      it = it->next;
      deleteIt->prev->next = deleteIt->next;
      deleteIt->next->prev = deleteIt->prev;
      delete deleteIt;
      mSize--;
    }else{
      it = it->next;
    }
  }
  return output;
}


#endif


}

#endif
