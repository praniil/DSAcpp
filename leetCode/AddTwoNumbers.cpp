#include <iostream>
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
        ListNode *head = new ListNode();
        ListNode *sum = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int total = x + y + carry;
            carry = total / 10;
            sum->next = new ListNode(total % 10);
            sum = sum->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return head->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(5);
    l1->next = new ListNode(10);
    l1->next->next = new ListNode(25);
    ListNode *l2 = new ListNode();
    l2->next = new ListNode(15);
    l2->next->next = new ListNode(20);
    ListNode *sum;
    Solution s1;
    sum = s1.addTwoNumbers(l1, l2);
    while (sum != nullptr)
    {
        std::cout << sum->val << " ";
        sum = sum->next;
    }
}