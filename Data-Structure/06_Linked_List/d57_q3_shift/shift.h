void shift(int k) {
    while(k<0) k+=mSize;
    k=k%mSize;
    if (k==0 || mSize<= 1) return;

    auto it = this->begin();
    for(int i{0} ; i<k ; i++) it++;

    auto lastElement = mHeader->prev;
    auto firstElement = mHeader->next;
    auto beforeIt = it.ptr->prev;
        
    lastElement->next = firstElement;
    firstElement->prev = lastElement;

    it.ptr->prev = mHeader;
    mHeader->prev = beforeIt;
    mHeader->next = it.ptr;
    beforeIt->next = mHeader;
}