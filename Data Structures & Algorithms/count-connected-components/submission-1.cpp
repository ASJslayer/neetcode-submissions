class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (const auto &edge: edges) {
            matrix[edge[0]][edge[1]] = 1;
            matrix[edge[1]][edge[0]] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) matrix[i][j] = 1;
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) continue;

                components++;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int start = q.front();
                    q.pop();
                    for (int end = 0; end < n; end++) {
                        if (matrix[start][end]) {
                            matrix[start][end] = 0;
                            matrix[end][start] = 0;

                            if (start != end) q.push(end);
                        }
                    }
                }
            }
        }

        return components;
    }
};
