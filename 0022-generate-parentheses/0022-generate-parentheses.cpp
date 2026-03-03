class Solution {
public:
    void backtrack(vector<string>&result, string p, int open, int close){
        if(open==0 && close==0){
            result.push_back(p);
            return;
        }
        if(open>0){
            backtrack(result,p+'(',open-1,close);
        }
        if(close>open){
            backtrack(result,p+')',open,close-1);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        backtrack(result,"",n,n);
        return result;
    }
};