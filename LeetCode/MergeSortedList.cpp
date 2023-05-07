
// Definition for singly-linked list.
struct ListNode
{

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode *mergedList = list1;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                auto temp1 = list1;
                auto temp2 = list2;

                list2 = list2->next;
                list1 = temp2;
                list1->next = temp1;
                mergedList = list1;
            }
            else
            {
                if (list1->next == nullptr || list1->next->val > list2->val)
                {
                    auto temp1 = list1->next;
                    auto temp2 = list2->next;

                    list1->next = list2;
                    list2->next = temp1;

                    list1 = list1->next;
                    list2 = temp2;
                }
                else
                {
                    list1 = list1->next;
                }
            }
        }

        return mergedList;
    }
};

int main(int argc, char const *argv[])
{
    auto sol = new Solution();
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    / list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    auto result = sol->mergeTwoLists(list1, list2);
    return 0;
}
