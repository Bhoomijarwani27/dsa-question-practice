/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;

        int minDist = INT_MAX;
        int maxDist = 0;

        int index = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != nullptr && curr->next != nullptr){
            int left = prev->val;
            int mid = curr->val;
            int right = curr->next->val;

            bool isCritical =
                (mid > left && mid > right) ||
                (mid < left && mid < right);

                if (isCritical) {
                   if (first == -1) {
                    first = index;
                }
                else {
                    // Current CP aur previous CP ka distance
                    int distance = index - last;

                    minDist = min(minDist, distance);
                }
                 last = index;
            }  
             prev = curr;
            curr = curr->next;
             index++; 
        }
        if (first == -1 || first == last) {
            return {-1, -1};
        }

         maxDist = last - first;

        return {minDist, maxDist};
    }
};