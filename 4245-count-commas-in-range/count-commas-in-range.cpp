class Solution {
private:
    int digit(int num) {
        int cnt = 0;
        while(num != 0) {
            cnt++;
            num /= 10;
        }
        return cnt;
    }
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i = n; i> 999; i--) {
            int d = digit(i);
            int temp = d / 3;
            if(d%3 == 0) ans+=temp-1;
            else ans+=temp;
        }
        return ans;
    }
};