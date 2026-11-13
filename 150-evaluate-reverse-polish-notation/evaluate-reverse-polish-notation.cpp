class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int(int,int)>> mp = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }},
        };

        for (const string& token : tokens) {
            if (mp.count(token)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(mp[token](a, b));
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};