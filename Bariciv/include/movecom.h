#ifndef MOVECOM_H
#define MOVECOM_H
#include <cstring>
#include <string>
#include <iostream>

struct movecom
{
    public:
        movecom(std::string, int, int);
        virtual ~movecom();
        int getrow() {return row;};
        int getcolumn() {return column;};
        int getdirect() {return direct;};
        int getnumber() {return number;};
        void setrow(int a) {row = a;};
        void setcolumn(int a) {column = a;};
        void setdirect(int a) {direct = a;};
        void setnumber(int a) {number = a;};
        void print();
    protected:
        int row;
        int column;
        int direct;
        int number;
    private:
};

#endif // MOVECOM_H
