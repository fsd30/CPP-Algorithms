#include <iostream>

using namespace std;

// linkedlist node
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode *next) : val(x), next(next){};
};

// reverse linkedlist
ListNode *reverseLinkedList(ListNode *head) {
  ListNode *nextNode, *prev = NULL;
  while (head) {
    nextNode = head->next;
    head->next = prev;
    prev = head;
    head = nextNode;
  }
  return prev;
}

// to display linkedlist
void printList(ListNode *head) {
  ListNode *curr = head;
  while (curr->next != NULL) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << curr->val << endl;
}

int main() {
  // create linkedlist 1->2->3->4
  ListNode *c = new ListNode(4, NULL);
  ListNode *b = new ListNode(3, c);
  ListNode *a = new ListNode(2, b);
  ListNode *head = new ListNode(1, a);

  cout << "before reverse: ";
  printList(head);
  ListNode *reversedLL = reverseLinkedList(head);
  cout << "after reverse: ";
  printList(reversedLL);
  return 0;
}
