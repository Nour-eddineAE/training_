#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
  map<int, Node *> mp;            // map the key to the node in the linked list
  int cp;                         // capacity
  Node *tail;                     // double linked list tail pointer
  Node *head;                     // double linked list head pointer
  virtual void set(int, int) = 0; // set function
  virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache
{

public:
  LRUCache(int capacity)
  {
    this->cp = capacity;
    this->head = NULL;
    this->tail = NULL;
  }

  void set(int key, int value) override
  {
    if (mp.count(key) > 0)
    {
      this->mp.at(key)->value = value;
    }
    else
    {
      Node *newHead = new Node(key, value);

      if (this->mp.size() < this->cp)
      {
        if (this->head != NULL)
        {
          newHead->next = this->head;
          this->head->prev = newHead;
          this->head = newHead;
        }
        else
        {
          this->head = newHead;
          this->tail = newHead;
        }
      }
      else if (this->cp == mp.size())
      {
        // tail
        Node *temp = this->tail->prev;
        this->mp.erase(this->tail->key);
        delete this->tail;
        this->tail = temp;
        this->tail->next = NULL;
        delete temp;

        // head
        newHead->next = this->head;
        this->head->prev = newHead;
        this->head = newHead;
      }
      // add new element to the map
      this->mp.insert(make_pair(key, newHead));
    }
  }

  int get(int key) override
  {
    if (mp.count(key) > 0)
    {
      return mp.at(key)->value;
    }
    return -1;
  }
};

int main()
{
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++)
  {
    string command;
    cin >> command;
    if (command == "get")
    {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    }
    else if (command == "set")
    {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
