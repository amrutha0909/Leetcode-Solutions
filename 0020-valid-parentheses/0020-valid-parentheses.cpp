class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mpp={{')','('},{']','['},{'}','{'}};
        stack<char>stk;
        for(char c:s){
            if(c=='(' || c=='[' || c=='{'){
                stk.push(c);
            }
            else{
                if(stk.empty())return false;
                else if(stk.top()!=mpp[c])return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};