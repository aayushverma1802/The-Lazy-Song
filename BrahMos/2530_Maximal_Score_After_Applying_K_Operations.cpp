class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long int n = nums.size();
        priority_queue<long long int> pq;
        for (auto i : nums)
        {
            pq.push(i);
        }
        long long ans = 0;
        while (k-- and pq.empty() == false)
        {
            ans += pq.top();
            long long int temp = pq.top();
            pq.pop();
            pq.push((long long)ceil(temp / 3.0));
        }
        return ans;
    }
};