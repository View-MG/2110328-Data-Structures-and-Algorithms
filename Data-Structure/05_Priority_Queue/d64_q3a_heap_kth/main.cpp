#include <bits/stdc++.h>
#include "priority_queue.h"
#include "student.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n = 10;
    CP::priority_queue<int> pq;
    while (n--) pq.push(n);
    cout << pq.get_kth(3) << endl; // Expected output: 7
    cout << pq.get_kth(2) << endl; // Expected output: 8
    cout << pq.get_kth(1) << endl; // Expected output: 9

    n = 10;
    CP::priority_queue<int, std::greater<int>> pq2;
    while (n--) pq2.push(n);
    cout << pq2.get_kth(3) << endl; // Expected output: 2
    cout << pq2.get_kth(2) << endl; // Expected output: 1
    cout << pq2.get_kth(1) << endl; // Expected output: 0
}
