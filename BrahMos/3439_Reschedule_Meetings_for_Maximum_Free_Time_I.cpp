class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                    vector<int> &endTime)
    {
        int maxSum = 0;

        vector<int> freetime;

        freetime.push_back(startTime[0]);
        for (int i = 1; i < startTime.size(); i++)
        {
            freetime.push_back(startTime[i] - endTime[i - 1]);
        }
        freetime.push_back(eventTime - endTime[endTime.size() - 1]);
        // Sliding Window
        int n = freetime.size();
        int i = 0, j = 0;
        int currsum = 0;
        while (j < n)
        {
            currsum += freetime[j];
            if (i < n and j - i + 1 > k + 1)
            {
                currsum -= freetime[i];
                i++;
            }
            maxSum = max(maxSum, currsum);
            j++;
        }
        return maxSum;
    }
};