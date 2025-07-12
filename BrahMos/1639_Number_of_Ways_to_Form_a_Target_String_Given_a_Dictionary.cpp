class Solution
{
public:
    int k; // target len
    int m; // word len
    vector<vector<int>> dp;
    const int MOD = 1e9 + 7;
    int solve(int i, int j, vector<vector<long long>> &freq, string &target)
    {
        if (i == m)
        {
            return 1;
        }
        if (j == k)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int not_taken = (solve(i, j + 1, freq, target)) % MOD;
        int taken = ((freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, target))) % MOD;
        return dp[i][j] = (not_taken + taken) % MOD;
    }
    int numWays(vector<string> &words, string target)
    {

        m = target.size();
        k = words[0].size();
        vector<vector<long long>> freq(26, vector<long long>(k));
        for (int col = 0; col < k; col++)
        {
            for (string &word : words)
            {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }
        dp.assign(target.size(), vector<int>(words[0].size(), -1));
        return solve(0, 0, freq, target);
    }
};