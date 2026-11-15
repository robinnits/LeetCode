class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int ans = 1;
        int l =0, r = 1;
        while(r<n) {
            if(nums[r] > nums[r-1]){
                ans = max(r-l+1, ans);
                r++;
            }else {
                l = r;
                r++;
            }
        }
        l=0, r = 1;
        while(r<n) {
            if(nums[r] < nums[r-1]){
                ans = max(r-l+1, ans);
                r++;
            }else {
                l = r;
                r++;
            }
        }
        return ans;
    }
};