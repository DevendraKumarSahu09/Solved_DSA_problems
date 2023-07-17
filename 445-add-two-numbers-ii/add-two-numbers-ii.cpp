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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;

        stack<int>s1;
        stack<int>s2;

        while(l1){
            int value = l1->val ; 
            s1.push(value);
            l1 = l1->next;
        }
        while(l2){
            int value = l2->val ; 
            s2.push(value);
            l2 = l2->next;
        }

        int carry = 0;
        while(!s1.empty() && !s2.empty()){
            int value = s1.top() + s2.top() + carry ;
            carry = value/10;
            l3->next = new ListNode(value%10);
            l3 = l3->next;
            s1.pop();
            s2.pop();
        }
        while(!s1.empty() && s2.empty()){
            int value = s1.top()+ carry ;
            carry = value/10;
            l3->next = new ListNode(value%10);
            l3 = l3->next;
            s1.pop();
        }
        while(!s2.empty() && s1.empty()){
            int value = s2.top() + carry ;
            carry = value/10;
            l3->next = new ListNode(value%10);
            l3 = l3->next;
            s2.pop();
        }
        
        if(carry){
            l3->next = new ListNode(carry);
        }
        return reverseList(head->next);
    }
};