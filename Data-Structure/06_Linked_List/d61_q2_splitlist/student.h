#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>
#include "list.h"

template <typename T>
void splitList(list<T>& list1, list<T>& list2) {
    auto it = begin();
    int mid = mSize%2==0 ? mSize/2 : mSize/2+1;
    for(int i{0} ; i<mid ; i++) it++;

    auto lastoldList1 = list1.mHeader->prev;
    lastoldList1->next = mHeader->next;
    list1.mHeader->prev = it.ptr->prev;
    it.ptr->prev->next = list1.mHeader;
    begin().ptr->prev = lastoldList1 ;

    auto lastoldList2 = list2.mHeader->prev;
    lastoldList2->next = it.ptr;
    it.ptr->prev = lastoldList2;
    list2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = list2.mHeader;

    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    list1.mSize = mid;
    list2.mSize = mSize-mid;
    mSize=0;
}
#endif
