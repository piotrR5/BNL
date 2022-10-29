#include "BNL.h"

namespace bln{
    Int abs(Int& n){
        if(n<Int(0))n.reverse();
        return n;
    }
}



