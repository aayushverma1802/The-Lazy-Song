class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        for (int i = 0; i <= (int)log2(n); i++)
        {
            if ((int)pow(2, i) == n)
            {
                return true;
            }
        }
        return false;
    }
};