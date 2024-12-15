#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::map<T,int> count;
    for(int i{0} ; i<this->mSize ; i++){
        count[mData[(mFront+i)%mCap]]++;
    }
    std::vector<std::pair<T,size_t>> result;
    for(auto &v : k){
        result.push_back({v,count[v]});
    }
    return result;
}

#endif
