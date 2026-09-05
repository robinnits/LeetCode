class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r = n-1;
        int ans = 0;
        while(l<r) {
            int temp = min(height[l], height[r]) * (r -l);
            ans = max(ans, temp);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};