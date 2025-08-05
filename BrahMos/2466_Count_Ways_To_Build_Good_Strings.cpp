class Solution {
public:
int mod=1e9+7;
vector<int>dp;
    int solve(int low, int high, int zero, int one,int length) {
        int count = 0;
        if(length>high){
            return 0;
        }
 
        count=(length>=low)?1:0;
        if(dp[length]!=-1){
            return dp[length];
        }
        // if (curr.size() >= low and curr.size() <= high) {
        //     count = 1;
        // }
        int onee = solve(low, high, zero, one, length+one);
        int zeroo = solve(low, high, zero, one, length+zero);
        return dp[length]=(onee + zeroo + count)%mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(high+1,-1);
        return solve(low, high, zero, one, 0);
    }
};
