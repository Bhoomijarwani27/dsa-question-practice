class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1){
            unordered_map<int, int> count;

            for(int x: nums){
                count[x]++;
            }
            int ans = -1;

            for(int x : nums){
                if(count[x] == 1){
                    ans = max(ans,x);
                }
            }

            return ans;
        }
        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }
        int ans = -1;

        int firstCount = 0;
        for(int x : nums){
            if(x == nums[0]){
                firstCount++;
            }
        }
        if(firstCount == 1){
            ans = max(ans, nums[0]);
        }
        int lastCount = 0;
                for (int x : nums) {
            if (x == nums[n - 1]) {
                lastCount++;
            }
        }
         if (lastCount == 1) {
            ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};