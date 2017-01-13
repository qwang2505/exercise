#include "../include.h"

/**
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
 */

// 通不过leetcode的提交，但是错误再getRandom，不知道怎么回事
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int size = v.size();
        m[val][size] = true;
        v.push_back(val);
        return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        map<int, map<int, bool> >::iterator it = m.find(val);
        if (it == m.end()) {
            return false;
        }
        // 要删除的元素的位置
        int index = m[val].begin()->first;
        m[val].erase(index);
        if (m[val].empty()) {
            m.erase(val);
        }
        // 注意：如果vector中只有一个元素，那就直接删除了事，否则需要替换后再删除
        if (v.size() > 1) {
            int last = v[v.size()-1];
            m[last].erase(v.size()-1);
            m[last][index] = true;
            v[index] = last;
        }
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    map<int, map<int, bool> > m;
    vector<int> v;
};

int main(int argc, char** argv) {
    /*
    // Init an empty collection.
    RandomizedCollection collection;

    // Inserts 1 to the collection. Returns true as the collection did not contain 1.
    cout << (collection.insert(1) == true) << endl;

    // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    cout << (collection.insert(1) == false) << endl;

    // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    cout << (collection.insert(2) == true) << endl;

    // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    cout << collection.getRandom() << endl;

    // Removes 1 from the collection, returns true. Collection now contains [1,2].
    cout << (collection.remove(1) == true) << endl;

    // getRandom should return 1 and 2 both equally likely.
    cout << collection.getRandom() << endl;

    cout << endl;
    */


    RandomizedCollection col;
    cout << col.insert(0) << endl << endl;
    cout << col.remove(0) << endl << endl;
    cout << col.insert(-1) << endl << endl;
    cout << col.remove(0) << endl << endl;
}
