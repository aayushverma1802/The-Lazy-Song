class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        map<int, vector<int>> m;
        map<int, int> trustedCount;
        for (int i = 0; i < trust.size(); i++)
        {
            m[trust[i][0]].push_back(trust[i][1]);
            trustedCount[trust[i][1]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (m.count(i) == 0 && trustedCount[i] == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};