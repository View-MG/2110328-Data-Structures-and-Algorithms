#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  auto bfbIt = b.ptr->prev;
  auto bfaIt = a.ptr->prev;
  auto reverseIt = a.ptr;
  while(reverseIt != b.ptr){
    auto nextNode = reverseIt->next;
    std::swap(reverseIt->next,reverseIt->prev);
    reverseIt = nextNode;
  }
  bfaIt->next = bfbIt;
  bfbIt->prev = bfaIt;
  a.ptr->next = b.ptr;
  b.ptr->prev = a.ptr;
  return bfbIt;
  

}

#endif
