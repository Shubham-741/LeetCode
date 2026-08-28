class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* newhead = new ListNode(head->val);
        ListNode* currOld = head->next;
        ListNode* currhead = newhead;

        while (currOld != NULL) {
            currhead->next = new ListNode(currOld->val);
            currOld = currOld->next;
            currhead = currhead->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = newhead;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        int ans = 0;

        while (head != NULL && prev != NULL) {
            ans = max(ans, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }

        return ans;
    }
};