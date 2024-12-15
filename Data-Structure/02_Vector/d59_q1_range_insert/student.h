#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
    T *arr = new T[mCap + (last-first)]();
    int count=0;
    for(auto it = mData ; it != position ; it++){
        arr[count++] = *it;
    }
    for(auto it2 = first ; it2 != last ; it2++){
        arr[count++] = *(it2);
    }
    for(int i=(position-mData) ; i < mSize ; i++){
        arr[count++] = mData[i];
    }
    delete [] mData;
    mData = arr;
    mCap += (last-first);
    mSize = count;
}

#endif
