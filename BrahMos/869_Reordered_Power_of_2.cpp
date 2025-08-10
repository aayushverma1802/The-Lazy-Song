class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        if (n <= 0)
        {

            return false;
        }
        bool ans = false;

        string temp = to_string(n);
        sort(temp.begin(), temp.end());
        do
        {
            if (temp[0] != '0')
            {
                int x = stoi(temp);
                if ((x & (x - 1)) == 0)
                    return true;
            }
        } while (next_permutation(temp.begin(), end(temp)));
        return false;
    }
};