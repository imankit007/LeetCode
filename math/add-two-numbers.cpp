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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode l3;      
        ListNode * temp = &l3;
        
        int carry = 0;
        
        while(l1 || l2|| carry ){
            int  a = l1? l1->val : 0 , b = l2?l2->val : 0;
            
            int sum = a + b + carry;
            temp->next = new ListNode(sum % 10);
            
            carry = sum / 10;
            
            l1 = l1?l1->next : nullptr;
            l2 = l2?l2->next : nullptr;
            
            temp = temp->next;
            
        }
        
        return l3.next;
    }
};