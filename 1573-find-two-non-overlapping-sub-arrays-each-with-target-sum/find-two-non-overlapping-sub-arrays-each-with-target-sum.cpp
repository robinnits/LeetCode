class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        const int INF = 1e9;
        vector<int> best(n + 1, INF);

        int ans = INF;

        int l = 0;
        long long sum = 0;

        for(int r = 0; r < n; r++) {

            sum += arr[r];

            while(sum > target && l <= r) {
                sum -= arr[l];
                l++;
            }

            best[r + 1] = best[r];

            if(sum == target) {

                int len = r - l + 1;
                if(best[l] != INF) {
                    ans = min(ans, len + best[l]);
                }
                best[r + 1] = min(best[r + 1], len);
            }
        }

        return ans == INF ? -1 : ans;
    }
};