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
        ListNode* curr=head;

        ///base case
        if(curr->next==NULL){
            return NULL;
        }

        ///find size
        int size=0;
        while(curr->next!=NULL){
            curr=curr->next;
            size++;
        }

        ///size-k:
        ListNode* ptr=head;

        if(size==k){
            return ptr->next;
        }
        for(int i=0;i<(size-n);i++){
            ptr=ptr->next;
        }



        if(ptr!=NULL && ptr->next!=NULL){
            ptr->next=ptr->next->next;
            return head;
        }
        return head;
    }
};
