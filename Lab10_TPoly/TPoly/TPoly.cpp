#include <cmath>
#include <list>
#include "TPoly.h"

TPoly::TPoly(int c, int n) {
    polynomial.emplace_back(TMember(c, n));
}

int TPoly::getMaxPower() {
    int maxPower = 0;
    for (TMember member : polynomial) {
        if (member.getPower() > maxPower) {
            maxPower = member.getPower();
        }
    }
    return maxPower;
}

int TPoly::getCoefficient(int power) {
    for (TMember member : polynomial) {
        if (member.getPower() == power) {
            return member.getCoefficient();
        }
    }
    return 0;
}

void TPoly::clear() {
    polynomial.clear();
    polynomial.emplace_back(TMember(0, 0));
}

TPoly TPoly::operator+(const TPoly &secondPoly) {
    TPoly result;

    if (polynomial.size() == secondPoly.polynomial.size()) {
        for (int i = 0; i < polynomial.size(); i++) {
            if (getElement(i).getPower() == secondPoly.getElement(i).getPower()) {
                result.polynomial.emplace_back(
                        getElement(i).getCoefficient() + secondPoly.getElement(i).getCoefficient(),
                                               getElement(i).getPower());
            }
        }
    } else return TPoly(0, 0);

    return result;
}

TPoly TPoly::operator+(const TMember &member) {
    TPoly result = *this;
    result.polynomial.push_back(member);
    return result;
}

TPoly TPoly::operator*(const TPoly &secondPoly) {
    TPoly temp;
    TPoly result;

    temp.polynomial.remove(TMember(0, 0));
    for (TMember mem : polynomial) {
        for (TMember secMem : secondPoly.polynomial) {
            temp.polynomial.emplace_back(mem.getCoefficient() * secMem.getCoefficient(), mem.getPower() + secMem.getPower());
        }
    }

    for (int i = 0; i < temp.polynomial.size(); i++) {
        if (temp.getElement(i).getPower() == temp.getElement(i + 1).getPower()) {
            TMember member(temp.getElement(i).getCoefficient() + temp.getElement(i + 1).getCoefficient(), temp.getElement(i).getPower());
            result.polynomial.push_back(member);
            i++;
        } else result.polynomial.push_back(temp.getElement(i));
    }
    return result;
}

TPoly TPoly::operator-(const TPoly &secondPoly) {
    TPoly result;

    if (polynomial.size() == secondPoly.polynomial.size()) {
        for (int i = 0; i < polynomial.size(); i++) {
            if (getElement(i).getPower() == secondPoly.getElement(i).getPower()) {
                result.polynomial.emplace_back(
                        getElement(i).getCoefficient() - secondPoly.getElement(i).getCoefficient(),
                                               getElement(i).getPower());
            }
        }
    } else return TPoly(0, 0);

    return result;
}

TPoly TPoly::subtract() {
    return TPoly(0, 0) + TMember(-(getElement(0).getCoefficient()), getElement(0).getPower());
}

bool TPoly::operator==(const TPoly &secondPoly) {
    if (polynomial.size() != secondPoly.polynomial.size()) {
        return false;
    }

    for (int i = 0; i < polynomial.size(); i++) {
        if (!(getElement(i) == secondPoly.getElement(i))) {
            return false;
        }
    }
    return true;
}

TPoly TPoly::differentiate() {
    TPoly result;
    for (TMember member : polynomial) {
        result.polynomial.push_back(member.differentiate());
    }
    return result;
}

double TPoly::calculate(double x) {
    double result = 0.0;
    for (TMember member : polynomial) {
        result += member.calculate(x);
    }
    return result;
}

TMember TPoly::getElement(int index) const {
    auto memberIterator = polynomial.begin();
    for (int i = 0; i < index; ++i) {
        memberIterator++;
    }
    return *memberIterator;
}