#include <cmath>
#include "TMember.h"

TMember::TMember(int c, int n) : FCoeff(c), FDegree(n) {

}

int TMember::getPower() const{
    return FDegree;
}

void TMember::setPower(int n) {
    FDegree = n;
}

int TMember::getCoefficient() const{
    return FCoeff;
}

void TMember::setCoefficient(int c) {
    FCoeff = c;
}

bool TMember::operator==(const TMember &secondMember) {
    return FCoeff == secondMember.FCoeff && FDegree == secondMember.FDegree;
}

TMember TMember::differentiate() {
    return {FCoeff * FDegree, FDegree - 1};
}

double TMember::calculate(double x) {
    return pow(x, FDegree) * FCoeff;
}

std::string TMember::getPolynomialString() {
    if (FDegree == 0 || FCoeff == 0) {
        return std::to_string(FCoeff);
    } else {
        return std::to_string(FCoeff) + "*x^" + std::to_string(FDegree);
    }
}