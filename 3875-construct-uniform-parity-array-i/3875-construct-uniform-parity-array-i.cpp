class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2;

        for(int i = 0; i<n; i++){
            if(nums1[i] %2 == 0){
                nums2.push_back(nums1[i]);
            }
        }
        return true;
    }
};