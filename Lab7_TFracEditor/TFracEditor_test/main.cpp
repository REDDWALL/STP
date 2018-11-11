#include "TFracEditor_test.h"

int main() {
    TFracEditor_test test = TFracEditor_test();
    test.constructorTest();
    test.isZeroFracTest();
    test.changeSignAndAddDigitTest();
    test.addZeroTest();
    test.removeLastDigitTest();
    test.clearTest();
    test.addDividerTest();
    test.editFracTest();
    test.settersAndGettersTest();
}