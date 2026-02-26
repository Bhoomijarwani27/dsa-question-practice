#include <iostream>
#include<climits>
#include<vector>
using namespace std; 
//problem link : https://leetcode.com/problems/maximum-subarray/
// Kadane's Algorithm it use only one loop 
// most optimsed time complexity 0(n)
int main(){
        vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
        int maxSum = INT_MIN;
        int currSum = 0;
      for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            maxSum = max(currSum,maxSum);
            if (currSum < 0){
                currSum = 0;
            }
        }
    
     cout << maxSum;
    }