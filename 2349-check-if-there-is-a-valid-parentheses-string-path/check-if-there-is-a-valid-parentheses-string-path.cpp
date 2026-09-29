class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        if ((m + n - 1) % 2)
            return false;

        int maxBal = m + n;

        vector<vector<vector<char>>> dp(
            m,
            vector<vector<char>>(n, vector<char>(maxBal + 1, 0))
        );

        dp[0][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                for (int bal = 0; bal <= maxBal; bal++) {
                    if (grid[i][j] == '(') {
                        if (bal == 0) continue;

                        if (i > 0 && dp[i - 1][j][bal - 1])
                            dp[i][j][bal] = 1;

                        if (j > 0 && dp[i][j - 1][bal - 1])
                            dp[i][j][bal] = 1;
                    }
                    else {
                        if (bal == maxBal) continue;

                        if (i > 0 && dp[i - 1][j][bal + 1])
                            dp[i][j][bal] = 1;

                        if (j > 0 && dp[i][j - 1][bal + 1])
                            dp[i][j][bal] = 1;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};