class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& color)
    {
        for(auto adj:graph[node])
        {
            if(color[adj]==-1)
            {
                color[adj]=!color[node];
                if(!dfs(adj,graph,color))
                return false;
            }
            else if(color[adj]==color[node])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfs(i,graph,color))
                return false;
            }
            
        }
        return true;
    }
};