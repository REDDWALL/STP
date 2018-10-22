#include <string>

using namespace std;

template<class T>
class TMemory {
private:
    T FNumber;
    bool FState;
public:
    TMemory() {
        FNumber = T();
        FState = false;
    }

    void set(T E) {
        FNumber = E;
        FState = true;
    }

    T get() {
        FState = true;
        return FNumber;
    }

    void add(T E) {
        FNumber = FNumber + E;
        FState = true;
    }

    void clear() {
        FNumber = T();
        FState = false;
    }

    string getFState() {
        if (FState) {
            return std::string("_On");
        } else return std::string("_Off");
    }

    T getFNumber() {
        return FNumber;
    }
};