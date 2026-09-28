class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cnt = 0;
        int n = s.length();
        for(int i= 0; i<n; i++) {
            if(s[i]=='(') {
                cnt++;
                ans = max(ans, cnt);
            }
            if(s[i]==')') {
                cnt--;
            }
        }
        return ans;
    }
};