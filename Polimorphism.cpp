/*Given an abstract base class Cache with member variables and functions: 

mp - Map the key to the node in the linked list
cp - Capacity
tail - Double linked list tail pointer
head - Double linked list head pointer
set() - Set/insert the value of the key, if present, otherwise add the key as the most recently used key. If the cache has reached its capacity, it should replace the least recently used key with a new key.
get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

You have to write a class LRUCache which extends the class Cache and uses the member functions and variables to implement an LRU cache.
*/


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache
{
    public:
    LRUCache(int c) { cp = c; }

    void set(int k,int v)
    {
        Node *N;

        if(mp.empty()) //No nodes
        {
            N = new Node(k,v);
            tail = head = N;
            mp[k] = N;

            return;
        }

        auto it = mp.find(k);

        if(it != mp.end()) //In hash table
        {
            it->second->value = v; // update value

            if(head == it->second) //head?
                return;

            it->second->prev->next = it->second->next;

            if(tail == it->second) //tail?
                tail = tail->prev;
            else                   //in between?
                it->second->next->prev = it->second->prev;

            it->second->next = head;
            it->second->prev = NULL;
            head->prev = it->second;
            head = it->second;
        }
        else               // No in hash table
        {
            N = new Node(head->prev,head,k,v); //new node
            head->prev = N;
            head = N;
            mp[k] = N;

            if(mp.size() > cp) //capacity?
            {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = NULL;
            }

        }

    }

    int get(int k)
    {
        auto it = mp.find(k);
        if(it != mp.end())
            return it->second->value;

        return -1;
    }

};

