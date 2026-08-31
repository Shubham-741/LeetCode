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
        int prevCritical = -1;
        int last = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int minDist = INT_MAX;

        int pos = 1;

        while(curr!=NULL && curr->next!=NULL){
            ListNode* next = curr->next;

            bool isCritical = ( (curr->val > prev->val && curr->val > next->val) ||  (curr->val < prev->val && curr->val < next->val) );

            if(isCritical){
                if(first==-1){
                    first=pos;
                }
                else{
                    minDist = min(minDist, pos - prevCritical);
                }

                prevCritical = pos;
                last = pos;

            }

            pos++;
            prev = curr;
            curr = next;
        }

        if(first == last){
            return {-1,-1};
        }

        int maxDist = last-first;

        return {minDist, maxDist};
        
    }
};