class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int n = num.length();

        for (int i = 0; i < n; i++) {
            while (!result.empty() && k > 0 && result.back() > num[i]) {
                result.pop_back();
                k--;
            }

            if (!result.empty() || num[i] != '0') {
                result.push_back(num[i]);
            }
        }

        while (!result.empty() && k > 0) {
            result.pop_back();
            k--;
        }

        if (result == "") {
            return "0";
        }
        return result;
    }
};