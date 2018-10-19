#include <math.h>
#include <stdexcept>
#include <sstream>
#include "TComplex.h"

TComplex::TComplex(double a, double b) : real(a), imag(b) {

}

TComplex::TComplex(string complexNumber) {
    size_t index = complexNumber.find("+i*");
    int sign = 1;
    if (index == std::string::npos) {
        index = complexNumber.find("-i*");
        sign = -1;
    }
    real = std::stod(complexNumber.substr(0, index));
    imag = std::stod(complexNumber.substr(index + 3)) * sign;
}

TComplex TComplex::copy() {
    return {real, imag};
}

TComplex operator+(TComplex left, TComplex right) {
    double newReal = left.getReal() + right.getReal();
    double newImg = left.getImag() + right.getImag();
    return {newReal, newImg};
}

TComplex operator*(TComplex left, TComplex right) {
    double a_1 = left.getReal();
    double b_1 = left.getImag();
    double a_2 = right.getReal();
    double b_2 = right.getImag();

    double newReal = (a_1 * a_2) - (b_1 * b_2);
    double newImg = (a_1 * b_2) + (b_1 * a_2);

    return {newReal, newImg};
}

TComplex TComplex::square() {
    return *this * *this;
}

TComplex TComplex::inverse() {
    double a = real;
    double b = imag;

    double newReal = a / ((a * a) + (b * b));
    double newImg = -(b / ((a * a) + (b * b)));

    return {newReal, newImg};
}

TComplex operator-(TComplex left, TComplex right) {
    double newReal = left.getReal() - right.getReal();
    double newImg = left.getImag() - right.getImag();

    return {newReal, newImg};
}

TComplex operator/(TComplex left, TComplex right) {
    double a_1 = left.getReal();
    double b_1 = left.getImag();
    double a_2 = right.getReal();
    double b_2 = right.getImag();

    double newReal = ((a_1 * a_2) + (b_1 * b_2)) / ((a_2 * a_2) + (b_2 * b_2));
    double newImg = ((a_2 * b_1) - (a_1 * b_2)) / ((a_2 * a_2) + (b_2 * b_2));

    return {newReal, newImg};
}

TComplex operator-(TComplex &complexNumber) {
    //return TComplex(-complexNumber.getReal(), -complexNumber.getImag());
    complexNumber.real = -complexNumber.getReal();
    complexNumber.imag = -complexNumber.getImag();
    return complexNumber;
}

double TComplex::module() {
    return sqrt(real * real + imag * imag);
}

double TComplex::angleRad() {
    double a = real;
    double b = imag;

    if (a == 0 && b == 0) return -1;
    if (a == 0 && b > 0) return M_PI / 2;
    if (a == 0 && b < 0) return -M_PI / 2;
    if (a > 0) return atan(b / a);
    if (a < 0) return atan(b / a) + M_PI;

    return -1;
}

double TComplex::angleDegree() {
    return (angleRad() * 180) / M_PI;
}

TComplex TComplex::pow(int power) {
    double newReal = std::pow(module(), (double) power) * (cos((double) power * angleRad()));
    double newImg = std::pow(module(), (double) power) * (sin((double) power * angleRad()));

    return {newReal, newImg};
}

TComplex TComplex::root(int power, int index) {
    if (index >= power) return {0, 0};
    double newReal = std::pow(module(), 1.0 / (double) power) * (cos((angleRad() + 2 * index * M_PI) / (double) power));
    double newImg = std::pow(module(), 1.0 / (double) power) * (sin((angleRad() + 2 * index * M_PI) / (double) power));

    return {newReal, newImg};
}

bool operator==(TComplex left, TComplex right) {
    return (left.getReal() == right.getReal()) && (left.getImag() == right.getImag());
}

bool operator!=(TComplex left, TComplex right) {
    return !(left == right);
}

double TComplex::getReal() {
    return real;
}

double TComplex::getImag() {
    return imag;
}

std::string TComplex::getRealString() {
    return std::to_string(real);
}

std::string TComplex::getImagString() {
    return std::to_string(imag);
}

string TComplex::getComplexString() {
    string symbol = "+";

    double imagSign = imag;
    if (imag < 0) {
        symbol = "-";
        imagSign = -imagSign;
    }

    ostringstream strs;
    strs << real << symbol << "i*" << imagSign;

    return strs.str();
}