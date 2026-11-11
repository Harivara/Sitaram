https://leetcode.com/problems/remove-nodes-from-linked-list/description/


// Reverse the Nodes and find all the max nodes

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int maxi = head->val;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val < maxi) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
                maxi = curr->val;
            }
        }

        return reverse(head);
    }
};