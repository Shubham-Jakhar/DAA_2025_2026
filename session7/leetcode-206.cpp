class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next=NULL;
        ListNode* newHead=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=newHead;
            newHead=head;
            head=next;
        }
        return newHead;
    }
};