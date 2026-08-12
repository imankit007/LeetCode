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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;
        int firstIndex = -1;
        int prevIndex = -1;
        int index = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr->next){
            if((curr->val < prev->val && curr->val<curr->next->val) || (curr->val > prev->val && curr->val>curr->next->val)){
                if(firstIndex == -1)
                    firstIndex = index;
                if(prevIndex!= -1)
                    minDistance = min(minDistance, index - prevIndex);
                prevIndex = index;
            }
            ++index;
            prev= curr;
            curr= curr->next;   
        }
        if(minDistance == INT_MAX)
            return {-1,-1};
        return {minDistance, prevIndex - firstIndex};

    }
};