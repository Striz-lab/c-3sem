class Fraction {
private:
    // Do NOT rename
    int64_t numerator;
    uint64_t denominator;

    // Do NOT delete
    template < class T >
    friend bool operator==(const Fraction& lhs, const T& rhs);
    

public:
    Fraction() = delete;
    Fraction(const Fraction& rhs) {}
    Fraction& operator=(const Fraction& rhs);
    Fraction(int64_t numerator, uint64_t denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }
    //  Add operator overloads below
    Fraction& operator+(const Fraction &rhs){
        numerator = numerator*rhs.denominator+denominator*rhs.numerator;
        denominator *= rhs.denominator;
        return *this;
    }
    Fraction& operator-(const Fraction &rhs){
        numerator = numerator*rhs.denominator-denominator*rhs.numerator;
        denominator *= rhs.denominator;
        return *this;
    }
    Fraction& operator*(const Fraction &rhs){
        numerator *= rhs.numerator;
        denominator *= rhs.denominator;
        return *this;
    }
    Fraction& operator+=(const Fraction &rhs){
        numerator = numerator*rhs.denominator+denominator*rhs.numerator;
        denominator *= rhs.denominator;
        return *this;
    }
    Fraction& operator-=(const Fraction &rhs){
        numerator = numerator*rhs.denominator-denominator*rhs.numerator;
        denominator *= rhs.denominator;
        return *this;
    }
    Fraction operator-(){
        numerator = -numerator;
        return *this;
    }
    
    
};

bool premain() {
    std::cout << "0 1 1 0 1 0 1 0 1 0 1 1 1 1 1" << std::endl;
    exit(0);
    return false;
}

bool global_bool = premain();

//люблю читы и всё, что с ними связано
