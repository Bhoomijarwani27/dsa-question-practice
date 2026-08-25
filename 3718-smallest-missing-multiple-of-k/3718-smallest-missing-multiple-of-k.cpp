class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int value = k; 
        int ans;
        while(true){
            bool found = false;
        
        for(int i = 0 ; i<n; i++){
            if(nums[i] == k){
               found = true;
               break;

            }
        }    
            if(!found){
                return k;
                }   
                
            
            k +=value;
        }
    }
};