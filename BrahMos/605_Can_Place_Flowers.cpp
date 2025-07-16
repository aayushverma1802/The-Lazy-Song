class Solution
{
public:
    bool canPlaceFlowers(vector<int> &nums, int n)
    {
        int l = nums.size();
        if (n == 0)
        {
            return 1;
        }
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == 0)
            {

                bool left = (i == 0) or (nums[i - 1] == 0);
                bool right = (i == l - 1) or (nums[i + 1] == 0);
                if (left and right)
                {
                    nums[i] = 1;
                    n--;
                }
                if (n == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
