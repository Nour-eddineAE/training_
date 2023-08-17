#include <bits/stdc++.h>

using namespace std;

// !Warning: the methods may not be implemented optimaly
class LRUCache
{
private:
  struct Node
  {
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
  };
  unordered_map<int, Node *> pairs;
  int cp;
  Node *head, *tail;

public:
  // ? You may need to use this to print the linked list
  void disp(Node *node)
  {
    if (!node)
    {
      cout << endl;
      return;
    }

    while (node->next)
    {
      cout << node->key << " -> ";
      node = node->next;
    }
    cout << node->key << endl;
  }

  /**
   * Moves the node to the front of the linked list
   * @param {Node *node} pointer to the node to move
   * @returns {void}
   */
  void moveToHead(Node *node)
  {
    if (this->head)
    {
      //* 1- if head
      if (node->key == this->head->key)
        return;

      //* 2- if tail
      if (!node->next)
      {
        // piping at tail
        node->prev->next = nullptr;
        this->tail = node->prev;

        // piping at head
        push_head(node);

        return;
      }

      //* 3- if at any other position
      // piping at position
      node->prev->next = node->next;
      node->next->prev = node->prev;

      // piping at head
      push_head(node);
    }
  }

  /**
   * Pushes a new node to the begining of the linked list
   * @param {Node *node} the node to push
   * @returns {void}
   */
  void push_head(Node *node)
  {
    if (!this->head)
    {
      node->next = nullptr;
      node->prev = nullptr;
      this->head = node;
      this->tail = node;
      return;
    }
    if (!this->head->next)
    {
      this->head->prev = node;
      node->next = this->head;
      node->prev = nullptr;
      this->tail = this->head;
      this->head = node;
      return;
    }

    this->head->prev = node;
    node->next = this->head;
    node->prev = nullptr;
    this->head = node;
  }

  /**
   * Removes the last node in the linked list
   * @returns {void}
   */
  void pop_tail()
  {
    // epty list
    if (!this->head)
      return;

    // one-node list
    else if (!this->tail)
      this->head = nullptr;

    else
    {
      this->tail->prev->next = nullptr;
      this->tail = this->tail->prev;
    }
  }

  LRUCache(int capacity)
  {
    this->cp = capacity;
    this->head = NULL;
    this->tail = NULL;
  }

  /**
   * gets the value associated with a given key
   * @param {int key}
   * @returns {void} the value corresponding to the given key
   */
  int get(int key)
  {

    if (pairs.count(key) != 0)
    {
      Node *res = pairs.at(key);
      moveToHead(res);

      return res->value;
    }
    return -1;
  }

  /**
   * Updates (or inserts) an existing (a new) node
   * @param {int key}
   * @param {int value}
   * @returns {void}
   */
  void put(int key, int value)
  {
    // if empty map
    if (pairs.empty())
    {
      Node *node = new Node(key, value);
      this->head = node;
      this->tail = node;
      pairs.insert({key, node});
    }
    else
    {
      if (pairs.count(key) != 0)
      {
        pairs.at(key)->value = value;
        Node *res = pairs.at(key);
        moveToHead(res);
      }
      else
      {
        Node *node = new Node(key, value);
        pairs.insert({key, node});
        push_head(node);

        if (pairs.size() > cp)
        {
          pairs.erase(this->tail->key);
          pop_tail();
        }
      }
    }
  }
};

int main(int argc, char const *argv[])
{
  LRUCache cache(2);
  cache.put(2, 1);
  cache.put(1, 1);
  cache.put(2, 3);
  cache.put(4, 1);
  cout << "1 => " << cache.get(1) << endl; // 1 => -1
  cout << "2 => " << cache.get(2) << endl; // 2 => 3
  return 0;
}