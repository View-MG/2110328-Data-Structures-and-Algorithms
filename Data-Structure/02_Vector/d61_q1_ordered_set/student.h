#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    unordered_set<T> unions;
    vector<T> v;
    for(auto& elem : A) {
        if(unions.insert(elem).second) {
            v.push_back(elem);
        }
    }
    for(auto& elem : B) {
        if(unions.insert(elem).second) {
            v.push_back(elem);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    unordered_set<T> tmp,intersects;
    vector<T> v;
    for(int i=0 ; i<B.size() ; i++){
        tmp.insert(B[i]);
    }
    for(int i=0 ; i<A.size() ; i++){
        if(tmp.find(A[i]) != tmp.end()){
            v.push_back(A[i]);
        }
    }
    return v;
}
