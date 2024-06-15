class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        ListNode* start=head;
        ListNode* end=head;
        ListNode* next=NULL;

        ///finding size
        int size=0;
        ListNode* ptr=head;
        while(ptr!=NULL){
            ptr=ptr->next;
            size++;
        }

        ///starting point
        for(int i=1;i<k;i++){
            start=start->next;
        }
        ///starting again for end
        for(int i=1;i<(size-k+1);i++){
            end=end->next;
        }

        int temp=0;
        temp=start->val;
        start->val=end->val;
        end->val=temp;

        return head;

    }
};
