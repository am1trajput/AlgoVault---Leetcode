class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        for(auto num : nums) mpp[num]++;
        for(int i = 1; i <= INT_MAX; i++) {
            if(mpp.find(i) == mpp.end()) return i;
        }

        return 1;
    }
};