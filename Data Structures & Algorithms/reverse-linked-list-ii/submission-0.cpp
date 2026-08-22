class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev_left = dummy;
        for (int i = 1; i < left; ++i) {
            prev_left = prev_left->next;
        }
        ListNode* start = prev_left->next;

        ListNode* end = start;
        for (int i = left; i < right; ++i) {
            end = end->next;
        }
        ListNode* next_right = end->next;

        prev_left->next = nullptr; 
        end->next = nullptr;       

        reverseList(start);

        prev_left->next = end;
        start->next = next_right;


        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};