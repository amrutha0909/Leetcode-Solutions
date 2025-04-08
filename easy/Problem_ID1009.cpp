class Solution {
    public:
        int bitwiseComplement(int n) {
            vector<int>num;
            if(n==0){
                return 1;
            }
            else if(n==1){
                return 0;
            }
            while(n>0){
                num.push_back(n%2);
                n/=2;
            }
            reverse(num.begin(),num.end());
            for(int i=0;i<num.size();i++){
                if(num[i]==0){
                    num[i]=1;
                }
                else{
                    num[i]=0;
                }
            }
            int sum=0;
            int j=0;
            for(int i=num.size()-1;i>-0;i--){
                sum+=num[i]*pow(2,j);
                j++;
            }
            return sum;
        }
    };