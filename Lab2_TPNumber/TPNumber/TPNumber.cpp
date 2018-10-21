#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <sstream>

#include "TPNumber.h"

using namespace std;

TPNumber::TPNumber(double a, int b, int c) {
    if (b >= 2 && b <= 16 && c >= 0) {
        number = a;
        base = b;
        precision = c;
    } else {
        number = 0.0;
        base = 10;
        precision = 0;
    }
}

TPNumber::TPNumber(string a, string b, string c) {
    double numberTemp = stoi(a);
    int baseTemp = stoi(b);
    int precisionTemp = stoi(c);

    if (baseTemp >= 2 && baseTemp <= 16 && precisionTemp >= 0) {
        number = numberTemp;
        base = baseTemp;
        precision = precisionTemp;
    } else {
        number = 0.0;
        base = 10;
        precision = 0;
    }
}

TPNumber TPNumber::copy() {
    return {number, base, precision};
}

TPNumber TPNumber::operator+(TPNumber right) {
    if (base == right.base && precision == right.precision) {
        return {number + right.number, base, precision};
    } else return {0.0, 10, 0};
}

TPNumber TPNumber::operator*(TPNumber right) {
    if (base == right.base && precision == right.precision) {
        return {number * right.number, base, precision};
    } else return {0.0, 10, 0};
}

TPNumber TPNumber::operator-(TPNumber right) {
    if (base == right.base && precision == right.precision) {
        return {number - right.number, base, precision};
    } else return {0.0, 10, 0};
}

TPNumber TPNumber::operator/(TPNumber right) {
    if (base == right.base && precision == right.precision) {
        return {number / right.number, base, precision};
    } else return {0.0, 10, 0};
}

TPNumber TPNumber::inverse() {
    return {1 / number, base, precision};
}

TPNumber TPNumber::square() {
    return {number * number, base, precision};
}

double TPNumber::getNumber() {
    return number;
}

string TPNumber::getNumberString() {
    double tempNumber = fabs(number);
    int leftPart = (int) floor(tempNumber); // Целая часть числа
    double rightPart = tempNumber - floor(tempNumber); // Дробная часть числа
    string result;

    while (leftPart > 0) {
        int ost = leftPart % base;
        result += symbols[ost];
        leftPart /= base;
    }
    if (result.empty()) result = "0";
    if (rightPart == 0.0) return result;
    else {
        result += ".";
        for (int i = 1; i <= precision; i++) {
            rightPart *= base;
            result += symbols[(int) floor(rightPart)];
            rightPart -= floor(rightPart);
            if (rightPart == 0.0) break;
        }
    }
    if (number < 0) result = result = "-" + result;
    return result;
}

int TPNumber::getBase() {
    return base;
}

string TPNumber::getBaseString() {
    return to_string(base);
}

int TPNumber::getPrecision() {
    return precision;
}

string TPNumber::getPrecisionString() {
    return to_string(precision);
}

void TPNumber::setBase(int newBase) {
    if (newBase >= 2 && newBase <= 16) base = newBase;
}

void TPNumber::setBase(string stringBase) {
    int newBase = stoi(stringBase);
    if (newBase >= 2 && newBase <= 16) base = newBase;
}

void TPNumber::setPrecision(int newPrecision) {
    if (newPrecision >= 0) precision = newPrecision;
}

void TPNumber::setPrecision(string stringPrecision) {
    int newPrecision = stoi(stringPrecision);
    if (newPrecision >= 0) precision = newPrecision;
}
