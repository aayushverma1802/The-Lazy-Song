class Solution
{
public:
    // Total count of subarray having <=k distinct elemnets
    int slidewin(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (j < n)
        {
            mp[nums[j]]++;
            while (mp.size() > k)
            {
                // Shrink the window
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt += (j - i + 1); // Ending at j;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return slidewin(nums, k) - slidewin(nums, k - 1);
    }
};