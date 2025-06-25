// User function template for C++

class Solution
{
public:
    vector<int> factorial(int n)
    {
        // code here
        vector<int> ans;
        ans.push_back(1);
        int i = 2;
        while (i <= n)
        {
            int carry = 0;
            int j = 0;
            while (j < ans.size())
            {
                int mul = ans[j] * i + carry;
                ans[j] = mul % 10;
                carry = mul / 10;
                j++;
            }
            while (carry > 0)
            {
                ans.push_back(carry % 10);
                carry /= 10;
            }
            i++;
        }

        // cout<<ans;
        vector<int> temp;
        stack<long long int> st;
        int k = 0;
        while (k < ans.size())
        {
            st.push(ans[k]);
            k++;
        }
        while (st.empty() == false)
        {
            temp.push_back(st.top());
            st.pop();
        }
        return temp;
    }
};