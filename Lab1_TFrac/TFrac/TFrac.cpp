#include "TFrac.h"
#include <vector>
#include <cstdint>
#include <string>
#include <ostream>
#include <iostream>
#include <cstdlib>

using namespace std;

TFrac::TFrac(int a, int b) : num(a), den(b) {
    reduction();
}

int TFrac::gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void TFrac::reduction() {
    int g = gcd(num, den);
    num /= g;
    den /= g;
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
}

TFrac::TFrac(string fraction) {
    int average = fraction.find('/');
    char buf1[30], buf2[30];
    size_t n1 = fraction.copy(buf1, average, 0);
    size_t n2 = fraction.copy(buf2, fraction.length() - average - 1, average + 1);
    buf1[n1] = '\0';
    buf2[n2] = '\0';
    num = atoi(buf1);
    den = atoi(buf2);
    reduction();
}

TFrac TFrac::copy() {
    return {num, den};
}

TFrac operator+(TFrac a, TFrac b) {
    int num = b.num * a.den + a.num * b.den;
    int den = b.den * a.den;
    return {num, den};
}

TFrac operator*(TFrac a, TFrac b) {
    int num = b.num * a.num;
    int den = b.den * a.den;
    return {num, den};
}

TFrac operator-(TFrac a, TFrac b) {
    int num = a.num * b.den - b.num * a.den;
    int den = b.den * a.den;
    return {num, den};
}

TFrac operator/(TFrac a, TFrac b) {
    int num = b.den * a.num;
    int den = b.num * a.den;
    return {num, den};
}

TFrac TFrac::square() {
    return {num * num, den * den};
}

TFrac TFrac::reverse() {
    return {den, num};
}

TFrac TFrac::operator-() {
    return {-num, den};
}

bool TFrac::operator==(TFrac a) {
    return num == a.num && den == a.den;
}

bool TFrac::operator>(TFrac a) {
    return num * a.den > a.num * den;
}

int TFrac::getNum() {
    return num;
}

int TFrac::getDen() {
    return den;
}

string TFrac::getNumStr() {
    return to_string(num);
}

string TFrac::getDenStr() {
    return to_string(den);
}

string TFrac::getFracStr() {
    return to_string(num) + "/" + to_string(den);
}