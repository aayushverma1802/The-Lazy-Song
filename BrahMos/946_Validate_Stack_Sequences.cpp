class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int n = pushed.size();
        stack<int> st;
        int i = 0, j = 0;

        while (i < n or (!st.empty() && j < n))
        {
            if (st.empty() == false and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            else if (i < n)
            {
                st.push(pushed[i]);
                i++;
            }
            else
            {
                return false;
            }
        }

        return st.empty();
    }
};