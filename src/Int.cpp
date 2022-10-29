#include "BNL.h"
#include <iostream>

/*

    cntrl + f and search for these keywords
    CONSTRUCTORS
    MOPERATORS
    LOPERATORS
    UTILITY


*/

/*

            MOPERATORS

*/

const Int& Int::operator+(const Int& n){
    bool prev=0;
    for(int i=BNL_INT_MAX-1;i>=0;i--){
        
        if(prev){
            if(num[i] && n.num[i]){
                num[i]=true;
                prev=true;
            }else if(num[i] || n.num[i]){
                num[i]=false;
                prev=true;
            }else{
                num[i]=true;
                prev=false;
            }
        }else{
            if(num[i] && n.num[i]){
                num[i]=false;
                prev=true;
            }else if(num[i] || n.num[i]){
                num[i]=true;
                prev=false;
            }else{
                num[i]=false;
                prev=false;
            }
        }
    }

    //if(prev)reverse();
    return *this;
}

const Int& Int::operator-(const Int& n){
    Int temp(n);
    temp.reverse();
    return *this+temp;
}




/*

            LOPERATORS

*/





/*

        CONSTRUCTORS

*/

Int::Int(){

}

Int::Int(const Int& n){
    num=n.num;
}

Int::Int(int64_t n){
    bool sign=(n<0);
    while(n){
        num.push_back(n%2);
        n/=2;
    }

    num=vector<bool>(num.rbegin(), num.rend());

    while(num.size()<BNL_INT_MAX){
        num.insert(num.begin(),0);
    }

    if(sign)reverse();
}

Int::Int(string n, int base){
    if(base==2){
        for(auto i:n){
            num.push_back(i=='1');
        }
        int nsize=num.size();
        while(num.size()<1024){
            num.insert(num.begin(), 0);
        }
    }
}

Int::Int(const vector<bool>& n){
    for(auto i:n){
        num.push_back(i=='1');
    }
    int nsize=num.size();
    while(num.size()<1024){
        num.insert(num.begin(), 0);
    }
}

/*

                UTILITY

*/

void Int::showNum(){
    int index=0;
    for(bool i:num){
        std::cout<<i;
        if(++index%128==0)std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"["<<num.size()<<"]\n";
}

void Int::resize(size_t goal_size){
    bool sign=num[0];
    while(num.size()<goal_size){
        num.insert(num.begin(), sign);
    }
    num[0]=sign;
}

void Int::reverse(){
    
    for(int i=0;i<num.size();i++){
        num[i].flip();
    }
    
    //std::cout<<"CHUJ";
    Int temp(1);
    *this=*this+temp;
    
};
