#include <cassert>
#include "TPoly_test.h"
#include "../TPoly/TPoly.h"

void TPoly_test::constructorAndGettersTest() {
    TPoly poly_1(6, 3);
    assert(poly_1.getElement(0) == TMember(6, 3));
    assert(poly_1.getMaxPower() == 3);
    assert(poly_1.getCoefficient(3) == 6);
    assert(poly_1.getElement(0).getPolynomialString() == "6*x^3");

    TPoly poly_2(3, 0);
    assert(poly_2.getElement(0) == TMember(3, 0));
    assert(poly_2.getCoefficient(0) == 3);
    assert(poly_2.getMaxPower() == 0);
    assert(poly_2.getElement(0).getPolynomialString() == "3");

    TMember member;
    assert(member.getCoefficient() == 0);
    assert(member.getPower() == 0);
    assert(member.getPolynomialString() == "0");
}

void TPoly_test::clearTest() {
    TPoly poly(4, 5);
    poly.clear();
    assert(poly.getMaxPower() == 0);
    assert(poly.getCoefficient(0) == 0);
}

void TPoly_test::additionTest() {
    TPoly poly_1 = TPoly(3, 2) + TMember(-2, 1) + TMember(7, 0);
    TPoly poly_2 = TPoly(5, 2) + TMember(4, 1) + TMember(-3, 0);
    TPoly poly_3 = poly_1 + poly_2;
    assert(poly_3.getElement(1).getPolynomialString() == "8*x^2");
    assert(poly_3.getElement(2).getPolynomialString() == "2*x^1");
    assert(poly_3.getElement(3).getPolynomialString() == "4");
}

void TPoly_test::multiplicationTest() {
    TPoly poly_1 = TPoly(2, 2) + TMember(3, 1);
    TPoly poly_2 = TPoly(3, 2) + TMember(2, 1);
    TPoly poly_3 = poly_1 * poly_2;
    assert(poly_3.getElement(1).getPolynomialString() == "6*x^4");
    assert(poly_3.getElement(2).getPolynomialString() == "13*x^3");
    assert(poly_3.getElement(3).getPolynomialString() == "6*x^2");
}

void TPoly_test::subtractionTest() {
    TPoly poly_1 = TPoly(1, 3) + TMember(-2, 1) + TMember(7, 0);
    TPoly poly_2 = TPoly(7, 3) + TMember(-4, 1) + TMember(7, 0);
    TPoly poly_3 = poly_1 - poly_2;
    assert(poly_3.getElement(1).getPolynomialString() == "-6*x^3");
    assert(poly_3.getElement(2).getPolynomialString() == "2*x^1");
    assert(poly_3.getElement(3).getPolynomialString() == "0");

    TPoly poly_4 = TPoly(5, 2).subtract();
    assert(poly_4.getElement(1).getPolynomialString() == "-5*x^2");
}

void TPoly_test::equalityTest() {
    assert(TPoly(2, 5) == TPoly(2, 5));
    assert(!(TPoly(1, 5) == TPoly(2, 5)));
    assert((TPoly(1, 3) + TMember(2, 1) + TMember(7, 0)) == (TPoly(1, 3) + TMember(2, 1) + TMember(7, 0)));
}

void TPoly_test::differentiationTest() {
    TPoly poly = TPoly(1, 3) + TMember(7, 2) + TMember(5, 1);
    TPoly result = poly.differentiate();
    assert(result.getElement(1).getPolynomialString() == "3*x^2");
    assert(result.getElement(2).getPolynomialString() == "14*x^1");
}

void TPoly_test::calculationTest() {
    TPoly poly = TPoly(6, 2);
    assert(poly.calculate(5) == 150);

    TPoly poly_2 = TPoly(1, 3) + TMember(2, 2) + TMember(7, 0);
    assert(poly_2.calculate(3) == 52);
}

void TPoly_test::settersTest() {
    TMember member = TMember(1, 2);
    member.setCoefficient(7);
    member.setPower(5);
    assert(member.getPolynomialString() == "7*x^5");
}