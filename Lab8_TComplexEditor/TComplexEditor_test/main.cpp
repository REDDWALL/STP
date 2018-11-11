#include "TComplexEditor_test.h"

int main() {
    TComplexEditor_test test = TComplexEditor_test();
    test.constructorTest();
    test.isZeroComplexTest();
    test.changeSignAndAddDigitTest();
    test.addZeroTest();
    test.removeLastDigitTest();
    test.clearTest();
    test.addDividerTest();
    test.editComplexTest();
    test.settersAndGettersTest();
}