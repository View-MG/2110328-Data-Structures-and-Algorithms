#include<iostream>
#include<vector>
using namespace std;

/*  Descendant of k-ary tree
    1-Ary tree: Descendant of node n is node [n+1]
    2-ary tree: Descendant of node n is node [2n+1,2n+2]
    3-Ary tree: Descendant of node n is node [3n+1,3n+2,3n+3]
    4-Ary tree: Descendant of node n is node [4n+1,4n+2,4n+3,4n+4]
    K-Ary tree: Descendant of node n is node [Kn+1,Kn+2,...,Kn+k]  */
int main()
{
    int tests;
    cin >> tests;
    while(tests--)
    {
        int nodes, K;
        cin >> nodes >> K;
        vector<int> data(nodes);
        for(int i{0}; i < nodes; i++) { cin >> data[i]; }
        bool isHeap = true;
        bool isEnd = false;
        for(int n{0}; n < nodes; n++)
        {
            for(int i = 1; i <= K; i++){
                int child = K*n + i;
                if(child >= nodes) {isEnd = true; break;}
                if(data[n] < data[child]) { isHeap = false; break; }
            }
            if(!isHeap || isEnd) break;
        }
        if(isHeap) cout << "true" << endl;
        else cout << "false" << endl;
    }
}