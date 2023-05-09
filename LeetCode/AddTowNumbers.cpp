#include <iostream>
using namespace std;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *sum = new ListNode();
        ListNode *head = sum;
        int carry = 0;

        while (l1 || l2 || carry != 0)
        {
            int total = 0;

            if (l1)
            {
                total += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                total += l2->val;
                l2 = l2->next;
            }

            total += carry;
            carry = 0;

            if (total > 9)
            {
                total -= 10;
                carry = 1;
            }

            sum->next = new ListNode(total);
            sum = sum->next;
        }
        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    auto l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    auto l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    auto sol = new Solution();
    auto sum = sol->addTwoNumbers(l1, l2);

    return 0;
}


