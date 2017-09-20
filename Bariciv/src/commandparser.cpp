#include "commandparser.h"
#include "movecom.h"

movecom commandparser(std::string raw){
    std::string delimiter = " ";
    movecom a;
    for(int i = 0; i<3, i++;){
        std::string token = raw.substr(0, raw.find(delimiter));
        raw.erase(0, raw.find(delimiter) + 1);
        if (i = 0) {a.settile(token);};
        if (i = 1) {a.setdirect(token);};
        if (i = 2) {a.setnumber(token);};
    };
    return a;
}
