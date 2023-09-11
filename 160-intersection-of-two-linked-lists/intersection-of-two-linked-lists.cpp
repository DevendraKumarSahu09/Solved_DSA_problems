/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int getLength(ListNode* head) {

        int count = 0;

        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        while(lenA > lenB){
            headA = headA->next;
            lenA--;
        }

        while(lenA < lenB){
            headB = headB->next;
            lenB--;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};