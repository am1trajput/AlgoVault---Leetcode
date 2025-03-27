class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int maxi = *max_element(nums.begin(), nums.end());
        unordered_set<int> st;
        for(auto num : nums) st.insert(num);
        for(int i = 1; i <= INT_MAX; i++) {
            if(st.find(i) == st.end()) return i;
        }

        return 1;
    }
};