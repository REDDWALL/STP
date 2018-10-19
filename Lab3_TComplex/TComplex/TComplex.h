#include <string>

using namespace std;

class TComplex {

private:
    double real, imag;

public:
    TComplex(double a, double b);
    TComplex(string complexNumber);

    friend TComplex operator+(TComplex left, TComplex right);
    friend TComplex operator-(TComplex left, TComplex right);
    friend TComplex operator*(TComplex left, TComplex right);
    friend TComplex operator/(TComplex left, TComplex right);
    friend bool operator==(TComplex left, TComplex right);
    friend bool operator!=(TComplex left, TComplex right);
    friend TComplex operator-(TComplex &complexNumber);

    TComplex copy();
    TComplex square();
    TComplex inverse();
    double module();
    double angleRad();
    double angleDegree();
    TComplex pow(int power);
    TComplex root(int, int);

    double getReal();
    double getImag();
    string getRealString();
    string getImagString();
    string getComplexString();
};