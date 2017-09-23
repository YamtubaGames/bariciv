#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>
#include <sstream>
#include <istream>

#include <movecom.h>

movecom commandparser(std::istream &inputStream);
movecom commandparserString(std::string input);
#endif // COMMANDPARSER_H
