class Solution {
public:
    int helper(int i, int j, int k, vector<vector<int>>& coins,
               vector<vector<vector<int>>>& dp) {

        int n = coins.size();
        int m = coins[0].size();

        if (i >= n || j >= m) return -1e9;

        if (i == n - 1 && j == m - 1) {
            if (coins[i][j] >= 0) return coins[i][j];
            return (k > 0) ? 0 : coins[i][j];
        }

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int down = helper(i + 1, j, k, coins, dp);
        int right = helper(i, j + 1, k, coins, dp);

        int ans;

        if (coins[i][j] >= 0) {
            ans = coins[i][j] + max(down, right);
        } else {
            int take = coins[i][j] + max(down, right); // negative add

            int skip = -1e9;
            if (k > 0) {
                int downSkip = helper(i + 1, j, k - 1, coins, dp);
                int rightSkip = helper(i, j + 1, k - 1, coins, dp);
                skip = max(downSkip, rightSkip);
            }

            ans = max(take, skip);
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        return helper(0, 0, 2, coins, dp);
    }
};