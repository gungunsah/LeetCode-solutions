class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        int n = min(first.length(), last.length());
        for (int i = 0; i < n; i++) {
            if (first[i] != last[i]) {
                break;
            }
            result += first[i];
        }
        return result;
    }
};