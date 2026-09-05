class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax(n);
        vector<int> suffmin(n);
        premax[0] = nums[0];
        for(int i= 1; i<n; i++) {
            premax[i] = max(premax[i-1], nums[i]);
        }
        suffmin[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            suffmin[i] = min(suffmin[i+1], nums[i]);
        }
        int idx = -1;
        for(int i =0; i<n; i++) {
            int result = premax[i] - suffmin[i];
            if(result <= k) {
                return i;
            }
        }
        return idx;
    }
};