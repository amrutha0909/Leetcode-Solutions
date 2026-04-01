class Solution {
public:
    string decodeString(string s) {
        stack<string>stk;
        string curr="";
        string num="";
        for(char c:s){
            if(c=='['){
                stk.push(curr);
                stk.push(num);
                curr="";
                num="";
            }
            else if(c==']'){
                int n=stoi(stk.top());
                stk.pop();
                string prev=stk.top();
                stk.pop();
                string temp="";
                for(int i=0;i<n;i++){
                    temp+=curr;
                }
                prev=prev+temp;
                curr=prev;
            }
            else if(isdigit(c)){
                num+=c;
            }
            else{
                curr+=c;
            }
        }
        return curr;
    }
};