#include "../include.h"

/**
 * Design a data structure that supports all following operations in average O(1) time.
 *
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 */

class RandomizedSet {
public:
    RandomizedSet() {
    };

    ~RandomizedSet() {
    };

    bool insert(int val) {
        map<int, int>::iterator it = m.find(val);
        if (it != m.end()) {
            return false;
        }
        int size = v.size();
        m[val] = size;
        v.push_back(val);
        return true;
    }

    bool remove(int val) {
        map<int, int>::iterator it = m.find(val);
        if (it == m.end()) {
            return false;
        }
        int index = m[val];
        int size = v.size();
        int last = v[size-1];
        v[index] = last;
        m[last] = index;
        v.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom() {
        srand(time(NULL));
        return v[rand() % v.size()];
    }
private:
    map<int, int> m;
    vector<int> v;
};

int main(int argc, char** argv) {
    // Init an empty set.
    RandomizedSet randomSet;

    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout << (randomSet.insert(1) == true) << endl;

    // Returns false as 2 does not exist in the set.
    cout << (randomSet.remove(2) == false) << endl;

    // Inserts 2 to the set, returns true. Set now contains [1,2].
    cout << (randomSet.insert(2) == true) << endl;

    // getRandom should return either 1 or 2 randomly.
    cout << randomSet.getRandom() << endl;

    // Removes 1 from the set, returns true. Set now contains [2].
    cout << (randomSet.remove(1) == true) << endl;

    // 2 was already in the set, so return false.
    cout << (randomSet.insert(2) == false) << endl;

    // Since 2 is the only number in the set, getRandom always return 2.
    cout << randomSet.getRandom() << endl;
}
