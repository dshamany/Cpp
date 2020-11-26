//
//  DSMap.hpp
//  googletest_test
//
//  Created by Daniel Shamany on 12/6/18.
//  Copyright © 2018 Daniel Shamany. All rights reserved.
//

#ifndef DSMap_hpp
#define DSMap_hpp

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

namespace DS {
    template <typename K, typename V>
    struct Pair {
        K key;
        V value;
        
        Pair(){}
        // I use underscores for parameters here just so I can tell the difference.
        Pair(K _key, V _value): key(_key), value(_value){}
        
        bool operator==(Pair<K,V> rhs) const {
            return key == rhs.key && value == rhs.value;
        }
        
        void operator=(V _value){
            value = _value;
        }
        
        friend ostream& operator<<(ostream& os, const Pair<K,V>& pair){
            os << "[ " << pair.key << "  ->  " << pair.value << " ]";
            return os;
        }
    };
    
    template <typename K, typename V>
    class Map{
        std::vector<Pair<K,V>> pairs;
    public:
        Map(){}
        Map(std::initializer_list<Pair<K,V>> iList){
            pairs.insert(pairs.begin() , iList);
        }
        Map(Pair<K, V> pair){
            pair.push_back(pair);
        }
        Map(std::vector<Pair<K,V>> pairs): pairs(pairs){}
        int size() const { return static_cast<int>(pairs.size()); }
        auto& operator[](K key){
            int i = 0;
            bool found = false;
            for (; i < pairs.size(); ++i){
                if (pairs[i].key == key){
                    found = true;
                    break;
                }
            }
            
            if (!found){
                Pair<K,V> tmp;
                tmp.key = key;
                pairs.push_back(tmp);
                assert(tmp == pairs.back());
            }
            return found ? pairs[i]: pairs.back();
        }
        auto operator[](const int index) const { return pairs[index]; }
        friend ostream& operator<<(ostream& os, Map& map){
            for (auto i : map.pairs)
                os << i << " ";
            os << endl;
            return os;
        }
        auto keys() const {
            vector<K> k;
            for (auto i : pairs){
                k.append(i.key);
            }
            return k;
        }
        auto values() const {
            vector<V> v;
            for (auto i : pairs){
                v.append(i.value);
            }
            return keys;
        }
        Pair<K,V>* begin(){ return &pairs.front(); }
        Pair<K,V>* end(){ return &pairs.back() + 1; }
    };
    
}

int main(int argc, char* argv[])
{
   DS::Map<std::string, int> my_map{ {"Daniel", 29}, {"Steve", 31}, {"Rebecca", 27}, {"Sarah", 22}, {"Adam", 10} };
   
   cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
   cout << "Printing Content:\n" << my_map << endl;
   
   cout << "Element Count: " << my_map.size() << endl;
   
   cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
   
   cout << "Sarah Object: " << my_map["Sarah"] << endl;
   
   cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
   
   my_map["Sarah"] = 23;
   
   auto sarah = my_map["Sarah"];
   
   cout << "Changed " << sarah.key << "\'s age to " << sarah.value << endl;
   
   cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
   
   cout << "Key Only: " << my_map["Sarah"].key << endl;
   cout << "Value Only: " << my_map["Sarah"].value << endl;
   
   cout << "- - - - - - - - - - - - - E N D - - - - - - - - - - - - - - - -\n";
   
   return 0;
}


#endif /* DSMap_hpp */
