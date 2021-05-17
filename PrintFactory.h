#ifndef PRINTFACTORY_H
#define PRINTFACTORY_H
#include "ClassMetPrint.h"
#include <memory>
#include <string>
#include <vector>

class CDoublePlusPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CDoublePlusPrintOperatorUnit(const std::string& text);
    ~CDoublePlusPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};


class CSharpPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperatorUnit(const std::string& text);
    ~CSharpPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};

class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit(const std::string& text);
    ~JavaPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};

#endif // PRINTFACTORY_H
