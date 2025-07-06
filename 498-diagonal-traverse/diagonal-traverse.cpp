class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> res;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        bool flag = true; // to toggle zig-zag reversal

        while (!q.empty()) {
            int size = q.size();
            vector<int> line;
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();

                line.push_back(matrix[row][col]);

                // Right
                if (col + 1 < m && !vis[row][col + 1]) {
                    q.push({row, col + 1});
                    vis[row][col + 1] = 1;
                }

                // Down
                if (row + 1 < n && !vis[row + 1][col]) {
                    q.push({row + 1, col});
                    vis[row + 1][col] = 1;
                }
            }

            if (flag)
                reverse(line.begin(), line.end());

            res.insert(res.end(), line.begin(), line.end());
            flag = !flag;
        }

        return res;
    }
};
