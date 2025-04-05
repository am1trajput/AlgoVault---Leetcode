class Solution {
public:
    int sum = 0;
    void solve(int index, vector<int> &nums, int temp) {
        if(index == nums.size()) {
            sum += temp;
            return;
        }
        solve(index + 1, nums, temp ^ nums[index]);
        solve(index + 1, nums, temp);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0, nums, 0);
        return sum;
    }
};