class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev = dummy, *cur = head;
        
        int i = 1;
        for(; i < m; ++i){
            prev = prev->next;
            cur = cur->next;
        }
        
        ListNode *rdummy = prev;
        ListNode *rtail = cur;
        
        for(; i <= n; ++i){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        
        rdummy->next = prev;
        rtail->next = cur;
        
        return dummy->next;
    }
};