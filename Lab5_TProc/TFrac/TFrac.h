#pragma once

#include <string>

using namespace std;

class TFrac {
private:
    int num;
    int den;
    void reduction();
public:
    TFrac();
    TFrac(int a, int b);
    TFrac(string fraction);

    friend TFrac operator+(TFrac a, TFrac b);
    friend TFrac operator*(TFrac a, TFrac b);
    friend TFrac operator-(TFrac a, TFrac b);
    friend TFrac operator/(TFrac a, TFrac b);
    bool operator==(TFrac a);
    bool operator>(TFrac a);
    TFrac operator-();

    int gcd(int a, int b);
    TFrac copy();
    TFrac square();
    TFrac reverse();

    int getNum();
    int getDen();
    string getNumStr();
    string getDenStr();
    string getFracStr();
};
