#pragma once

#include <list>
#include <string>
#include "../TMember/TMember.h"

class TPoly {
private:
    std::list<TMember> polynomial;
public:
    TPoly(int c = 0, int n = 0);

    int getMaxPower();

    int getCoefficient(int power);

    void clear();

    TPoly operator+(const TPoly &secondPoly);

    TPoly operator+(const TMember &member);

    TPoly operator*(const TPoly &secondPoly);

    TPoly operator-(const TPoly &secondPoly);

    TPoly subtract();

    bool operator==(const TPoly &secondPoly);

    TPoly differentiate();

    double calculate(double x);

    TMember getElement(int index) const;
};