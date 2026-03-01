#include <iostream>
#include<vector>
using namespace std;
// problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
int main(){
    vector<int>prices = {7,1,3,6,4,1};
    int maxProfit = 0;
    int bestBuy = prices[0];
    for(int i=0;i<prices.size();i++){
       if(prices[i] > bestBuy){
          maxProfit = max(maxProfit,prices[i] - bestBuy);
    } 
    bestBuy = min(bestBuy , prices[i]);

}
 cout << maxProfit;



return 0;     
}