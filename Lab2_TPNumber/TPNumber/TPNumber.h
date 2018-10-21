#include <string>

using namespace std;

const string symbols = "0123456789ABCDEF";

class TPNumber
{
private:
    double number;
    int base, precision;
public:
    TPNumber(double, int, int);
    TPNumber(string, string, string);

    TPNumber copy();
    TPNumber inverse();
    TPNumber square();

    TPNumber operator+(TPNumber);
    TPNumber operator-(TPNumber);
    TPNumber operator*(TPNumber);
    TPNumber operator/(TPNumber);

    double getNumber();
    string getNumberString();

    int getBase();
    string getBaseString();

    int getPrecision();
    string getPrecisionString();

    void setBase(int);
    void setBase(string);

    void setPrecision(int);
    void setPrecision(string);
};