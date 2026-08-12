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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> uniqueNums(nums.begin(), nums.end());

        ListNode* start = new ListNode();
        ListNode* ans = start; 
        while(head != nullptr){
            if(uniqueNums.contains(head->val)){
                ListNode* temp = head;
                head = head->next;
                temp->next = nullptr;
                continue;
            }
            start->next = head;
            head=head->next;
            start = start->next;
            start->next = nullptr;
        }

        return ans->next;

    }
};