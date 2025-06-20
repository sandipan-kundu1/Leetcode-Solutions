class DSU
{
    vector<int> rank,parent,size;
public:
    DSU(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i; // initially each node is its own parent
    }
    int findupar(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findupar(parent[node]); // recursively find the parent
    }
    void unionbysize(int u,int v)
    {
        int upu=findupar(u);
        int upv=findupar(v);

        if(upu==upv)  return;

        if(size[upu]<size[upv])
        {
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else
        {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution {
public:
    int cost(vector<int> a,vector<int> b)
    {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                int coste=cost(points[i],points[j]);
                edges.push_back({coste,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        DSU dsu(V);
        int sum=0;
        for(auto i:edges)
        {
            int wt=i.first;
            int u=i.second.first,v=i.second.second;
            if(dsu.findupar(u)!=dsu.findupar(v))
            {
                dsu.unionbysize(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
};