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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int n = b - a + 2;
        ListNode * head = list1;
        ListNode* start = list1;
        ListNode* end = list1;
        while(n--){
            end=end->next;
        }
        while(--a){
            start = start->next;
            end=end->next;
        }

        start->next = list2;
        while(list2->next){
            list2 = list2->next;    
        }

        list2->next = end;

        return head;
    }
};