#include<iostream>
#include<vector>
using namespace std;
//problem link : https://leetcode.com/problems/majority-element/description/

// time complexity O(n) moore's voting algorithm 
int main(){
     vector<int>nums = {2,1,3};
          int freq =0, ans = 0;
    for(int i=0;i<nums.size();i++) {
        if(freq == 0){
            ans = nums[i];
        }
        if(ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
 
    }
    // if no major element 
        int count =0; 
        for (int val:nums){
            if(val == ans) {
                count ++ ;
            }
        }
        if(count > nums.size()/2) {
            cout << ans;
        } else {
            cout << -1;
        }
       
    }

        
    