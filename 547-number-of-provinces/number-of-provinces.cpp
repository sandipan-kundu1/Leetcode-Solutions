class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[i] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !vis[j]) {
                dfs(j, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0); // Use a vector for the visited array
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // If a node is not visited, it's a new component
                cnt++;
                dfs(i, isConnected, vis);
            }
        }

        return cnt;
    }
};
