#ifndef _CP_LIST_INCLUDED_
#define _CP_LIST_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP { 

template <typename T>
class list
{
  protected:
    class node {
      friend class list;
      public:
        T data;
        node *prev;
        node *next;

        node() :
          data( T() ), prev( this ), next( this ) { }

        node(const T& data,node* prev, node* next) :
          data ( T(data) ), prev( prev ), next( next ) { }
    };

    class list_iterator {
      friend class list;
      protected:
        node* ptr;
      public:

        list_iterator() : ptr( NULL ) { }

        list_iterator(node *a) : ptr(a) { }

        list_iterator& operator++() { 
          ptr = ptr->next; 
          return (*this);
        }

        list_iterator& operator--() { 
          ptr = ptr->prev; 
          return (*this);
        }

        list_iterator operator++(int) {
          list_iterator tmp(*this);
          operator++();
          return tmp;

        }
        list_iterator operator--(int) {
          list_iterator tmp(*this);
          operator--();
          return tmp;
        }

        T& operator*() { return ptr->data; }
        T* operator->() { return &(ptr->data); }
        bool operator==(const list_iterator& other) const { return other.ptr == ptr; }
        bool operator!=(const list_iterator& other) const { return other.ptr != ptr; }
    };

  public:
    typedef list_iterator iterator;

  protected:
    node *mHeader; // pointer to a header node
    size_t mSize;


  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    list(const list<T>& a) :
      mHeader( new node() ), mSize( 0 ) {
      for (auto it = a.begin();it != a.end();it++) {
        push_back(*it);
      }
    }

    // default constructor
    list() :
      mHeader( new node() ), mSize( 0 ) { }

    // copy assignment operator using copy-and-swap idiom
    list<T>& operator=(list<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mHeader, other.mHeader);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~list() {
      clear();
      delete mHeader;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }


    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mHeader->next);
    }

    iterator end() {
      return iterator(mHeader);
    }

    iterator begin() const {
      return iterator(mHeader->next);
    }

    iterator end() const {
      return iterator(mHeader);
    }
    //----------------- access -----------------
    T& front() { return mHeader->next->data; }

    T& back() { return mHeader->prev->data; }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void push_front(const T& element) {
      insert(begin(),element);
    }

    void pop_back() {
      erase(iterator(mHeader->prev));
    }

    void pop_front() {
      erase(begin());
    }

    iterator insert(iterator it,const T& element) {
      node *n = new node(element,it.ptr->prev, it.ptr);
      it.ptr->prev->next = n;
      it.ptr->prev = n;
      mSize++;
      return iterator(n);
    }

    iterator erase(iterator it) {
      iterator tmp(it.ptr->next);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
      return tmp;
    }

    void clear() {
      while (mSize > 0) erase(begin());
    }

    void print() {
      std::cout << "Size = " << mSize << "\n";
      std::cout << "From FRONT to BACK: ";
      for (auto it = begin();it!=end();it++) {
        std::cout << *it << " ";
      }
      std::cout << std::endl << "From BACK to FRONT: ";
      auto it = end();
      while (it != begin()) {
        --it;
        std::cout << *it << " ";
      }
      std::cout << "\n";
    }
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

};

}

#endif


