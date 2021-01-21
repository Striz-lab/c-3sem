#include "Complex.h"
#include <cmath>
#include <string>

using std::string;

    
float Re(){
    return re;
}
    
float Im(){
    return im;
}
    
float abs(){                                  //модуль числа
    return std::sqrt(re*re+im*im);
}
 
float ang(){                                    //аргумент числа
    if (re != 0)
        return std::atan(im/re);
    else if (im > 0)
        return M_PI/2;
    else if (im < 0)
        return -M_PI/2;
    else
        return 0;
}
    
float Pair(){                                   //сопряжение
    Complex pair(re, -im);
    return pair;
}

Complex& operator+(const Complex &r) {         //сложение комплексных
    Complex sum(this->re + r.re, this->im + r.im);
    return sum;
}

Complex& operator-(const Complex &r) {         //вычитание комплексных
    Complex dif(this->re - r.re, this->im - r.im);
    return dif;
}

Complex& operator*(const Complex &r) {         //умножение комплексных
    Complex mul(this->re * r.re - this->im * r.im, this->im * r.re + this->re * r.im);
    return dif;
}

Complex& operator/(const Complex &r) {         //деление комплексных
    Complex div((this->re * r.re + this->im * r.im)/(r.re*r.re+r.im*r.im), (this->im * r.re - this->re * r.im)/(r.re*r.re+r.im*r.im));
    return div;
}

Complex& operator+(float it, Complex r) {              //сложение комплексного числа и числа с плавающей запятой
    Complex sum1(it + r.re, r.im);
    return sum1;
}

Complex& operator-(float it, Complex r) {              //вычитание комплексного числа из числа с плавающей запятой
    Complex dif1(it - r.re, -r.im);
    return dif1;
}

Complex& operator-(Complex r, float it) {              //вычитание из комплексного числа числа с плавающей запятой
    Complex dif2(r.re - it, r.im);
    return dif2;
}

Complex& operator*(Complex r, float it) {              //умножение комплексного числа и числа с плавающей запятой
    Complex mul1(r.re * it, r.im * it);
    return mul1;
}

Complex& operator*(float it, Complex r) {              //умножение комплексного числа и числа с плавающей запятой (коммутатор)
    Complex mul2(r.re * it, r.im * it);
    return mul2;
}

Complex& operator/(Complex r, float it) {              //деление комплексного числа на число с плавающей запятой
    Complex div1(r.re / it, r.im / it);
    return div1;
}

Complex& operator/(float it, Complex r) {              //деление на комплексное число числа с плавающей запятой
    Complex div2(r.re * it/(r.re*r.re+r.im*r.im), -r.im * it/(r.re*r.re+r.im*r.im));
    return div2;
}

Complex& operator-() {                                //умножение на -1
    Complex dif3(-this->re, -this->im);
    return dif3;
}


string Complex::transform(){                         //преобразование в строку для сдвигов
    std::string something;
    if (this->im >= 0)
        something = std::transform(this->re) + "+" + std::transform(this->im) + "i";
    else
        something = std::transform(this->re) + "-" + std::transform(-this->im) + "i";

    return something;
}

std::ostream& operator<<(std::ostream out, Complex& r){ //побитовый сдвиг влево
    return out << t.transform;
}

std::istream& operator>>(std::istream in, Complex& r){ //побитовый сдвиг вправо
    return out >> t.transform;
}

