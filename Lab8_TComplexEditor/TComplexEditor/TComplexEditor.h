#pragma once

#include <string>

enum ComplexPart {
    REAL_PART,
    IMAGINE_PART
};

enum Operations {
    CHANGE_SIGN,
    ADD_ZERO,
    REMOVE_LAST_DIGIT,
    CLEAR,
    ADD_DIVIDER
};

class TComplexEditor {
private:
    std::string complex;
    ComplexPart currentPart;
    bool complexValidation(std::string comp);
public:
    static const std::string DIVIDER;
    static const std::string ZERO;

    TComplexEditor();

    bool isZeroComplex();

    std::string changeSign();

    std::string addDigit(int digit);

    std::string addZero();

    std::string removeLastDigit();

    std::string clear();

    std::string addDivider();

    void editComplex(Operations operation);

    void setComplex(std::string comp);

    std::string getComplex();
};
