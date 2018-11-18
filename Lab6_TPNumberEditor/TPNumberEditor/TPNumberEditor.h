#pragma once

#include <string>

class TEditor {
private:
    std::string number;
public:
    static const char DIVIDER;
    static const std::string ZERO;

    TEditor();

    bool isZeroNumber();

    std::string changeSign();

    std::string addDigit(int digit);

    std::string addZero();

    std::string removeLastDigit();

    std::string clear();

    std::string addDivider();

    void editNumber(int commandNumber);

    void setNumber(std::string num);

    std::string getNumber();
};