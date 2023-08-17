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

  void trans_lists(vector<ListNode *> &lists, vector<int> &arr_rep)
  {
    for (auto list : lists)
    {
      while (list)
      {
        arr_rep.push_back(list->val);
        list = list->next;
      }
    }
  }

  void trans_vec(ListNode *&list, vector<int> &arr_rep)
  {
    for (auto it = arr_rep.begin(); it < arr_rep.end(); ++it)
    {
      if (distance(it, arr_rep.end()) == 1)
      {
        list->val = *it;
        break;
      }
      list->val = *it;
      list->next = new ListNode();
      list = list->next;
    }
  }

  // ?Using heaps make_heap and sort_heap
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.empty())
      return nullptr;

    vector<int> arr;
    trans_lists(lists, arr);

    if (arr.empty())
      return nullptr;

    make_heap(arr.begin(), arr.end());
    sort_heap(arr.begin(), arr.end());

    ListNode *res = new ListNode();
    ListNode *node = res;

    trans_vec(node, arr);

    return res;
  }

  // ? Using priority-queue class
  ListNode *_mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (auto list : lists)
    {
      while (list)
      {
        min_heap.push(list->val);
        list = list->next;
      }
    }

    if (min_heap.empty())
    {
      return nullptr;
    }

    ListNode *res = new ListNode(min_heap.top());
    min_heap.pop();
    ListNode *current = res;

    while (!min_heap.empty())
    {
      current->next = new ListNode(min_heap.top());
      current = current->next;
      min_heap.pop();
    }

    return res;
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

  ListNode *node3 = new ListNode(0);
  node3->next = new ListNode(5);
  node3->next->next = new ListNode(11);

  vector<ListNode *> nodes = {node1, node2, node3};
  sol.disp(sol.mergeKLists(nodes));
  sol.disp(sol._mergeKLists(nodes));
  // both should print: 0 -> 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 11
  return 0;
}