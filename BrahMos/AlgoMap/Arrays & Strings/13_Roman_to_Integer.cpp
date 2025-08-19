class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                         {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char a = s[i];
            if (m.find(a) != m.end()) {
                if ( m[s[i + 1]] > m[a]) {
                    ans += m[s[i + 1]] - m[a];
                    i++;
                } else {
                    cout << m[a] << endl;
                    ans += m[a];
                }
            }
        }
        return ans;
    }
};