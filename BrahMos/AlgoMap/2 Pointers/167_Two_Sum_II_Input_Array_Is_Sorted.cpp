class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int j = n-1, i =0;
        vector<int> ans;
        while (i<j) {
            if (numbers[i] + numbers[j] == target) {
                return {i+1,j+1};

            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
                
            }
        }
        return ans;
    }
};