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

bool devide2(string& n){
    string ret(n.size(),'0');
    bool returned = (n[n.size()-1]-48)%2;
    for(size_t i=1; i<n.size(); i++)
    {
        ret[i]=((n[i-1]-48)*10+n[i]-48)/2+48;
        n[i]=(n[i]-48)%2+48;
    }
    if(n.size()==1){
        n[0]=(n[0]-48)/2+48;
        return returned;
    }
    n=ret;
    return returned;
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

    if(base==10){
        bool sign=n[0]=='-';
        if(sign) n.erase(n.begin(),n.begin()+1);
        vector <bool> b;
        //std::cout<<"CHUJ"<<decimal.size()<<std::endl;

        while(n!=string(n.size(),'0'))
        {
            //std::cout<<decimal<<std::endl;
            b.emplace(b.begin(),devide2(n));  
            //for(auto i:b)std::cout<<i<<std::endl; 
        }
        num=b;
        resize(BNL_INT_MAX);
        if(sign)reverse();
        
    }
}

Int::Int(string n){
    *this=Int(n,10);
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

void Int::_add(string& s1, string s2){
    uint8_t offset='0';
    for(auto& i:s1)i-=offset;
    for(auto& i:s2)i-=offset;

    uint8_t temp=0;
    if(s1.size()!=s2.size()){
        if(s1.size()<s2.size()){
            while(s1.size()<s2.size()){
                s1.insert(0,1,0);
            }
        }
        else{
            while(s1.size()>s2.size()){
                s2.insert(0,1,0);
            }
        }
    }
    
    size_t index=s1.length()-1;

    for(;index>=0;index--){
        uint8_t foo=s1[index]+s2[index]+temp;

        s1[index]=foo%10;
        temp=foo/10;

        if(index==0 && temp!=0){
            s1.insert(0,1,temp);
            for(auto& i:s1)i+=offset;
            return;
        }else if(index==0){
            for(auto& i:s1)i+=offset;
            return;
        }
    }

    for(auto& i:s1)i+=offset;
}

void Int::pow2(size_t power, std::string& num){
    while(power--){
        _add(num,num);
    }
}

string Int::getDec(){
    string returned="0";
    string powered="1";

    size_t indexOfLastPower=num.size()-1;
    bool sign=num[0];
    if(sign)reverse();
    for(size_t i=num.size()-1;i>0;i--){
        if(num[i]){
            pow2(indexOfLastPower-i, powered);
            _add(returned, powered);
            indexOfLastPower=i;
            
        }
    }

    if(sign){
        returned.insert(0,1,'-');
    }

    return returned;
}

void Int::RSA(){
    num.pop_back();
    num.insert(num.begin(), num[0]);
}
void Int::RSC(){
    bool temp=num[0];
    num.pop_back();
    num.insert(num.begin(), temp);
}
