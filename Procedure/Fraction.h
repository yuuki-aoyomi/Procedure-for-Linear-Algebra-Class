/*
You can change Decimal to Fraction. 
And you 
*/

#include <iostream>
#include <sstream>


int yuguri(int x, int y){
    if (y == 0) return x;
    return yuguri(y, x % y);
}

class Fraction{
private:
    int num;   // 分子
    int den;   // 分母

    void normalize(){
        if (den < 0){
            num = -num;
            den = -den;
        }
        int g = yuguri(abs(num), abs(den));
        num /= g;
        den /= g;
    }

public:
    Fraction(int x = 0, int y = 1) : num(x), den(y){
        normalize();
    }

    // double → 分数
    Fraction(double x){
        const int SCALE = 1000000;   // 精度
        num = static_cast<int>(x * SCALE);
        den = SCALE;
        normalize();
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "(" << num << "/" << den << ")";
        return ss.str();
    }

    Fraction operator+(const Fraction& f) const {
        return Fraction(
            num * f.den + den * f.num,
            den * f.den
        );
    }
    Fraction operator-(const Fraction& f) const {
        return Fraction(
            num * f.den - den * f.num,
            den * f.den
        );
    }
    Fraction operator*(const Fraction& f) const {
        return Fraction(
            num * f.num,
            den * f.den
        );
    }
    Fraction operator/(const Fraction& f) const {
        return Fraction(
            num * f.den,
            den * f.num
        );
    }

};
/* 使用例
int main(){
    /*
    Fraction f1(6,4);
    Fraction f2(1,3);
    Fraction f3 = f1 + f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;

    cout << f1.toString() << endl;
    cout << f2.toString() << endl;
    cout << f3.toString() << endl;

    Fraction f4(0.125);
    cout << f4.toString() << endl;
    cout << f5.toString() << endl;
    cout << f6.toString() << endl;
    
    double x,y,z;
    cin >> x >> y >> z;
    Fraction f5(x), f6(y), f7(z);
    cout << f5.toString() << endl << f6.toString() << endl << f7.toString();
}
*/