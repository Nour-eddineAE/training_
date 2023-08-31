#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void disp(ListNode *node)
{
  while (node->next)
  {
    cout << node->val << " -> ";
    node = node->next;
  }
  cout << node->val << endl;
}