#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(NULL){}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode *fast = head;
      ListNode *slow = head;
      while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
        if(slow==fast)
          break;
      }
      if(fast==nullptr || fast->next == nullptr){
        return NULL;
      }
      fast = head;
      while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
};