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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        int cnt=0;
        ListNode *unt=head;
        while(unt!=nullptr){
            unt=unt->next;
            cnt++;
        }
        ListNode *first=head,*second=head;
        int temp=0;
        while(temp!=k-1 and first!=nullptr){
            first=first->next;
            temp++;

        }
        int gg=cnt-k;
        while(gg!=0 and second!=nullptr){
            second=second->next;
            gg--;
        }
        swap(first->val,second->val);
        return head;
    }
};