class Solution
{
public:
    vector<int> take(int n)
    {
        vector<int> temp;
        for (int i = 0; i < 32; i++)
        {
            if ((n & (1 << i)) != 0)
            {
                temp.push_back(1 << i);
            }
        }
        return temp;
    }
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<int> power = take(n);
        for (auto &q : queries)
        {
            int s = q[0];
            int e = q[1];
            long long product = 1;
            for (int i = s; i <= e; i++)
            {
                // product*=power[i];
                product = (product * power[i]) % 1000000007;
            }
            ans.push_back(product);
        }
        return ans;
    }
};