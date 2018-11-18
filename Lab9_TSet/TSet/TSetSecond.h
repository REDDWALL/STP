#include <set>
#include <algorithm>

template<class T>
class TSetSecond {
private:
    std::set<T> set;
public:
    void clear() {
        set.clear();
    }

    void insert(T value) {
        set.insert(value);
    }

    void erase(T value) {
        set.erase(value);
    }

    bool empty() {
        return set.empty();
    }

    bool contains(T value) {
        return set.find(value) != set.end();
    }

    TSetSecond<T> concatenate(TSetSecond<T> value) {
        TSetSecond result;

        std::set_union(set.begin(), set.end(), value.set.begin(), value.set.end(),
                std::inserter(result.set, result.set.begin()));

        return result;
    }

    TSetSecond<T> subtract(TSetSecond<T> value) {
        TSetSecond result;

        std::set_difference(set.begin(), set.end(), value.set.begin(), value.set.end(),
                            std::inserter(result.set, result.set.begin()));

        return result;
    }

    TSetSecond<T> intersect(TSetSecond<T> value) {
        TSetSecond result;

        std::set_intersection(set.begin(), set.end(), value.set.begin(), value.set.end(),
                              std::inserter(result.set, result.set.begin()));

        return result;
    }

    unsigned long size() {
        return set.size();
    }

    T getElement(int index) {
        return *std::next(set.begin(), index);
    }
};
