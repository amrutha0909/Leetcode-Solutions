class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int sum1=0;
            int sum2=0;
            int i=0;
            int maximum=questions[0][0];
            for(int i=0;i<questions.size();i++){
                if(questions[i][0]>maximum){
                    maximum=questions[i][0];
                }
            }
            while(i<questions.size()){
                sum1+=questions[i][0];
                i+=questions[i][1]+1;
                
            }
            sum1=max(maximum,sum1);
            int j=1;
            while(j<questions.size()){
                sum2+=questions[j][0];
                j+=questions[j][1]+1;
                
            }
            sum2=max(maximum,sum2);
            if(sum1>=sum2){
                return sum1;
            }
            return sum2;
        }
    };