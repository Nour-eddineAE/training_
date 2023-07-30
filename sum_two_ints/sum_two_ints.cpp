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
  void dispNodes(ListNode *node)
  {
    while (node->next)
    {
      cout << node->val << " -> ";
      node = node->next;
    }
    cout << node->val << endl;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *res = new ListNode();
    ListNode *resNext = res;
    int reminder = 0;
    while (l1 && l2)
    {
      int sum = l1->val + l2->val + reminder;
      if (sum > 9)
      {
        reminder = 1;
        sum -= 10;
      }
      else
        reminder = 0;

      // store the first digit of the sum in the current node
      resNext->val += sum;

      if (!l1->next && !l2->next && reminder == 1)
      {
        l1->next = new ListNode();
      }

      l1 = l1->next;
      l2 = l2->next;

      if (l1 && l2)
      {
        // create next node and initialize it with the reminder
        resNext->next = new ListNode();

        // move to next
        resNext = resNext->next;
      }
    }

    if (l1)
    {
      resNext->next = l1;
      resNext = resNext->next;
    }
    else if (l2)
    {
      resNext->next = l2;
      resNext = resNext->next;
    }
    else
    {
      return res;
    }
    // store the rest
    while (resNext)
    {
      if (resNext->val + reminder <= 9)
      {
        resNext->val += reminder;
        // we simply return as the linked list is now ready
        return res;
      }
      else
      {
        resNext->val = 0;
        reminder = 1;
      }

      if (!resNext->next && reminder == 1)
      {
        resNext->next = new ListNode();
      }

      resNext = resNext->next;
    }
    return res;
  }
};

int main(int argc, char const *argv[])
{
  ListNode *node1 = new ListNode(3);
  node1->next = new ListNode(7);
  // node1->next->next = new ListNode(3);

  ListNode *node2 = new ListNode(9);
  node2->next = new ListNode(2);
  // node2->next->next = new ListNode(4);

  // Output should be 2 -> 0 -> 1 because 73 + 29 = 102
  Solution sol;
  sol.dispNodes(sol.addTwoNumbers(node1, node2));
  return 0;
}