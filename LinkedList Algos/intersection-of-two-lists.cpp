class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA, *prev1, *prev2, *temp2 = headB;
        while(temp1 != NULL && temp2 != NULL){
            prev1 = temp1, prev2 = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp1 == NULL) prev1->next = headB;
        else prev2->next = headA;
        ListNode *head = (temp1 == NULL?headA:headB);
        ListNode *slow = head, *fast = head;
        if(!head) return nullptr;
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            // else return nullptr;
        }
        while(slow != fast && fast!=NULL);
        if(fast == nullptr) {
            if(temp1 == NULL) prev1->next = NULL;
            else prev2->next = NULL;
            return nullptr;
        }
        fast = head;
        while(slow != fast ){
            slow = slow->next;
            fast = fast->next;
        }
        if(temp1 == NULL) prev1->next = NULL;
        else prev2->next = NULL;
        return slow;
    }
};
