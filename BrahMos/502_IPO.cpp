class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital)
    {
        int ans_capital = 0;
        int n = profits.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq_cap;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            pq_cap.push({capital[i], profits[i]});
        }
        int i = 0;
        while (k > 0)
        {

            while (!pq_cap.empty() and w >= pq_cap.top().first)
            {
                pq.push(pq_cap.top().second); // push profit
                pq_cap.pop();
            }
            if (pq.empty())
            {
                break;
            }
            w += pq.top(); // Add best profit
            pq.pop();
            k--;
        }

        return w;
    }
};