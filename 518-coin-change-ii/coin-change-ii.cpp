class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // Overflow se bachne ke liye unsigned int use kiya hai
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(amount + 1, 0));

        // Base case: 0 amount banane ka 1 tariqa hota hai (koyi coin mat lo)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // Option 1: Current coin ko mat lo
                dp[i][j] = dp[i - 1][j];

                // Option 2: Current coin ko include karo
                if (coins[i - 1] <= j) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};