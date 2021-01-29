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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *res = new ListNode();
      ListNode *cur = res;
      if(l1==nullptr){
          return l2;
      }else if(l2==nullptr){
          return l1;
      }
      if(l1->val>l2->val){
          cur = l2;
          cur->next=mergeTwoLists(l1,l2->next);
      }else{
          cur = l1;
          cur->next=mergeTwoLists(l1->next, l2);
      }
      return cur;
    }
    
};