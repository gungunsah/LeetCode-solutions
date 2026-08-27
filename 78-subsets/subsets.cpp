class Solution {
public:
void solve(vector<int>& nums,int i,vector<vector<int>>&result, vector<int>&ans){
    if(i==(int)nums.size()){
        result.push_back(ans);
        return;
    }
    //include
    ans.push_back(nums[i]);
    solve(nums,i+1,result,ans);

    ans.pop_back();
     solve(nums,i+1,result,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;
        solve(nums,0,result,ans);
        return result;
        
    }
};