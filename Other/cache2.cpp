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
class LRUCache : public Cache {
    int count = 0;
public:
    LRUCache() {}
    LRUCache(int capacity) { cp = capacity; }
    void set(int, int);
    int get(int);
    int size(){ return mp.size(); }
    void description() {
    for (auto i : mp)
      cout << i.first << " = (" << i.second->key
             << " -> " << i.second->value << ")"
           << endl;
    }
};

void LRUCache::set(int key, int value) {
    auto node = new Node(NULL, head, key, value);
    head = node;
    mp.insert(std::pair<int, Node*>(++count, node));

    if (count > cp){
        for(int i = 1; i < count; ++i){
            mp[i] = mp[i + 1];
        }
        mp.erase(count);
        count--;
    }
}

int LRUCache::get(int key) {
    int index = 1;
    int result = -1;

    // TODO: If the key exists, get the index
    for(auto& i : mp){
        if (i.second->key == key){
            result = i.second->value;
            index = i.first;
        }
    }

    // Move item to the higher index (higher priority)
    for (int i = index; i < count; ++i){
        if (i > 1){
            auto tmp = mp[i];
            mp[i] = mp[i + 1];
            mp[i + 1] = tmp;
        }
    }
    return result;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
