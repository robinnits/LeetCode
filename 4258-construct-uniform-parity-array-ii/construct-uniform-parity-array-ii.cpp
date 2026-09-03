class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = 0, even = 0;
        int mne = INT_MAX, mno = INT_MAX;
        for(int i=0; i<n; i++) {
            if(nums1[i] %2 == 0) {
                even++;
                mne = min(mne, nums1[i]);
            }
            else {
                odd++;
                mno = min(mno, nums1[i]);
            }
        }
        if(even == n) return true;
        else if(mne > mno) return true;
        return false;
    }
};