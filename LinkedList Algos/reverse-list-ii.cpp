class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *curr, *nxt;
        prev = NULL, curr = head;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int count = 1;
        ListNode *prev1, *next2, *temp1, *temp2;
        prev1 = NULL, next2 = NULL;
        temp1 = temp2 = head;
        ListNode *temp = head;
        while(temp and count <= right){
            temp = temp->next;
            count++;
            if(count <= left){
                prev1 = temp1;
                temp1 = temp;
            }
            if(count <= right){
                temp2 = temp;
            }
        }
        next2 = temp2->next;
        temp2->next = NULL;
        ListNode *revHead = reverseList(temp1);
        if(prev1)
            prev1->next = revHead;
        else 
            head = revHead;
        temp1->next = next2;
        return head;
    }
};
