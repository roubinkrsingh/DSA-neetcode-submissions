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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        if(n==1 && head->next==nullptr) return nullptr;

        ListNode *len=head;
        int sz=0;
        while(len!=nullptr){
            sz++;
            len=len->next;
        }
        int nodeToRemove=sz-n;
        if(nodeToRemove<0) return head;
        ListNode *prev=nullptr;
        ListNode * curr=head;
        int x=0;
        while(curr!=nullptr){
            if(x==nodeToRemove){
                if(prev==nullptr) return head->next;
                prev->next=curr->next;
                return head;
            }
            prev=curr;
            curr=curr->next;
            x++;
        }
        return head;  
    }
};
