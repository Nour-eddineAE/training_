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

  /**
   * ? swaps a pair of nodes
   *
   * @param {ListNode *} head - The head of the list
   * @param {ListNode *} node - The node to swap(swap with next node)
   */
  void swap_pair(ListNode *&head, ListNode *node)
  {
    ListNode *prev = head;
    ListNode *curr = head;

    while (curr != node)
    {
      prev = curr;
      curr = curr->next;
    }

    // Piping
    node = curr->next->next;

    // if node is different of head
    if (prev != curr)
      prev->next = curr->next;

    // if node is head
    if (prev == curr)
      head = curr->next;

    curr->next->next = curr;
    curr->next = node;
  }

  ListNode *swapPairs(ListNode *head)
  {
    ListNode *node = head;

    while (node && node->next)
    {
      swap_pair(head, node);
      node = node->next;
    }

    return head;
  }
};

int main(int argc, char const *argv[])
{

  Solution sol;
  ListNode *node = new ListNode(1);
  node->next = new ListNode(2);
  node->next->next = new ListNode(3);
  node->next->next->next = new ListNode(4);
  node->next->next->next->next = new ListNode(5);

  sol.disp(node);                //  1 -> 2 -> 3 -> 4 -> 5
  sol.disp(sol.swapPairs(node)); //  2 -> 1 -> 4 -> 3 -> 5
  return 0;
}