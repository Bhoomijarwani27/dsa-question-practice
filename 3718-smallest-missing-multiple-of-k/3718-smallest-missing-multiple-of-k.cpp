class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int value = k;

        while (s.count(k)) {
            k += value;
        }

        return k;
    }
};