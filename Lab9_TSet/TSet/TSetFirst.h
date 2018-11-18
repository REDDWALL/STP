#include <set>
#include <algorithm>

template<class T>
class TSetFirst : public std::set<T> {
public:
    bool contains(T value) {
        return this->find(value) != this->end();
    }

    TSetFirst<T> concatenate(TSetFirst<T> value) {
        TSetFirst result;

        std::set_union(this->begin(), this->end(), value.begin(), value.end(), std::inserter(result, result.begin()));

        return result;
    }

    TSetFirst<T> subtract(TSetFirst<T> value) {
        TSetFirst result;

        std::set_difference(this->begin(), this->end(), value.begin(), value.end(), std::inserter(result, result.begin()));

        return result;
    }

    TSetFirst<T> intersect(TSetFirst<T> value) {
        TSetFirst result;

        std::set_intersection(this->begin(), this->end(), value.begin(), value.end(), std::inserter(result, result.begin()));

        return result;
    }

    T getElement(int index) {
        return *std::next(std::set<T>::begin(), index);
    }
};