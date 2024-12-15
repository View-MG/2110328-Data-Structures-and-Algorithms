#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> nodes;
vector<int> finds(8);
unordered_set<int> resultPaths;
vector<vector<bool>> visited;

// DFS function with memoization to explore all simple paths and their sums
void dfs(int node, int currentSum, vector<bool>& visited) {
    resultPaths.insert(currentSum);

    // Explore all neighbors of the current node
    for (auto& neighbor : nodes[node]) {
        int nextNode = neighbor.first;
        int weight = neighbor.second;

        // Visit the neighbor if it hasn't been visited already (simple path)
        if (!visited[nextNode]) {
            visited[nextNode] = true;
            dfs(nextNode, currentSum + weight, visited);
            visited[nextNode] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n, false);

    // Read the target Ki values
    for (int i = 0; i < 8; i++) {
        cin >> finds[i];
    }

    // Initialize the graph
    nodes.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({b, c});
        nodes[b].push_back({a, c});
    }

    // Run DFS starting from each node
    for (int i = 0; i < n; i++) {
        visited[i] = true;
        dfs(i, 0, visited);
        visited[i] = false;
    }

    // Output results for each Ki
    for (int i = 0; i < 8; i++) {
        if (resultPaths.find(finds[i]) != resultPaths.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
