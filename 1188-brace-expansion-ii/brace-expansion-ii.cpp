class Solution {
public:

    set<string> parse(string &s, int &i) {

        set<string> result;
        set<string> current;

        current.insert("");

        while(i < s.size() && s[i] != '}') {

            if(s[i] == ',') {


                result.insert(current.begin(), current.end());

                current.clear();
                current.insert("");

                i++;
            }
            else if(s[i] == '{') {

                i++; 

                set<string> inside = parse(s, i);

                i++; 
                set<string> next;

                for(auto &a : current) {
                    for(auto &b : inside) {
                        next.insert(a + b);
                    }
                }

                current = next;
            }
            else {

                char c = s[i];

                set<string> next;

                for(auto &str : current) {
                    next.insert(str + c);
                }

                current = next;

                i++;
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};