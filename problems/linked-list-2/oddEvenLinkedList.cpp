#include "../include.h"

/**
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 *
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input. 
 * The first node is considered odd, the second node even and so on ...
 *
 * Credits:
 * Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

void print(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* l1 = head;
    ListNode* l2 = head->next;
    ListNode* h2 = l2;
    l1->next = NULL;
    while (l2 != NULL && l2->next != NULL) {
        ListNode* t = l2->next;
        // 从l2删除
        ListNode* next = t->next;
        l2->next = next;
        l2 = l2->next;
        // 插入到l1
        l1->next = t;
        l1 = t;
    }
    l1->next = h2;
    return head;
}

int main() {
    ListNode* p = new ListNode(1);
    ListNode* temp = p;
    for (int i=0; i < 9; i++) {
        temp->next = new ListNode(i+2);
        temp = temp->next;
    }
    print(p);
    ListNode* output = oddEvenList(p);
    print(output);
}
