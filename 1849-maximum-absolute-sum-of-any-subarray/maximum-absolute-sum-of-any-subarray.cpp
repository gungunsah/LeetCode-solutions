class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();

        int maxsum = nums[0];
        int minsum = nums[0];

        int currsumMax = nums[0];
        int currsumMin = nums[0];

        for(int i=1; i<n; i++){

        currsumMax = max(nums[i],currsumMax+nums[i]);
        maxsum = max(maxsum,currsumMax);

        currsumMin =min(nums[i],currsumMin+nums[i]);
        minsum = min(minsum,currsumMin);

       }
       return max(maxsum,abs(minsum));
        
    }
};