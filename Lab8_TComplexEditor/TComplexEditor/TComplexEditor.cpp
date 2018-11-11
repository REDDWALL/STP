#include "TComplexEditor.h"

const std::string TComplexEditor::ZERO = "0";
const std::string TComplexEditor::DIVIDER = "+i*";

TComplexEditor::TComplexEditor() : complex("0"), currentPart(REAL_PART) {

}

bool TComplexEditor::isZeroComplex() {
    return complex == ZERO;
}

std::string TComplexEditor::changeSign() {
    switch (currentPart) {
        case REAL_PART: {
            if (complex[0] == '-') {
                complex.erase(complex.begin());
            } else if (complex[0] != '0') {
                complex = "-" + complex;
            }
        }
            break;
        case IMAGINE_PART: {
            int position = complex.find('i');
            complex[position - 1] = (complex[position - 1] == '-') ? '+' : '-';
        }
            break;
        default:
            break;
    }
    return complex;
}

std::string TComplexEditor::addDigit(int digit) {
    switch (currentPart) {
        case IMAGINE_PART:
            complex += std::to_string(digit);
            break;
        default: {
            unsigned int position = complex.find('i');
            if (complex[0] == '0') {
                complex.replace(0, 1, std::to_string(digit));
            } else if (position != -1) {
                complex.insert(position - 1, std::to_string(digit));
            } else if (complex[0] == '-') {
                complex.insert(1, std::to_string(digit));
            } else {
                complex += std::to_string(digit);
            }
        }
            break;
    }
    return complex;
}

std::string TComplexEditor::addZero() {
    return addDigit(0);
}

std::string TComplexEditor::removeLastDigit() {
    complex.pop_back();
    switch (currentPart) {
        case REAL_PART: {
            if (complex == "-" || complex.empty()) {
                complex = ZERO;
            }
        }
            break;
        case IMAGINE_PART: {
            if (complex[complex.length() - 1] == '*') {
                complex.erase(complex.end() - 3, complex.end());
                currentPart = REAL_PART;
            } else if (complex.find('i')) {
                complex.back();
            }
        }
            break;
        default:
            break;
    }
    return complex;
}

std::string TComplexEditor::clear() {
    currentPart = REAL_PART;
    return complex = ZERO;
}

std::string TComplexEditor::addDivider() {
    if (complex.find(DIVIDER) == std::string::npos) {
        complex = complex + DIVIDER;
        currentPart = IMAGINE_PART;
    }
    return complex;
}

void TComplexEditor::editComplex(Operations operation) {
    switch (operation) {
        case CHANGE_SIGN:
            changeSign();
            break;
        case ADD_ZERO:
            addZero();
            break;
        case REMOVE_LAST_DIGIT:
            removeLastDigit();
            break;
        case CLEAR:
            clear();
            break;
        case ADD_DIVIDER:
            addDivider();
            break;
        default:
            break;
    }
}

void TComplexEditor::setComplex(std::string comp) {
    if (comp.find(DIVIDER) != std::string::npos && !comp.empty()) {
        complex = comp;
    }
}

std::string TComplexEditor::getComplex() {
    return complex;
}
