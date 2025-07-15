class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *prev = head;
        ListNode *curr = head->next;
        if (!curr || !curr->next)
            return {-1, -1};

        ListNode *nxt = curr->next;
        int index = 1;
        int fcp = -1, pcp = -1; 
        int minDist = INT_MAX;
 
        while (nxt != nullptr)
        {
            if ((curr->val > prev->val && curr->val > nxt->val) ||
                (curr->val < prev->val && curr->val < nxt->val))
            {

                if (fcp == -1)
                {
                    fcp = index;
                    pcp = index;
                }
                else
                {
                    minDist = min(minDist, index - pcp);
                    pcp = index;
                }
            }

            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            index++;
        }

        if (minDist == INT_MAX)
        {
            return {-1, -1};
        }

        return {minDist, pcp - fcp};
    }
};
