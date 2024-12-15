#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	if(p>mSize/2){
		T *arr = new T[mCap*2]();
		int n=mSize,idx=0;
		for (int i{0} ; i<p ; i++){
			arr[idx++] = mData[(mFront+i)%mCap];
		}
		for(int i{0} ; i<m ; i++){
			arr[idx++] = element;
		}
		for(int i{p} ; i<n ; i++){
			arr[idx++] = mData[(mFront+i)%mCap];
		}
		
		delete [] mData;
		mData = arr;
		mSize = idx;
		mFront =0;
	}else{
		
	}
	
}

#endif
