#include "TEditor.h"

const std::string TEditor::ZERO = "0";
const char TEditor::DIVIDER = '.';

TEditor::TEditor() : number("0") {

}

bool TEditor::isZeroNumber() {
    return number == "0";
}

std::string TEditor::changeSign() {
    if (number[0] == '-') {
        number.erase(number.begin());
    } else if (number != TEditor::ZERO) {
        number = "-" + number;
    }
    return number;
}

std::string TEditor::addDigit(int digit) {
    if (number == TEditor::ZERO) {
        number = "";
    }
    return number += std::to_string(digit);
}

std::string TEditor::addZero() {
    return addDigit(0);
}

std::string TEditor::removeLastDigit() {
    number.pop_back();
    if (number == "-" || number.empty()) {
        number = TEditor::ZERO;
    }
    return number;
}

std::string TEditor::clear() {
    return number = TEditor::ZERO;
}

std::string TEditor::addDivider() {
    if (number.find(DIVIDER) == std::string::npos) {
        number = number + DIVIDER;
    }
    return number;
}

void TEditor::editNumber(int commandNumber) {
    switch (commandNumber) {
        case 1:
            changeSign();
            break;
        case 2:
            addZero();
            break;
        case 3:
            removeLastDigit();
            break;
        case 4:
            clear();
            break;
        case 5:
            addDivider();
            break;
        default:
            break;
    }
}

void TEditor::setNumber(std::string num) {
    number = num;
}

std::string TEditor::getNumber() {
    return number;
}
