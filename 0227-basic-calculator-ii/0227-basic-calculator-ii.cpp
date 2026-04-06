class Solution {
public:
    int calculate(string s) {
        stack<int>stk;
        int num=0;
        char sign='+';
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            if((s[i]!=' '&&!isdigit(s[i]))||i==s.size()-1){
                if(sign=='+')stk.push(num);
                else if(sign=='-')stk.push(-num);
                else if(sign=='*'){
                    int val=stk.top();stk.pop();
                    stk.push(val*num);
                }
                else{
                    int val=stk.top();stk.pop();
                    stk.push(val/num);
                }
                sign=s[i];
                num=0;
            }
        }
        int result=0;
        while(!stk.empty()){
            result+=stk.top();
            stk.pop();
        }
        return result;
    }
};