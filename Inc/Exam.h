#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <string>

using namespace std;

class intClass
{
public:
    virtual bool init() {return true;};
    virtual bool login(string nm, string psw) {return true;};
};

class myClass : public intClass
{
    private:
        intClass& _dbC;
    public:
    myClass(intClass& dbC): _dbC(dbC)
    {};
    ~myClass()
    {};

    int Initialization(string name, string pass)
    {
        if(_dbC.init()) {
            if(_dbC.login(name, pass)) {
                std::cout << "SUCCESS" << std::endl;
                return 1;
            }
            else{
                std::cout << "NO LOGIN" << std::endl;
                return -1;
            }
        }
        else{
            std::cout << "NO Init" << std::endl;
            return -1;
        }
    }

};


#endif