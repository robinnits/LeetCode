class Solution {
public:
    int numberOfSets(int n, int k) {

        const long long MOD = 1000000007;

        int N = n + k - 1;

        vector<vector<long long>> dp(
            N + 1,
            vector<long long>(2 * k + 1, 0)
        );

        dp[0][0] = 1;

        for(int i = 1; i <= N; i++) {

            dp[i][0] = 1;

            for(int j = 1; j <= 2 * k; j++) {

                dp[i][j] = dp[i - 1][j];

                if(j <= i) {
                    dp[i][j] =
                        (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }

        return dp[N][2 * k];
    }
};