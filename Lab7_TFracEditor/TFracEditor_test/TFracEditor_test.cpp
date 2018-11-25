#include <cassert>
#include "TFracEditor_test.h"
#include "../TFracEditor/TFracEditor.h"

void TFracEditor_test::constructorTest() {
    TFracEditor editor;
    assert(editor.getFraction() == "0/1");
}

void TFracEditor_test::isZeroFracTest() {
    TFracEditor editor;
    assert(editor.isZeroFraction());
    editor.addDigit(8);
    assert(!editor.isZeroFraction());
}

void TFracEditor_test::changeSignAndAddDigitTest() {
    TFracEditor editor;
    editor.addDigit(8);
    assert(editor.changeSign() == "-8");
    assert(editor.changeSign() == "8");
}

void TFracEditor_test::addZeroTest() {
    TFracEditor editor;
    editor.addDigit(8);
    editor.addZero();
    assert(editor.getFraction() == "80");
}

void TFracEditor_test::removeLastDigitTest() {
    TFracEditor editor;
    editor.addDigit(8);
    editor.changeSign();
    assert(editor.removeLastDigit() == "0/1");
}

void TFracEditor_test::clearTest() {
    TFracEditor editor;
    editor.addDigit(-1);
    editor.addDigit(-1);
    assert(editor.clear() == "0/1");
}

void TFracEditor_test::addDividerTest() {
    TFracEditor editor;
    editor.addDigit(108);
    editor.addDivider();
    editor.addDigit(18);
    assert(editor.getFraction() == "6/1");
}

void TFracEditor_test::editFracTest() {
    TFracEditor editor;
    editor.addDigit(8);
    editor.editFraction(CHANGE_SIGN);
    assert(editor.getFraction() == "-8");
    editor.editFraction(ADD_DIVIDER);
    editor.addDigit(8);
    assert(editor.getFraction() == "-1/1");
    editor.editFraction(ADD_ZERO);
    assert(editor.getFraction() == "-1/10");
    editor.editFraction(REMOVE_LAST_DIGIT);
    assert(editor.getFraction() == "-1/1");
    editor.editFraction(CLEAR);
    assert(editor.getFraction() == "0/1");
}

void TFracEditor_test::settersAndGettersTest() {
    TFracEditor editor;
    editor.setFraction("1//5");
    assert(editor.getFraction() == "1/5");
}
