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
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k, nullptr);

        ListNode *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        int div = cnt / k;
        int mod = cnt % k;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        for (int i = 0; curr != NULL and i < k; i++)
        {
            ans[i] = curr;
            for (int count = 1; count <= div + (mod > 0 ? 1 : 0); count++)
            {
                prev = curr;
                curr = curr->next;
            }
            mod--;
            if (prev != nullptr)
            {
                prev->next = nullptr; // Cut the list
            }
        }
        return ans;
    }
};