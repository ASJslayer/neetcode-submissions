class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n,0));
        for (const auto &edge: edges) {
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
        }

        // Start BFS at anypoint and break if loop or multiple components
        bool visited[n] = {false};
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (graph[i][j] == 0) continue;

                if (found) return false;

                found = true;

                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int start = q.front();
                    q.pop();
                    if (visited[start]) return false;
                    visited[start] = true;

                    for (int end = 0; end < n; end++) {
                        if (graph[start][end]) {
                            if (start == end) return false; // Self loop
                            graph[start][end] = 0;
                            graph[end][start] = 0;
                            q.push(end);
                        }
                    }
                }
            }
        }

        return true;
    }
};
