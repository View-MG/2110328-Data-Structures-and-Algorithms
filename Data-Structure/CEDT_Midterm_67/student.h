
#ifndef __STUDENT_H_
#define __STUDENT_H_


#include "map_bst.h"
#include<bits/stdc++.h>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // You may need this function
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    std::set<node*> a;
    node* n = p->parent;
    while(n!=mRoot) {
        n = n->parent;
        a.insert(n);
    }
    return mRoot;
    
}

#endif
