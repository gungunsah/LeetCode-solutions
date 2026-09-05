class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int start=0,end=n-1,ans=nums[0],mid,beg;
        while(start<=end){
            mid=end+(start-end)/2;
       // left sorted
       if(nums[mid]>=nums[0])
       start=mid+1;
       // right sorted 
        else{
         ans=nums[mid];
         end=mid-1;
        }
    }
    return ans;
    }
};