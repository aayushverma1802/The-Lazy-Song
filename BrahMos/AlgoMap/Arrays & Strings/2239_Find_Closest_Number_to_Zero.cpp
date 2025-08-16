class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int ans = INT_MAX;
        int n = nums.size();
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans > abs(nums[i]))
            {
                ans = abs(nums[i]);
                idx = i;
            }
            else if (ans == abs(nums[i]))
            {
                if (nums[i] > nums[idx])
                {
                    idx = i;
                }
            }
        }
        return nums[idx];
    }
};