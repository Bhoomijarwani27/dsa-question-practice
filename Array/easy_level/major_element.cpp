#include<iostream>
#include<vector>
using namespace std;
//problem link : https://leetcode.com/problems/majority-element/description/
int main(){
     vector<int>nums = {2,3,3};
        int n = nums.size();
        for(int i=0;i<n ; i++){
           int  count =0;
           for(int j=0;j<n;j++){
              if (nums[i] == nums[j]){
                count++;
            }
            if (count > n/2){
                cout << nums[i];
                return 0;
            }

           }
        }

            return -1 ;
        
        return 0;
        
    };
    
