class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        string temp="";
        int open=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open++;
                temp.push_back(s[i]);
            }else if(s[i]==')'){
                if(open>0){
                    open--;
                    temp.push_back(s[i]);
                }
            }else{
                temp.push_back(s[i]);
            }
        }
        string final_result="";
        for(int i=temp.length()-1; i>=0; i--){
            if(temp[i]=='(' && open>0){
                open--;
            }else{
                final_result.push_back(temp[i]);
            }
        }
            
            reverse(begin(final_result),end(final_result));
            return final_result;
            
    }
};