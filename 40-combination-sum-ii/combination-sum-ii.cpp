class Solution {
public:
void getallcombination(vector<int>& arr,int idx, int target, vector<vector<int>>&ans, vector<int>&combin){
    if(target==0){
        ans.push_back(combin);
        return;
    }
    if(idx==arr.size() || target<0){
        return;
    }
    combin.push_back(arr[idx]);
    getallcombination(arr,idx+1,target-arr[idx],ans,combin);
    combin.pop_back();
    while(idx+1<arr.size() && arr[idx+1]==arr[idx]){
        idx++;
    }
    getallcombination(arr,idx+1,target,ans,combin);
}
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>combin;

        getallcombination(arr,0,target,ans,combin);
        return ans;
        
    }
};