class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0;
        int n = s.size();
        int j = n - 1;
        while (i < j and s[i] == s[j])
        {
            char ch = s[i];
            while (i <= j and s[i] == ch)
                i++;
            while (i <= j and s[j] == ch)
                j--;
        }
        int ans = j - i;
        return ans + 1;
    }
};