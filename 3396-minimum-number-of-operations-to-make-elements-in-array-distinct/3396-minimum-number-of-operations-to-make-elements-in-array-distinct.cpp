class Solution {
public:
    bool isDistinct(vector<int> &nums, int mpp[]) {
        for(auto num : nums) if(mpp[num] > 1) return false;
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        int mpp[101] = {0};
        for(auto num : nums) mpp[num]++;

        int operations = 0;
        while(!isDistinct(nums, mpp)) {
            if(nums.size() < 3) return operations + 1;
            for(int i = 0; i < 3; ++i) {
                mpp[nums[0]]--;
                nums.erase(nums.begin());
            }
            operations++;
        }

        return operations;
    }
};