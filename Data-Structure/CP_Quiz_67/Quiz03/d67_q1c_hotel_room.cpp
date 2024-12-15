int depth(node *n)
{
  if(n == NULL) return -1;
  if(n->left_child == NULL && n->right_sibling == NULL) return 0;
  if(n->left_child == NULL) return depth(n->right_sibling);
  if(n->right_sibling == NULL) return depth(n->left_child) + 1;
  return std::max(depth(n->left_child) + 1, depth(n->right_sibling));
}
