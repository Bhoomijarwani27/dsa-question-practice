class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MAX;
        int largest =INT_MIN;


        for(int i = 0; i<n ;i++){
        smallest = min(smallest, nums[i]);
        largest = max(largest, nums[i]);
        }

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int>ans;

        for(int i= smallest ;i<largest ;i++){
            if (st.find(i) == st.end()) {
                ans.push_back(i);

        }


        }
        return ans;
    }
};