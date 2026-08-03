class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) { 
     int n = stoneValue.size();

     vector<int> dp(n+1,INT_MIN);
     dp[n] = 0;

     for(int i = n -1; i>=0; i--){ 
     int sum = 0;
     for(int k=0; k<3 && i+k <n; k++){ // Check all 3 possible moves 
        sum += stoneValue[i + k]; //Points collected in this move
        dp[i] = max(dp[i], sum-dp[i + k+ 1]); // Keep the best move

        }
     } 

     if(dp[0]>0)
        return "Alice";
     if(dp[0] < 0)
     return "Bob";
    else
     return "Tie";
    }
};