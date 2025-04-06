#pragma once
#include <map>
#include <vector>
#include <stdexcept>
template <typename keyType, typename valueType>
class MyTreeMap {
    std::vector<std::map<keyType, valueType>> deepMap;
public:
    valueType& at(keyType key) {
        for (auto it = deepMap.rbegin(); it != deepMap.rend();it++) {
            if(it->find(key) != it->end()) {
                return it->at(key);
            }
        }
        throw std::out_of_range("the container does not have an element with the specified key");
    }
    valueType& operator[](keyType key) {
        for (auto it = deepMap.rbegin(); it != deepMap.rend();it++) {
            if(it->find(key) != it->end()) {
                return it->at(key);
            }
        }
        return deepMap.back()[key];
    }
    void incDepth() {
        deepMap.emplace_back();
    }
    void decDepth() {
        deepMap.pop_back();
    }
};
