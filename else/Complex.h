#include <string>
#include <cmath>

using std::string;



class Complex{
private:
    float re;
    float im;
public:
        
    float Re();
    float Im();
    float abs();
    float ang();
    Complex Pair();
    Complex& operator+(Complex r);
    Complex& operator-(Complex r);
    Complex& operator*(Complex r);
    Complex& operator/(Complex r);
    friend Complex& operator+(float it, Complex r);
    friend Complex& operator-(float it, Complex r);
    friend Complex& operator*(float it, Complex r);
    friend Complex& operator/(float it, Complex r);
    friend Complex& operator-(Complex r, float it);
    friend Complex& operator*(Complex r, float it);
    friend Complex& operator/(Complex r, float it);
    Complex& operator-();
    std::string transform();
    friend std::ostream&operator<<(std::ostream out, Complex r);
    friend std::istream&operator>>(std::istream in, Complex r);
};


