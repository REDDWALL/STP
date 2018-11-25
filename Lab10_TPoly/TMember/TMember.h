#pragma once

#include <string>

class TMember {
private:
    int FCoeff;
    int FDegree;
public:
    TMember(int c = 0, int n = 0);

    int getPower() const;

    void setPower(int n);

    int getCoefficient() const;

    void setCoefficient(int c);

    bool operator==(const TMember &secondMember);

    TMember differentiate();

    double calculate(double x);

    std::string getPolynomialString();
};
