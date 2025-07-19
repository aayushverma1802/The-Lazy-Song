class Solution
{
public:
    static bool cmp(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
    {
        return get<0>(a) < get<0>(b); // Sort by nums1
    }

    vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<long long> ans(n, 0);
        vector<tuple<int, int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({nums1[i], i, nums2[i]}); // (nums1, index, nums2)
        }

        sort(v.begin(), v.end(), cmp);

        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && get<0>(v[i]) == get<0>(v[i - 1]))
            {
                ans[get<1>(v[i])] = ans[get<1>(v[i - 1])];
            }
            else
            {
                ans[get<1>(v[i])] = sum;
            }

            int val = get<2>(v[i]);
            pq.push(val);
            sum += val;

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};
