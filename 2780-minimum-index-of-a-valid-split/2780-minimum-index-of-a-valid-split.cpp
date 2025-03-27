class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // Moore's voting algorithm
        int count = 0;
        int dom = nums[0];
        for(auto num : nums) {
            if(num == dom) count++;
            else count--;
            if(count == 0) {
                dom = num;
                count = 1;
            }
        }
        int freq = 0;
        for(auto num : nums) if(num == dom) freq++;

        count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == dom) count++;
            if(count * 2 > (i + 1) && (freq - count) * 2 > (nums.size() - i - 1)) return i;
        }

        return -1;
    }
};