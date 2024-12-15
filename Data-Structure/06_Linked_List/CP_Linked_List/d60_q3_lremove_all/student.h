#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  auto it = mHeader->next;
  while(it != mHeader){
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
}


#endif
