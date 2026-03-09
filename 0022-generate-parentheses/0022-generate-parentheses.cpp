class Solution {
public:
    void backtrack(int open, int close, vector<string>&result, string pattern){
        if(open==0 && close==0){
            result.push_back(pattern);
            return;
        }
        if(open>0){
            backtrack(open-1,close,result,pattern+'(');
        }
        if(close>open){
            backtrack(open,close-1,result,pattern+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        backtrack(n,n,result,"");
        return result;
    }
};