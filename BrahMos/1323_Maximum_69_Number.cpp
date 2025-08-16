class Solution
{
public:
    int maximum69Number(int num)
    {
        string temp = to_string(num);
        int n = temp.size();
        int maxi = num;
        for (int i = 0; i < n; i++)
        {
            int ori = temp[i];
            if (temp[i] == '6')
            {
                temp[i] = '9';
            }
            else if (temp[i] == '9')
            {
                temp[i] = '6';
            }
            int a = stoi(temp);
            cout << a << endl;
            maxi = max(maxi, a);
            temp[i] = ori;
        }
        return maxi;
    }
};