class Solution
{
public:
    const int MOD = 1e9 + 7;
    vector<int> dp;
    int solve(string &s, int &k, int start)
    {
        if (start >= s.size())
        {
            return 1;
        }
        if (s[start] == '0')
        {
            return 0;
        }
        if (dp[start] != -1)
        {
            return dp[start];
        }
        long long int num = 0, ans = 0;
        for (int end = start; end < s.length(); end++)
        {
            num = num * 10 + (s[end] - '0');
            if (num > k)
            {
                break;
            }
            ans = (ans % MOD + solve(s, k, end + 1) % MOD) % MOD;
        }
        return dp[start] = ans % MOD;
    }
    int numberOfArrays(string s, int k)
    {
        dp.assign(s.size(), -1);
        return solve(s, k, 0);
    }
};