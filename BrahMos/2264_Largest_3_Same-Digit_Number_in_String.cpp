class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int maxi = -1;
        for (int i = 0; i <= num.size() - 3; i++)
        {
            if (num[i] == num[i + 1] and num[i + 1] == num[i + 2])
            {
                maxi = max(maxi, (num[i] - '0'));
            }
        }

        if (maxi == -1)
            return ""; // no good integer found
        return string(3, '0' + maxi);
    }
};