class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for(int num : nums)
            total += num;

        long long target = total - x;

        if(target < 0)
            return -1;

        if(target == 0)
            return n;

        unordered_map<long long, int> mp;
        mp[0] = -1;

        long long sum = 0;
        int maxLen = -1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if(mp.count(sum - target)) {
                maxLen = max(maxLen, i - mp[sum - target]);
            }

            if(!mp.count(sum))
                mp[sum] = i;
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};