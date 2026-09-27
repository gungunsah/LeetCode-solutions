class Solution {
public:
    int findtarget(vector<int>& nums, int target, int n, int index){
        if(index == n)
            return (target == 0) ? 1 : 0;

        int add = findtarget(nums, target + nums[index], n, index + 1);
        int sub = findtarget(nums, target - nums[index], n, index + 1);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return findtarget(nums, target, nums.size(), 0);
    }
};