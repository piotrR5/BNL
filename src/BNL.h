#include "Int.h"
#include "Float.h"

#define BNL_INT_MAX 1024


namespace bln{
    Int abs(Int& n);
    //Float abs(const Float& n);

    Int round(const Int& n, int m);

    Int round(const Int& n, const Int& m);

    //TODO
    /*
        ceil
        floor       for floats
        round 
        mod
        pow 
        log       
        sqrt
        root

    */

    Int mod(const Int& n, int m);

    Int mod(const Int& n, const Int& m);

    Int pow(const Int& n, int m);

    Int pow(const Int& n, const Int& m);
}

/*
    TODO:
        TODO INT:
            optimized storage of 1024 bit integers
            optimized basic math and logic operands
            converting from string (base 10 and base 2) representation of ints
            converting from BML::Float
        TODO FLOAT:
            optimized storage of 1024 bit floats
            optimized basic math and logic operands
            converting from string (base 10 and base 2) representation of floats
            converting from BML::Int
        TODO MATH:
            MultiType math and logic operands (BML::Float + BML::Int, BML::Int * int etc)
            more specialized math functions:
                nth root
                nth power
                min,max
                logarithms
                ... and basicly cmath implementation ...
*/
