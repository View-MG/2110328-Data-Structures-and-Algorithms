#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,typename MappedT,typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  CP::map_bst<KeyT,MappedT,CompareT> result;
  result.mRoot = nullptr;
  node *res = result.mRoot;
  node *it = mRoot;
  while(it != NULL){
    int cmp = compare(it->data.first, val);
    if(cmp == -1){
      tmp = it->left;
      if(it == mRoot){
        mRoot = it->left;
        it->left = NULL;
      }else{ 
        it->parent = NULL;
        it->left = NULL;
      }
      if(res == NULL){
        result.mRoot = it;
      }else{
        while(res->left != NULL){
          res = res->left;
        }
        child_link(res,it) = it;
        it->parent = res;
      }
      it = tmp;
    }
    else{
      it = it->right;
    }
  }
  return result;
}

#endif
