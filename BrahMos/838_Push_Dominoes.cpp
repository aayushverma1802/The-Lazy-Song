class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();

        vector<int> leftClosetR(n, -1);
        vector<int> rightClosetL(n, -1);

        // Move from left to right to find the nearest 'R' to the left
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'R')
            {
                leftClosetR[i] = i;
            }
            else if (dominoes[i] == '.' && i > 0)
            {
                leftClosetR[i] = leftClosetR[i - 1];
            }
        }

        // Move from right to left to find the nearest 'L' to the right
        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L')
            {
                rightClosetL[i] = i;
            }
            else if (dominoes[i] == '.' && i < n - 1)
            {
                rightClosetL[i] = rightClosetL[i + 1];
            }
        }

        string result(n, '.');
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] != '.')
            {
                result[i] = dominoes[i];
                continue;
            }

            int distToR = leftClosetR[i] == -1 ? INT_MAX : i - leftClosetR[i];
            int distToL = rightClosetL[i] == -1 ? INT_MAX : rightClosetL[i] - i;

            if (distToL == distToR)
            {
                result[i] = '.'; // Cancel each other
            }
            else if (distToL < distToR)
            {
                result[i] = 'L';
            }
            else
            {
                result[i] = 'R';
            }
        }

        return result;
    }
};
