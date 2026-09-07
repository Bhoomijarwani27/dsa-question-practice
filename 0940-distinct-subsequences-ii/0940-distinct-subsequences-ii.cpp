class Solution {
public:
    int distinctSubseqII(string s) {
         const int MOD = 1e9 + 7;

        int total = 0;
        int  end[26] = {0};

        for(char c : s){
            int index = c -'a';

            int oldTotal = total;

            int newsubsequences = (oldTotal + 1 - end[index] + MOD) % MOD;

            total = (total + newsubsequences) % MOD;

            end[index] = (end[index] + newsubsequences) % MOD;
        }
        return total;
    }
};