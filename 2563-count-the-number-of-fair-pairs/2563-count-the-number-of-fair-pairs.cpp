typedef long long ll;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll count = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            int mini = lower - nums[i], maxi = upper - nums[i];
            int low = lower_bound(nums.begin() + i + 1, nums.end(), mini) - nums.begin();
            int high = upper_bound(nums.begin() + i + 1, nums.end(), maxi) - nums.begin();
            count += (high - low);
        }

        return count;
    }
};