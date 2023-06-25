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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // vector<int>v;
        // ListNode* mergeList;
        // ListNode* temp = new ListNode();

        // while(list1 != NULL){
        //     v.push_back(list1->val);
        //     list1 = list1->next;
        // }

        // while(list2 != NULL){
        //     v.push_back(list2->val);
        //     list2 = list2->next;
        // }
        // sort(v.begin(), v.end());

        // mergeList = temp;
        // for(int i=0; i<v.size(); i++){
        //     temp->next = new ListNode(v[i]);
        //     temp = temp->next;
        // }
        // mergeList = mergeList->next;
        
        // return mergeList;

        if(list1 == NULL){ 
            return list2;
        }else if(list2 == NULL){ 
            return list1;
        }
        else if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};