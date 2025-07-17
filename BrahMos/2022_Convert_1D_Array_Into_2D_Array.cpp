class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int size = original.size();
        if (size != m * n)
            return {}; // Added this condition to ensure the 2D array can be constructed
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = original[k++];
            }
        }
        return ans;
    }
};
 
