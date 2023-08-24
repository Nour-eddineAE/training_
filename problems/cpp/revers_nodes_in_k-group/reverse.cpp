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
    while (node && node->next)
    {
      cout << node->val << " -> ";
      node = node->next;
    }
    cout << node->val << endl;
  }

  int sizeOfList(ListNode *&head)
  {
    int size = 0;
    ListNode *node = head;

    while (node)
    {
      size++;
      node = node->next;
    }

    return size;
  }

  void reverseGroup(ListNode *&head, ListNode *node, int &k)
  {
    ListNode *prev = head;
    ListNode *curr = head;

    while (curr != node)
    {
      prev = curr;
      curr = curr->next;
    }

    // ? store all nodes
    ListNode *it = curr;
    ListNode *nodes[k];
    for (int i = 0; i < k; ++i)
    {
      nodes[i] = it;
      it = it->next;
    }

    ListNode *last_node = nodes[k - 1];
    ListNode *first_in_next_group = last_node->next;

    // if currnt node is not the head
    if (curr != prev)
      prev->next = last_node;

    // if current node is the head itself
    if (curr == prev)
    {
      head = last_node;
    }

    curr = last_node;
    for (int i = k - 2; i >= 0; --i)
    {
      curr->next = nodes[i];
      curr = curr->next;
    }

    curr->next = first_in_next_group;
  }

  ListNode *reverseKGroup(ListNode *head, int k)
  {
    int groups = sizeOfList(head) / k;

    if (groups == 0)
      return head;

    ListNode *currStart = head;

    for (int i = 0; i < groups; ++i)
    {
      reverseGroup(head, currStart, k);
      // ?next node became the start of the next group
      currStart = currStart->next;
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

  int k = 3;

  sol.disp(node);                       // * 1 -> 2 -> 3 -> 4 -> 5
  sol.disp(sol.reverseKGroup(node, k)); // * 3 -> 2 -> 1 -> 4 -> 5
  return 0;
}