class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->next != nullptr &&
                curr->val == curr->next->val) {

                int duplicate = curr->val;

                while (curr != nullptr &&
                       curr->val == duplicate) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }

                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};


Node* solve(Node* head) {
    Node dummy(0);
    Node* tail = &dummy;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->next != nullptr &&
            curr->data == curr->next->data) {

            int duplicate = curr->data;

            while (curr != nullptr &&
                   curr->data == duplicate) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }

            tail->next = curr;
        } else {
            tail->next = curr;
            tail = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}