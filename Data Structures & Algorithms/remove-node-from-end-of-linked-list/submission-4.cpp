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
        ListNode* temp= head;
        int len= 0;
        while(temp){
            len++;
            temp= temp->next;
        }
        int x= len-n;
        ListNode* prev= head;
        if(x==0){
            head= head->next;
        }
        if(x>0){
            x--;
        }
        while(x){
            x--;
            prev= prev->next;
        }
        if(prev->next==NULL){
            prev= prev->next;
        }
        else{
            prev->next= prev->next->next;
        }
        return head;
    }
};
