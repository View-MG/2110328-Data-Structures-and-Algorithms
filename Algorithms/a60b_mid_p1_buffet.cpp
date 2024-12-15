#include <bits/stdc++.h>
using namespace std;

int main() {
    int f, w, n;
    cin >> f >> w >> n;
    vector<int> table(f);
    for (int i{0}; i<f; i++) cin >> table[i];
    sort(table.begin(), table.end());
    int light_count{0};
    int range = 2*w+1;
    int last_covered = -1;

    for (int i{0}; i<f; i++) {
        if (table[i] > last_covered) {
            last_covered = table[i] + range - 1;
            light_count++;
        }
    }
    cout << light_count;
    return 0;
}
