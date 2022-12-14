#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using std::vector;
using std::string;

class Int{
    vector<bool>num;
    
    void resize(size_t goal_size);
    string binToDec();
    vector<bool>DecToBin();
    
    public:
    //Int& operator=(const Int& n);
    //Int& operator=(Int&& n) noexcept;


    /*

                MOPERATORS

    */
    const Int& operator+(const Int& n);
    const Int& operator-(const Int& n);
    const Int& operator*(const Int& n);
    const Int& operator/(const Int& n);

    Int& operator++();
    Int operator++(int);
    Int& operator+=(const Int& n);
    Int& operator--();
    Int operator--(int);
    Int& operator-=(const Int& n);
    Int& operator*=(const Int& n);
    Int& operator/=(const Int& n);


    /*

                LOPERATORS

    */
    operator bool() const;
    friend bool operator==(const Int& lhs, const Int& rhs);
    friend bool operator!=(const Int& lhs, const Int& rhs);
    friend bool operator<(const Int& lhs, const Int& rhs);
    friend bool operator<=(const Int& lhs, const Int& rhs);
    friend bool operator>(const Int& lhs, const Int& rhs);
    friend bool operator>=(const Int& lhs, const Int& rhs);



    /*

            CONSTRUCTORS

    */
    Int();
    Int(string n, int base);    //base 2 and 10 atm.
    Int(string n);              //just base 10;
    Int(const Int& n);
    Int(int64_t n);
    Int(const vector<bool>& n);


    /*

                    UTILITY

    */
    void reverse();
    void _add(string& s1, string s2);
    void pow2(size_t power, std::string& num);
    string getDec();
    void RSA();
    void RSC();
    void LSA();
    void LSC();
    //debug
    void showNum();
};
//TODO:
/*
    unsigned Int
    Fixed size Ints and uInts(Int128_t etc)    
*/

