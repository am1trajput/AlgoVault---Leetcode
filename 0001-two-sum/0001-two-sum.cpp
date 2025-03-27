class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int diff = target - num;
            if(hashmap.find(diff) != hashmap.end()) {
                return {hashmap[diff], i};
            }
            hashmap[num] = i;
        }
        return {-1, -1};
    }
};