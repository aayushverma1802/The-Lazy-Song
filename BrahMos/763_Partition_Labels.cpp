class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>ans;
        map<char,int>m;
        for(int i=n-1;i>=0;i--){
            if(m.find(s[i])==m.end())
                m.insert({s[i],i});
        }
        int start=0, end=0,i=0;
        while(i<n){
        // for(i=0;i<n;i++){
            // char cc=s[i];
            end=max(end,m[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
            i++;
        }
        return ans;
    }
};