#include <iostream>
#include<vector>
using namespace std;
// problem link : https://leetcode.com/problems/container-with-most-water/
int main(){
     vector<int>height = {1,8,6,2,5,4,8,3,7} ;
    

        int maxWater = 0; 
        int lp =  0, rp = height.size()-1;
        while(lp < rp){
            int w = rp-lp;
            int ht = min(height[lp],height[rp]);
            int currwater = w*ht;
            maxWater = max(maxWater,currwater);
            height[lp] < height[rp] ? lp++:rp--;
        }
        cout << maxWater  << endl;

        
    
return 0;     
}