class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=nums.size();
        int start=0,end=nums.size()-1,mid,beg;
        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
        
    }
};