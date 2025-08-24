class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        // Approach 1 Brute Force
        // if(n>m){
        //     return false;
        // }
        // sort(begin(s1),s1.end());
        // // bool ans=false;
        // for(int i=0;i<=m-n;i++){
        //     string sub=s2.substr(i,n);
        //     sort(begin(sub),end(sub));
        //     if(s1==sub){
        //         return true;
        //     }
        // }

        // Approach 2 Optimized
        if (n > m)
        {
            return false;
        }
        vector<int> s1_f(26, 0);
        vector<int> s2_f(26, 0);
        for (char &ch : s1)
        {
            s1_f[ch - 'a']++;
        }
        int i = 0;
        int j = 0;
        while (j < m)
        {
            s2_f[s2[j] - 'a']++;
            if (j - i + 1 > n)
            {
                // time to shrink the window
                s2_f[s2[i] - 'a']--;
                i++;
            }
            if (s1_f == s2_f)
            {
                return true;
            }
            j++;
        }

        return false;
    }
};