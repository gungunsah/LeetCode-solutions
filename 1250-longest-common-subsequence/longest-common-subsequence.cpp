class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        // vector ko direct 0 se initialize kar sakte hain
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1]; // Match hone par 1 add karein
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]); // Match na hone par max lein
                }
            }
        }
        
        return t[m][n]; // Ab return statement function ke andar hai
    }
};