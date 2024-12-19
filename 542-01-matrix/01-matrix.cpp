class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    queue<pair<pair<int, int>, int>> q;

    // Initialize queue with all 0 cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    // Directions for up, right, down, left
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    // BFS traversal
    while (!q.empty()) {
        auto [coords, val] = q.front();
        auto [x, y] = coords;
        q.pop();

        // Set the distance in the answer matrix
        ans[x][y] = val;

        // Traverse all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check if within bounds and not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({{nx, ny}, val + 1});
            }
        }
    }

    return ans;
}

};