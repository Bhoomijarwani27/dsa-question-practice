class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int ,int>mp;

        for(auto &seat: reservedSeats){
            int row = seat[0];
            int col = seat[1];

            if(col >=2 && col <= 9){
                mp[row] |= (1 << (col - 2));
            }
        }

        int LEFT = 0b00001111;
        int MIDDLE = 0b00111100;
        int RIGHT = 0b11110000;

        int ans = 0;
    

    ans += (n - mp.size()) * 2;

    for(auto &[row , mask] : mp){
        if((mask & LEFT) == 0 &&
        (mask & RIGHT) == 0) {
            ans += 2;
        }
        else if ((mask & LEFT) == 0 ||
                     (mask & MIDDLE) == 0 ||
                     (mask & RIGHT) == 0) {

                ans += 1;
            }
        }
        return ans;

    }
};