class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        // vector<int>ans;
        string ans = "";
        // for(int i=0;i<n;i++){
        int i = 0, j = 0;
        int n = word1.size();
        int m = word2.size();
        while (i < n or j < m)
        {
            if (i < n)
            {
                ans.push_back(word1[i]);
                i++;
            }
            if (j < m)
            {
                ans.push_back(word2[j]);
                j++;
            }
        }
        return ans;
    }
};