class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    queue<pair<int, int>> q;

                    q.push({i, j});
                    grid[i][j] = 0;  // mark visited

                    int area = 0;

                    while (!q.empty()) {

                        auto [r, c] = q.front();
                        q.pop();

                        area++;

                        for (int k = 0; k < 4; k++) {

                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr >= 0 && nr < n &&
                                nc >= 0 && nc < m &&
                                grid[nr][nc] == 1) {

                                grid[nr][nc] = 0;  // mark visited
                                q.push({nr, nc});
                            }
                        }
                    }

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};