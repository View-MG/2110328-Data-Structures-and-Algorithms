// Your code 
int getHeight(node *n , KeyT& find, int& maximBalance){
      if(n==NULL) return -1;
      int leftHeight = getHeight(n->left, find, maximBalance);
      int rightHeight = getHeight(n->right, find, maximBalance);
      int imBalance = abs(leftHeight-rightHeight);

      if(imBalance > maximBalance){
        find = n->data.first;
        maximBalance = imBalance;
      }else if(imBalance == maximBalance){
        if(mLess(n->data.first,find)){
          find = n->data.first;  
        }
      }

      if(leftHeight > rightHeight){
        return 1 + leftHeight;
     }else{
        return 1 + rightHeight;
      }
    }

    KeyT getValueOfMostImbalanceNode() {
      KeyT find = mRoot->data.first;
      int maximBalance = 0;
      getHeight(mRoot,find,maximBalance);
      return find;
    }