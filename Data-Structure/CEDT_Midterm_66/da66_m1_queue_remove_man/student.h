#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <unordered_set>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos) {
  std::unordered_set<size_t> pos_set(pos.begin(), pos.end());
  size_t new_idx = 0;

  for (size_t i = 0; i < mSize; ++i) {
    size_t current = (mFront + i) % mCap;
    if (pos_set.find(i) == pos_set.end()) {
      mData[(mFront + new_idx) % mCap] = std::move(mData[current]);
      ++new_idx;
    }
  }

  mSize -= pos.size();
  mFront = 0;
}

#endif
