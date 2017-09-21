#ifndef MOVECOM_H
#define MOVECOM_H
#include <cstring>
#include <string>
#include <iostream>

struct movecom
{
    public:
        movecom();
        virtual ~movecom();
        std::string gettile() {return tileloc;};
        std::string getdirect() {return direct;};
        std::string getnumber() {return number;};
        void settile(std::string a) {tileloc = a;};
        void setdirect(std::string a) {direct = a;};
        void setnumber(std::string a) {number = a;};
    protected:
        std::string tileloc;
        std::string direct;
        std::string number;
    private:
};

#endif // MOVECOM_H
