class Solution
{
public:
    typedef long long ll;
    const int Large_Value = 2e9;
    typedef pair<long, long> P;
    ll Disalgo(vector<vector<int>> &edges, int n, int src, int dest)
    {
        // make the graph excluding -1 at edges
        unordered_map<ll, vector<pair<ll, ll>>> adj; // u->v;
        for (vector<int> &edge : edges)
        {
            if (edge[2] != -1)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, INT_MAX);
        vector<bool> visited(n, false);
        result[src] = 0;
        pq.push({0, src});
        while (pq.empty() == false)
        {
            ll currdist = pq.top().first;
            ll currnode = pq.top().second;
            pq.pop();
            if (visited[currnode] == true)
            {
                continue;
            }
            visited[currnode] = true;
            for (auto &[ng, wt] : adj[currnode])
            {
                if (result[ng] > currdist + wt)
                {
                    result[ng] = currdist + wt;
                    pq.push({result[ng], ng});
                }
            }
        }
        return result[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        ll currshortdist = Disalgo(edges, n, source, destination);
        if (currshortdist < target)
        {
            return {};
        }
        bool matchedTarget = (currshortdist == target);
        if (matchedTarget == true)
        {
            for (vector<int> &edge : edges)
            {
                if (edge[2] == -1)
                {
                    edge[2] = Large_Value;
                }
            }
            return edges;
        }
        for (vector<int> &edge : edges)
        {
            if (edge[2] == -1)
            {
                edge[2] = (matchedTarget == true) ? Large_Value : 1; // assign lowest number i.e 1;
                if (matchedTarget != true)
                {
                    ll newShortDist = Disalgo(edges, n, source, destination);
                    if (newShortDist <= target)
                    {
                        matchedTarget = true;
                        edge[2] += (target - newShortDist);
                    }
                }
            }
        }
        if (matchedTarget == false)
        {
            return {};
        }
        return edges;
    }
};