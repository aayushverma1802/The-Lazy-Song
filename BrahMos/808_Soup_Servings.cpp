class Solution
{
public:
    vector<vector<double>> dp;
    double solve(int a, int b)
    {
        if (a <= 0 and b > 0)
            return 1.0;
        else if (a <= 0 and b <= 0)
            return 0.5;
        else if (a > 0 and b <= 0)
            return 0.0;
        if (dp[a][b] != -1)
        {
            return dp[a][b]; 
        }
        double c1 = solve(a - 100, b);
        double c2 = solve(a - 75, b - 25);
        double c3 = solve(a - 50, b - 50);
        double c4 = solve(a - 25, b - 75);
        return dp[a][b] = (c1 + c2 + c3 + c4) * 0.25;
    }
    double soupServings(int n)
    {
        if (n >= 5000)
            return 1;
        dp.assign(n + 1, vector<double>(n + 1, -1));
        return solve(n, n);
    }
};