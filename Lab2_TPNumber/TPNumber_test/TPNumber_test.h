#pragma once

#include <math.h>
#include <cassert>
#include <iostream>
#include "../TPNumber/TPNumber.h"

using namespace std;

void constructorsTest() {
    TPNumber pNumber_1(10, 8, 2);
    assert(pNumber_1.getNumber() == 10);
    assert(pNumber_1.getBase() == 8);
    assert(pNumber_1.getPrecision() == 2);

    TPNumber pNumber_2("5", "16", "3");
    assert(pNumber_2.getNumber() == 5);
    assert(pNumber_2.getBase() == 16);
    assert(pNumber_2.getPrecision() == 3);
}

void copyTest() {
    TPNumber pNumber_1(10, 8, 2);
    TPNumber pNumber_2 = pNumber_1.copy();
    assert(pNumber_1.getNumber() == pNumber_2.getNumber());
    assert(pNumber_1.getBase() == pNumber_2.getBase());
    assert(pNumber_1.getPrecision() == pNumber_2.getPrecision());
}

void plusTest() {
    TPNumber pNumber_1(10, 8, 2);
    TPNumber pNumber_2(5, 8, 2);
    TPNumber result = pNumber_1 + pNumber_2;
    assert(result.getNumber() == 15);
    assert(result.getBase() == 8);
    assert(result.getPrecision() == 2);
}

void multiplyTest() {
    TPNumber pNumber_1(8, 8, 2);
    TPNumber pNumber_2(2, 8, 2);
    TPNumber result = pNumber_1 * pNumber_2;
    assert(result.getNumber() == 16);
    assert(result.getBase() == 8);
    assert(result.getPrecision() == 2);
}

void minusTest() {
    TPNumber pNumber_1(8, 8, 2);
    TPNumber pNumber_2(2, 8, 2);
    TPNumber result = pNumber_1 - pNumber_2;
    assert(result.getNumber() == 6);
    assert(result.getBase() == 8);
    assert(result.getPrecision() == 2);
}

void divideTest() {
    TPNumber pNumber_1(8, 8, 2);
    TPNumber pNumber_2(2, 8, 2);
    TPNumber result = pNumber_1 / pNumber_2;
    assert(result.getNumber() == 4);
    assert(result.getBase() == 8);
    assert(result.getPrecision() == 2);
}

void inverseTest() {
    assert(TPNumber(0.5, 8, 2).getNumber() == TPNumber(2, 8, 2).inverse().getNumber());
}

void squareTest() {
    TPNumber pNumber(3, 5, 0);
    TPNumber result = pNumber.square();
    assert(result.getNumber() == 9);
    assert(result.getBase() == 5);
    assert(result.getPrecision() == 0);
}

void gettersTest() {
    TPNumber pNumber_1(3, 5, 0);
    assert(pNumber_1.getNumber() == 3);
    assert(pNumber_1.getBase() == 5);
    assert(pNumber_1.getPrecision() == 0);

    TPNumber pNumber_2(3.9, 2, 4);
    assert(pNumber_2.getNumberString() == "11.1110");
    assert(pNumber_2.getBaseString() == "2");
    assert(pNumber_2.getPrecisionString() == "4");

    TPNumber pNumber_3(-6.2, 8, 4);
    assert(pNumber_3.getNumberString() == "-6.1463");
    assert(pNumber_3.getBaseString() == "8");
    assert(pNumber_3.getPrecisionString() == "4");

    TPNumber pNumber_4(3.9, 16, 3);
    assert(pNumber_4.getNumberString() == "3.E66");
    assert(pNumber_4.getBaseString() == "16");
    assert(pNumber_4.getPrecisionString() == "3");
}

void settersTest() {
    TPNumber pNumber_1(3, 5, 2);
    pNumber_1.setBase(2);
    pNumber_1.setPrecision(1);
    assert(pNumber_1.getBase() == 2);
    assert(pNumber_1.getPrecision() == 1);

    TPNumber pNumber_2(3, 5, 2);
    pNumber_2.setBase("2");
    pNumber_2.setPrecision("1");
    assert(pNumber_2.getBase() == 2);
    assert(pNumber_2.getPrecision() == 1);
}