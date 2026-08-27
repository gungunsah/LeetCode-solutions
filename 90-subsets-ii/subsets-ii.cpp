class Solution {
public:
void getallsubset(vector<int>& nums,int i, vector<vector<int>>&result,vector<int>&ans){
    if(i==nums.size()){
        result.push_back(ans);
        return ;
    }
    //include
    ans.push_back(nums[i]);
    getallsubset(nums,i+1,result,ans);

    //exclude
    ans.pop_back();
    int idx=i;
    while(idx<nums.size() && nums[idx]==nums[i]){
    idx++;
}
    getallsubset(nums,idx,result,ans);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;

        sort(nums.begin(),nums.end());
        getallsubset(nums,0,result,ans);
        return result;
        
    }
};