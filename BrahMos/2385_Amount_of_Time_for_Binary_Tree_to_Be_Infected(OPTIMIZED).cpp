/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void make_graph(unordered_map<int, vector<int>> &adj, int parent, TreeNode *curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        if (parent != -1)
        { // Curr ka parent
            adj[curr->val].push_back(parent);
        }
        if (curr->left)
        {
            adj[curr->val].push_back(curr->left->val);
        }
        if (curr->right)
        {
            adj[curr->val].push_back(curr->right->val);
        }
        make_graph(adj, curr->val, curr->left);
        make_graph(adj, curr->val, curr->right);
    }
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> adj;
        make_graph(adj, -1, root);
        // Apply bfs from start
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int mintues = 0;

        while (!q.empty())
        {
            int n = q.size(); // Current Level size
            while (n--)
            {
                int curr = q.front();
                q.pop();
                for (int &ngbr : adj[curr])
                {
                    if (vis.find(ngbr) == vis.end())
                    {
                        vis.insert(ngbr);
                        q.push(ngbr);
                    }
                }
            }
            mintues++;
        }
        return mintues - 1;
    }
};