class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()) {
            int children = q.size();
            for (int i = 0; i < children; i++) {
                pair<int,int> cur = q.front();
                int I = cur.first;
                int J = cur.second;
                q.pop();

                // Only mark and add squares that would be less dist
                if (I+1 < grid.size() && grid[I+1][J] != -1 && (grid[I][J] + 1) < grid[I+1][J]) {
                    grid[I+1][J] = grid[I][J] + 1;
                    q.push({I+1,J});
                }

                if (I-1 >= 0 && grid[I-1][J] != -1 && (grid[I][J] + 1) < grid[I-1][J]) {
                    grid[I-1][J] = grid[I][J] + 1;
                    q.push({I-1,J});
                }

                if (J+1 < grid[0].size() && grid[I][J+1] != -1 && (grid[I][J] + 1) < grid[I][J+1]) {
                    grid[I][J+1] = grid[I][J] + 1;
                    q.push({I,J+1});
                }

                if (J-1 >= 0 && grid[I][J-1] != -1 && (grid[I][J] + 1) < grid[I][J-1]) {
                    grid[I][J-1] = grid[I][J] + 1;
                    q.push({I,J-1});
                }
            }
        }
    }
};
