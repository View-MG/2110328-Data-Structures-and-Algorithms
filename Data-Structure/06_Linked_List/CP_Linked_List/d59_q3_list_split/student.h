#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  CP::list<T> result;
  auto LastElement = mHeader->prev;
  it.ptr->prev->next = mHeader;
  mHeader->prev = it.ptr->prev;
  result.mHeader->next = it.ptr;
  LastElement->next = result.mHeader;
  result.mHeader->prev = LastElement;
  it.ptr->prev = result.mHeader;
  result.mSize = mSize-pos;
  mSize -= pos;
  return result;
}

#endif
