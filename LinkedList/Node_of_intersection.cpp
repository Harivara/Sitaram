// Find the intersecting Node 


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;
    }
};


// 1. Pointer a traverses list A, then list B.
// 2. Pointer b traverses list B, then list A.
// 3. If the lists intersect, the pointers meet at the intersection node. If they don't, both eventually become nullptr.
// Why switch heads?
// Suppose list A has 5 nodes before the shared portion and list B has 2. Switching heads makes both pointers traverse the same total distance:
// - a: A then B
// - b: B then A
// This compensates for the difference in list lengths without counting nodes.