class Solution {
public:


    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        int s=0,count=0;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto i:m ){
            if(i.second>(n/2)){
                s=i.first;
            }
        }
       return s;
    }
};