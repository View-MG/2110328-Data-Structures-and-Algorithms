#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	if(first >= last) return;
	int n = last > mSize ? mSize : last;
	for(int i{first} ; i<n ; i++)

}

#endif
