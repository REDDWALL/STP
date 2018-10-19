#pragma once
#include <cassert>
#include "../TFrac/TFrac.h"

using namespace std;

void constructorsTest() {
    TFrac frac_1(-108, -18);
    assert(frac_1.getNumStr() == "6");
    assert(frac_1.getDenStr() == "1");

    TFrac frac_2("6/54");
    assert(frac_2.getNumStr() == "1");
    assert(frac_2.getDenStr() == "9");
}

void copyTest() {
    TFrac frac_1(1, 25);
    TFrac frac_2 = frac_1.copy();
    assert(frac_1.getNumStr() == frac_2.getNumStr());
    assert(frac_1.getDenStr() == frac_2.getDenStr());
}

void plusTest() {
    TFrac frac_1(2, 3);
    TFrac frac_2(3, 4);
    TFrac result = frac_1 + frac_2;
    assert(result.getNum() == 17);
    assert(result.getDen() == 12);
}

void multiplyTest() {
    TFrac frac_1(2, 3);
    TFrac frac_2(3, 4);
    TFrac result = frac_1 * frac_2;
    assert(result.getNum() == 1);
    assert(result.getDen() == 2);
}

void subtractionTest() {
    TFrac frac_1(2, 3);
    TFrac frac_2(3, 4);
    TFrac result = frac_1 - frac_2;
    assert(result.getNum() == -1);
    assert(result.getDen() == 12);
}

void divideTest() {
    TFrac frac_1(2, 3);
    TFrac frac_2(3, 4);
    TFrac result = frac_1 / frac_2;
    assert(result.getNum() == 8);
    assert(result.getDen() == 9);
}

void squareTest() {
    TFrac frac(3, 5);
    TFrac result = frac.square();
    assert(result.getNum() == 9);
    assert(result.getDen() == 25);
}

void reverseTest() {
    TFrac frac(-2, 3);
    TFrac result = frac.reverse();
    assert(result.getNum() == -3);
    assert(result.getDen() == 2);
}

void minusTest() {
    TFrac frac(-2, 3);
    TFrac result = -frac;
    assert(result.getNum() == 2);
    assert(result.getDen() == 3);
}

void equalTest() {
    TFrac frac_1(-2, 3);
    TFrac frac_2(-4, 6);
    assert(frac_1 == frac_2);
}

void moreTest() {
    TFrac frac_1(4, 6);
    TFrac frac_2(1, 3);
    assert(frac_1 > frac_2);
}

void gettersTest() {
    TFrac frac(-1, 3);
    assert(frac.getNum() == -1.0);
    assert(frac.getDen() == 3.0);
}

void stringGettersTest() {
    TFrac frac(1, -25);
    assert(frac.getNumStr() == "-1");
    assert(frac.getDenStr() == "25");
}

void stringFracTest() {
    TFrac frac(-1, 3);
    assert(frac.getFracStr() == "-1/3");
}