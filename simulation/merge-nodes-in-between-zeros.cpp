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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* start = new ListNode();
        ListNode* temp = start;
        int curr = 0;
        while(head!=NULL){
            if(head->val!=0){
                curr+=head->val;
            }else{
                if(curr!=0){
                    temp->next = new ListNode(curr);
                    curr =0;
                    temp = temp->next;
                }
            }
            head = head->next;
        }
        return start->next;
    }
};