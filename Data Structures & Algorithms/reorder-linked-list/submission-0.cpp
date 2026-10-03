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
ListNode* rev(ListNode* head)
    {
        if(head==NULL) return nullptr;
        ListNode *p=head,*q=NULL,*r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return;
        ListNode* p=head,*h=head,*p1=head;
        while(p!=NULL && p->next!=NULL)
        {
            p=p->next->next;
            h=h->next;
        }
        p=h->next;
        h->next=NULL;
        ListNode* q=rev(p),*ans=NULL,*ans1=NULL;
        while(q!=NULL)
        {
            ans=p1->next;
            ans1=q->next;
            p1->next=q;
            q->next=ans;
            p1=ans;
            q=ans1;
        }
    }
};
