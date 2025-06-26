class Solution
{
public:
    void dfs(int node, vector<int> &dist, vector<int> &edges,
             vector<bool> &vis)
    {
        vis[node] = true;
        int v = edges[node];
        if (v != -1 and vis[v] == false)
        {

            dist[v] = 1 + dist[node];
            dfs(v, dist, edges, vis);
        }
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        vector<int> dist1(edges.size(), INT_MAX);
        vector<int> dist2(edges.size(), INT_MAX);
        vector<bool> vis1(edges.size(), false);
        vector<bool> vis2(edges.size(), false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(node1, dist1, edges, vis1);
        dfs(node2, dist2, edges, vis2);
        int mind = -1;
        int maxmin = INT_MAX;

        for (int i = 0; i < edges.size(); i++)
        {
            int maxd = max(dist1[i], dist2[i]);
            if (maxd < maxmin)
            {
                maxmin = maxd;
                mind = i;
            }
        }
        return mind;
    }
};