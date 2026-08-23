class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int LeftSum = 0,  RightSum = 0;
        int LeftQ = 0, RightQ = 0;

        for(int i = 0; i<n/2 ;i++){
            if(num[i] == '?')
               LeftQ++;
            else 
               LeftSum += num[i] - '0';
        }

        for(int i = n/2; i<n; i++){
            if(num[i] == '?')
               RightQ++;
            else 
               RightSum += num[i] - '0';
        }

        int QDiff = LeftQ - RightQ ;
        int SumDiff = LeftSum - RightSum ;

        if(QDiff % 2 != 0)
           return true;

        return SumDiff != (-QDiff /2)* 9;   
    }
};