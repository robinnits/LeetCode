class Solution {
public:
    long long solve(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {
        if (j < 0) return 1;

        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] =
                solve(i - 1, j - 1, s, t, dp) +
                solve(i - 1, j, s, t, dp);
        }

        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(
            n, vector<long long>(m, -1)
        );

        return solve(n - 1, m - 1, s, t, dp);
    }
};