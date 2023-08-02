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

  ListNode *deleteTail(ListNode *head)
  {
    if (!head->next)
    {
      delete head;
      return nullptr;
    }
    ListNode *node = head;
    while (node->next->next)
      node = node->next;
    ListNode *temp = node->next;
    delete temp;
    node->next = nullptr;
    return head;
  }

  ListNode *deleteHead(ListNode *head)
  {
    if (!head->next)
    {
      delete head;
      return nullptr;
    }
    ListNode *temp = head;
    head = head->next;
    delete temp;

    return head;
  }

  ListNode *deleteAt(ListNode *head, int pos)
  {
    // get the node before the node to delete
    ListNode *node = head;
    while (1 < pos)
    {
      pos--;
      node = node->next;
    }

    // do the piping
    ListNode *temp = node->next;
    if (node->next && temp)
    {
      node->next = temp->next;
    }
    delete temp;

    return head;
  }

  int getSize(ListNode *head)
  {
    ListNode *node = head;
    int size = 1;
    while (node->next)
    {
      size++;
      node = node->next;
    }

    return size;
  }

  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    // *All the removal operations are 0 based

    if (!head)
      return nullptr;

    if (n == 0)
      return head;

    int size = getSize(head);
    int pos = size - n;

    if (pos == 0)
      return deleteHead(head);

    else if (pos == size - 1)
      return deleteTail(head);

    else
      return deleteAt(head, pos);

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
  sol.disp(node);
  sol.disp(sol.removeNthFromEnd(node, 3));
  return 0;
}