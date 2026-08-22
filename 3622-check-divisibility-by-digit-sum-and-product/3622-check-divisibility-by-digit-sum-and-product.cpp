class Solution {
public:
    bool checkDivisibility(int n) {
        int  sum  = 0;
        int  product = 1;
        int original  = n;

        while ( n > 0){
            int digit = n % 10;
             sum += digit;
             product *= digit;

             n = n / 10;
        }
         int ans = sum + product;

        return original % ans == 0; 


         
     

        
    }
};