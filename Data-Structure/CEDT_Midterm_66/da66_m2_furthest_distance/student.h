#ifndef __STUDENT_H_5
#define __STUDENT_H_
#include "map_bst.h"
template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int& aux) {
    if (!n) return 0;
    int l = my_recur(n->left, aux);
    int r = my_recur(n->right, aux);
    aux = std::max(aux, l + r);
    return std::max(l, r) + 1;
}
template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    int aux = -1;
    my_recur(mRoot, aux);
    return aux;
}
#endif
