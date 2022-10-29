#include "src/BNL.h"
#include <iostream>


using namespace std;


int main(){
    Int n(-10);
    n.showNum();
    Int n2(10);
    n2.showNum();
    Int n3(n-n2);
    n3.showNum();
    
    
    return 0;
}