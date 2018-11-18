#include "TSet_test.h"

int main() {
    TSet_test test = TSet_test();
    test.constructorTest();
    test.clearAndEmptyTest();
    test.insertTest();
    test.eraseTest();
    test.containsTest();
    test.concatenationTest();
    test.subtractionTest();
    test.multiplicationTest();
}