#include <bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
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
  void disp(ListNode *node)
  {
    while (node->next)
    {
      cout << node->val << " -> ";
      node = node->next;
    }
    cout << node->val << endl;
  }

  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (!list1 && !list2)
      return nullptr;
    else if (list1 && !list2)
      return list1;
    else if (!list1 && list2)
      return list2;
    else
    {
      ListNode *res = new ListNode();
      ListNode *curr = res;
      ListNode *prev = res;
      while (list1 && list2)
      {
        if (list1->val < list2->val)
        {
          curr->val = list1->val;
          curr->next = new ListNode();
          list1 = list1->next;
        }
        else
        {
          curr->val = list2->val;
          curr->next = new ListNode();
          list2 = list2->next;
        }

        prev = curr;
        curr = curr->next;
      }

      // ? if list1 still has elements
      if (list1)
      {
        prev->next = list1;
      }

      // ? if list2 still has elements
      if (list2)
      {
        prev->next = list2;
      }

      return res;
    }

    return nullptr;
  }
};

int main(int argc, char const *argv[])
{
  Solution sol;

  ListNode *node1 = new ListNode(1);
  node1->next = new ListNode(2);
  node1->next->next = new ListNode(4);

  ListNode *node2 = new ListNode(1);
  node2->next = new ListNode(3);
  node2->next->next = new ListNode(4);

  sol.disp(sol.mergeTwoLists(node1, node2));

  return 0;
}