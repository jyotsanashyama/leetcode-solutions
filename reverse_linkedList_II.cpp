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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left==right) return head;   ///STEP1:

        ListNode* curr=head;
        ListNode* prev=NULL;

        ///STEP2
        ///Move curr1 to left-th node and prev to one before of curr
        for(int i=1;i<left;i++){
            prev=curr;
            curr=curr->next;
        }

        ListNode* beforeLeft=prev;    ///node before left-th node
        ListNode* next=NULL;
        ListNode* lastOfSubList=curr;  ///left-th node will be the last node after reversal

        ///STEP3
        ///reverse between left and right
        for(int i=0;i<(right-left+1); i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ///STEP4
        ///Connect with 1st part
        if(beforeLeft!=NULL){
            beforeLeft->next=prev;   ///connect beforeLeft to start of the reversed sublist
        }else{
            head=prev;   ///update head, if reversing starts from head
        }


        /// STEP5:
        ///Connect end of reversed sublist to the remaining part
        lastOfSubList->next=curr;

        return head;
    }
};
