class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n)
        return"";

        unordered_map<char,int>mp;
        for(char&ch:t)
        mp[ch]++;

        int requiredcount=t.length();
        int i=0,j=0;

        int minwindowsize=INT_MAX;
        int start_i=0;
        while(j<n){
            char ch=s[j];

            if(mp[ch]>0)
            requiredcount--;

            mp[ch]--;
            while(requiredcount==0){
                int currwindowsize=j-i+1;

                if(minwindowsize>currwindowsize){
                    minwindowsize=currwindowsize;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredcount++;
                }
                i++;
            }
            j++;
        }
        return minwindowsize==INT_MAX?"":s.substr(start_i,minwindowsize);
        
    }
};

