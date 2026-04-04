class Solution {
public:
    void backtrack(int open,int close,vector<string>&res,string s){
        if(open==0 && close==0){
            res.push_back(s);
            return;
        }
        if(open>0){
            backtrack(open-1,close,res,s+'(');
        }
        if(close>open){
            backtrack(open,close-1,res,s+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s="";
        backtrack(n,n,res,s);
        return res;
    }
};