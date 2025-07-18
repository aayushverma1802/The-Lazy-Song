class Solution
{
public:
    void fillNig(queue<string> &q, string curr, unordered_set<string> &st)
    {
        for (int i = 0; i < 4; i++)
        {
            char ch = curr[i];
            char dec = ch == '0' ? '9' : ch - 1;
            char inc = ch == '9' ? '0' : ch + 1;
            curr[i] = dec;
            if (st.find(curr) == st.end())
            {
                st.insert(curr);
                q.push(curr);
            }
            curr[i] = inc;
            if (st.find(curr) == st.end())
            {
                st.insert(curr);
                q.push(curr);
            }
            curr[i] = ch;
        }
    }
    int openLock(vector<string> &deadends, string target)
    {
        string start = "0000";
        unordered_set<string> st{begin(deadends), end(deadends)};
        queue<string> q;
        q.push(start);
        if (st.find(start) != st.end())
            return -1;
        int level = 0;
        while (q.empty() == false)
        {
            int n = q.size();
            while (n--)
            {
                string curr = q.front();
                q.pop();
                if (curr == target)
                {
                    return level;
                }
                fillNig(q, curr, st);
            }
            level++;
        }
        return -1;
    }
};