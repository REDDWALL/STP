#pragma once

#include <cassert>
#include "../TPNumberEditor/TPNumberEditor.h"

using namespace std;

void constructorTest() {
    TEditor editor;
    assert(editor.getNumber() == "0");
}

void isZeroNumberTest() {
    TEditor editor;
    assert(editor.isZeroNumber());
    editor.addDigit(8);
    assert(!editor.isZeroNumber());
}

void changeSignAndAddNumberTest() {
    TEditor editor;
    editor.addDigit(8);
    assert(editor.changeSign() == "-8");
    assert(editor.changeSign() == "8");
}

void addZeroTest() {
    TEditor editor;
    editor.addDigit(8);
    editor.addZero();
    assert(editor.getNumber() == "80");
}

void removeLastDigitTest() {
    TEditor editor;
    editor.addDigit(8);
    editor.changeSign();
    assert(editor.removeLastDigit() == "0");
}

void clearTest() {
    TEditor editor;
    editor.addDigit(8);
    editor.addDigit(8);
    assert(editor.clear() == "0");
}

void addDividerTest() {
    TEditor editor;
    editor.addDigit(8);
    editor.addDivider();
    editor.addZero();
    editor.addDigit(5);
    assert(editor.clear() == "0");
}

void editNumberTest() {
    TEditor editor;
    editor.addDigit(8);
    editor.editNumber(1);
    assert(editor.getNumber() == "-8");
    editor.editNumber(5);
    editor.addDigit(8);
    assert(editor.getNumber() == "-8.8");
    editor.editNumber(2);
    assert(editor.getNumber() == "-8.80");
    editor.editNumber(3);
    assert(editor.getNumber() == "-8.8");
    editor.editNumber(4);
    assert(editor.getNumber() == "0");
}

void settersAndGettersTest() {
    TEditor editor;
    editor.setNumber("8.08");
    assert(editor.getNumber() == "8.08");
}
