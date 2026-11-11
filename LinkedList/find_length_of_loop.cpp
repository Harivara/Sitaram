class Solution {
public:
    int countNodesinLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect the loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find the starting node of the loop
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // Step 3: Count nodes in the loop
                int count = 1;
                Node* curr = slow->next;

                while (curr != slow) {
                    count++;
                    curr = curr->next;
                }

                return count;
            }
        }

        return 0; // No loop
    }
};