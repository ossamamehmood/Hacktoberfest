#include <unordered_map>

class MyHashMap {
private:
    std::unordered_map<int, int> data;

public:
    MyHashMap() {
        // Constructor, no initialization needed
    }

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        if (data.find(key) != data.end()) {
            return data[key];
        } else {
            return -1; // Key not found
        }
    }

    void remove(int key) {
        data.erase(key);
    }
};

int main() {
    MyHashMap* obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);
    int param_1 = obj->get(1); // Returns 1
    int param_2 = obj->get(3); // Returns -1 (not found)
    obj->put(2, 1); // Update the existing value
    int param_3 = obj->get(2); // Returns 1
    obj->remove(2); // Remove the mapping for 2
    int param_4 = obj->get(2); // Returns -1 (not found)

    delete obj; // Don't forget to clean up

    return 0;
}
