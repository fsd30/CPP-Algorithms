class Solution {
public:
    ListNode*  reverse(ListNode *head){
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow =  head, *fast= head, *prev;
        
        while(fast){
            fast = fast->next;
            if(fast) fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        ListNode *mid = reverse(slow), *temp;
        temp = head, fast = mid;
        bool ans = true;
        while(temp && fast){
            if(temp->val != fast->val){ 
                ans = false;
                break;    
            };
            temp= temp->next;
            fast = fast->next;
        }
        mid = reverse(mid);
        prev->next = mid;
        return ans;
        
    }
};
