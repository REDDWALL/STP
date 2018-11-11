#include <cassert>
#include "TComplexEditor_test.h"
#include "../TComplexEditor/TComplexEditor.h"

void TComplexEditor_test::constructorTest() {
    TComplexEditor editor;
    assert(editor.getComplex() == "0");
}

void TComplexEditor_test::isZeroComplexTest() {
    TComplexEditor editor;
    assert(editor.isZeroComplex());
    editor.addDigit(8);
    assert(!editor.isZeroComplex());
}

void TComplexEditor_test::changeSignAndAddDigitTest() {
    TComplexEditor editor;
    editor.addDigit(8);
    assert(editor.changeSign() == "-8");
    assert(editor.changeSign() == "8");
}

void TComplexEditor_test::addZeroTest() {
    TComplexEditor editor;
    editor.addDigit(8);
    editor.addZero();
    assert(editor.getComplex() == "80");
}

void TComplexEditor_test::removeLastDigitTest() {
    TComplexEditor editor;
    editor.addDigit(8);
    editor.changeSign();
    assert(editor.removeLastDigit() == "0");
}

void TComplexEditor_test::clearTest() {
    TComplexEditor editor;
    editor.addDigit(8);
    editor.addDigit(8);
    assert(editor.clear() == "0");
}

void TComplexEditor_test::addDividerTest() {
    TComplexEditor editor;
    editor.addDigit(8);
    editor.addZero();
    editor.addDivider();
    editor.addDigit(4);
    assert(editor.getComplex() == "80+i*4");
}

void TComplexEditor_test::editComplexTest() {
    TComplexEditor editor;
    editor.addDigit(8);
    editor.editComplex(CHANGE_SIGN);
    assert(editor.getComplex() == "-8");
    editor.editComplex(ADD_DIVIDER);
    editor.addDigit(2);
    assert(editor.getComplex() == "-8+i*2");
    editor.editComplex(ADD_ZERO);
    assert(editor.getComplex() == "-8+i*20");
    editor.editComplex(REMOVE_LAST_DIGIT);
    assert(editor.getComplex() == "-8+i*2");
    editor.editComplex(CHANGE_SIGN);
    assert(editor.getComplex() == "-8-i*2");
    editor.editComplex(CLEAR);
    assert(editor.getComplex() == "0");
}

void TComplexEditor_test::settersAndGettersTest() {
    TComplexEditor editor;
    editor.setComplex("5+i*3");
    assert(editor.getComplex() == "5+i*3");
}
