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

    void reverse();
    
    //debug
    void showNum();
    


    //Int& operator=(const Int& n);
    //Int& operator=(Int&& n) noexcept;

    const Int& operator+(const Int& n);
    const Int& operator-(const Int& n);
    const Int& operator*(const Int& n);
    const Int& operator/(const Int& n);

    Int& operator++();
    Int& operator+=(const Int& n);
    Int& operator--();
    Int& operator-=(const Int& n);
    Int& operator*=(const Int& n);
    Int& operator/=(const Int& n);

    //operator bool() const;
    friend bool operator==(const Int& lhs, const Int& rhs);
    friend bool operator!=(const Int& lhs, const Int& rhs);
    friend bool operator<(const Int& lhs, const Int& rhs);
    friend bool operator<=(const Int& lhs, const Int& rhs);
    friend bool operator>(const Int& lhs, const Int& rhs);
    friend bool operator>=(const Int& lhs, const Int& rhs);


    Int();
    Int(string n, int base);    //base 2 and 10 atm.
    Int(const Int& n);
    Int(int64_t n);
    Int(const vector<bool>& n);
};
//TODO:
/*
    unsigned Int
    Fixed size Ints and uInts(Int128_t etc)    
*/

