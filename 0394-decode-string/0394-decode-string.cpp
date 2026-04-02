class Solution {
public:
    string decodeString(string s) {
       
        string num="";
        stack<string>stk;
        string str="";
        for(char c:s){
            if(isdigit(c)){
                num+=c;
            }
            else if(c=='['){
                stk.push(str);
                stk.push(num);
                num="";
                str="";
            }
            else if(c==']'){
                int f=stoi(stk.top());
                stk.pop();
                string curr=stk.top();
                stk.pop();
                string temp="";
                for(int i=0;i<f;i++){
                    temp+=str;
                }
                str=curr+temp;
            }
            else{
                str+=c;
            }
        }
        return str;
    }
};