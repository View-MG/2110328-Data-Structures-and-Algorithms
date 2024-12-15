#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(m==0) return false;
  if(a<this->begin() || a>= this->end() || b<this->begin() || b >=this->end()) return false;
  if(a+m-1 > this->end() || b+m-1 > this->end()) return false;
  if(!(a+m-1 < b || b+m-1 < a)) return false;
  else{
      for(int i{0} ; i<m ; i++){
        std::swap(*(a+i),*(b+i));
      }
      return true;
    }
    return false;
}

#endif
