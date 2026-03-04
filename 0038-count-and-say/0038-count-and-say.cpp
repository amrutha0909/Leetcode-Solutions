class Solution {
public:
    string helper(int n, string s) {
        if(n == 1)
            return s;

        string res = "";
        int count = 1;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                count++;
            } else {
                res += to_string(count);
                res += s[i-1];
                count = 1;
            }
        }

        // last group
        res += to_string(count);
        res += s.back();

        return helper(n - 1, res);
    }

    string countAndSay(int n) {
        return helper(n, "1");
    }
};