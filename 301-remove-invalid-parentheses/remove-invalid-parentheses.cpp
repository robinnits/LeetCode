class Solution {
public:
    bool valid(string s) {
        int bal = 0;

        for(char c : s) {
            if(c == '(')
                bal++;
            else if(c == ')') {
                bal--;
                if(bal < 0)
                    return false;
            }
        }

        return bal == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while(!q.empty() && !found) {
            int sz = q.size();

            while(sz--) {
                string curr = q.front();
                q.pop();

                if(valid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                if(found)
                    continue;

                for(int i = 0; i < curr.size(); i++) {
                    if(curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) + curr.substr(i + 1);

                    if(!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};