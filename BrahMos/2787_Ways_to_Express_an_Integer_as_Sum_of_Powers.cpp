

class Solution
{
public:
    vector<int> powers;
    vector<vector<long long int>> dp;

    long long int intPow(int base, int exp)
    {
        long long int result = 1;
        for (int i = 0; i < exp; i++)
        {
            result *= base;
        }
        return result;
    }

    void generatePowers(int n, int x)
    {
        powers.clear();
        for (int i = 1;; i++)
        {
            long long int val = intPow(i, x);
            if (val > n)
                break;
            powers.push_back(val);
        }
    }

    long long int solve(int index, int target)
    {
        if (target == 0)
            return 1;
        if (index >= powers.size() || target < 0)
            return 0;
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        long long int take = solve(index + 1, target - powers[index]);
        long long int not_take = solve(index + 1, target);

        return dp[index][target] = (take + not_take) % 1000000007;
    }

    int numberOfWays(int n, int x)
    {
        generatePowers(n, x);
        dp.assign(powers.size(), vector<long long int>(n + 1, -1));
        return solve(0, n);
    }
};
