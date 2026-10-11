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
    ListNode* mergeSortedList(ListNode *head1, ListNode *head2){
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }

            curr = curr->next;
        }

        curr->next = (head1 != nullptr) ? head1 : head2;

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int k = lists.size();
        while (k > 1) {
            int newSize = (k + 1) / 2;
            for (int i = 0; i < k / 2; i++) {
                lists[i] = mergeSortedList(
                    lists[i],
                    lists[i + newSize]
                );
            }
            k = newSize;
        }
        return lists[0];
    }
};
