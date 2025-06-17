class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);  // edge from prereq to course
            indegree[edge[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0; // number of nodes in topological order

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return count == n;  // if not, there was a cycle
    }
};
