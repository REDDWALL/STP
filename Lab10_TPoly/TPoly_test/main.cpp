#include "TPoly_test.h"

int main() {
    TPoly_test test = TPoly_test();
    test.constructorAndGettersTest();
    test.clearTest();
    test.additionTest();
    test.multiplicationTest();
    test.subtractionTest();
    test.equalityTest();
    test.differentiationTest();
    test.calculationTest();
    test.settersTest();
}