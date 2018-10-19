#pragma once

#include <math.h>
#include <cassert>
#include "../TComplex/TComplex.h"

using namespace std;

void constructorsTest() {
    TComplex complex_1(108, 18);
    assert(complex_1.getReal() == 108);
    assert(complex_1.getImag() == 18);

    TComplex complex_2("11.53+i*6.12");
    assert(complex_2.getReal() == 11.53);
    assert(complex_2.getImag() == 6.12);
}

void copyTest() {
    TComplex complex_1(1, 25);
    TComplex complex_2 = complex_1.copy();
    assert(complex_1.getReal() == complex_2.getReal());
    assert(complex_1.getImag() == complex_2.getImag());
}

void plusTest() {
    TComplex complex_1(2, 3);
    TComplex complex_2(3, 4);
    TComplex result = complex_1 + complex_2;
    assert(result.getReal() == 5);
    assert(result.getImag() == 7);
}

void multiplyTest() {
    TComplex complex_1(2, 3);
    TComplex complex_2(-1, 1);
    TComplex result = complex_1 * complex_2;
    assert(result.getReal() == -5);
    assert(result.getImag() == -1);
}

void squareTest() {
    TComplex complex(3, 5);
    TComplex result = complex.square();
    assert(result.getReal() == -16);
    assert(result.getImag() == 30);
}

void inverseTest() {
    TComplex complex(-2, 8);
    TComplex result = complex.inverse();
    assert(result.getReal() == (double) -2 / 68);
    assert(result.getImag() == -(double) 8 / 68);
}

void subtractionTest() {
    TComplex complex_1(2, 3);
    TComplex complex_2(2, 3);
    TComplex result = complex_1 - complex_2;
    assert(result.getReal() == 0);
    assert(result.getImag() == 0);
}

void divideTest() {
    TComplex complex_1(2, 3);
    TComplex complex_2(-1, 4);
    TComplex result = complex_1 / complex_2;
    assert(result.getReal() == (double) 10 / 17);
    assert(result.getImag() == -(double) 11 / 17);
}

void minusTest() {
    TComplex complex(2, 3);
    TComplex result = -complex;
    assert(result.getReal() == -2);
    assert(result.getImag() == -3);
}

void moduleTest() {
    TComplex complex(8, 0);
    double result = complex.module();
    assert(result == 8);
}

void angleRadTest() {
    TComplex complex_1(0, 0);
    double result_1 = complex_1.angleRad();
    assert(result_1 == -1);

    TComplex complex_2(0, 3);
    double result_2 = complex_2.angleRad();
    assert(result_2 == M_PI / 2);

    TComplex complex_3(0, -3);
    double result_3 = complex_3.angleRad();
    assert(result_3 == -M_PI / 2);

    TComplex complex_4(5, 2);
    double result_4 = complex_4.angleRad();
    double answer_1 = atan((2.0 / 5.0));
    assert(result_4 == answer_1);

    TComplex complex_5(-5, 2);
    double result_5 = complex_5.angleRad();
    double answer_2 = atan(2.0 / -5.0) + M_PI;
    assert(result_5 == answer_2);
}

void angleDegreeTest() {
    TComplex complex(3, 4);
    double result = complex.angleDegree();
    double answer = complex.angleRad() * 180 / M_PI;
    assert(result == answer);
}

void powTest() {
    TComplex complex(2, 2);
    TComplex result = complex.pow(2);
    assert(std::abs(result.getReal() - 0) < 0.001);
    assert(std::abs(result.getImag() - 8) < 0.001);
}

void rootTest() {
    TComplex complex_1(1, 1);
    TComplex result_1 = complex_1.root(1, 2);
    assert(result_1.getReal() == 0);
    assert(result_1.getImag() == 0);

    TComplex complex_2(3, 7);
    TComplex result_2 = complex_2.root(3, 1);
    assert(std::abs(result_2.getReal() - -1.556006) < 0.001);
    assert(std::abs(result_2.getImag() - 1.2040441) < 0.001);
}

void equalTest() {
    TComplex complex_1(2, 3);
    TComplex complex_2(2, 3);
    assert(complex_1 == complex_2);

    TComplex complex_3(3, 5);
    TComplex complex_4(1, 2);
    assert(complex_3 != complex_4);
}

void gettersTest() {
    TComplex complex(-1, 3);
    assert(complex.getReal() == -1.0);
    assert(complex.getImag() == 3.0);
}

void stringGettersTest() {
    TComplex complex(1, -25);
    assert(complex.getRealString() == std::to_string(1.0));
    assert(complex.getImagString() == std::to_string(-25.0));
}

void stringComplexTest() {
    TComplex complex(6, 3);
    assert(complex.getComplexString() == "6+i*3");
}