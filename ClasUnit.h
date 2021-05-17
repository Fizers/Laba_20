#ifndef CLASUNIT_H
#define CLASUNIT_H
#include <memory>
#include <vector>
#include <string>
#include "ClassMetPrint.h"

class CDoublePlusClassUnit : public ClassUnit
{
public:
    explicit CDoublePlusClassUnit(const std::string& name, Flags modifier = ClassUnit::DEFAULT);
    ~CDoublePlusClassUnit();
    std::string compile(unsigned int level = 0) const;
};

class CSharpClassUnit : public ClassUnit
{
public:
    explicit CSharpClassUnit(const std::string& name, Flags modifier = ClassUnit::PUBLIC);
    ~CSharpClassUnit();
    std::string compile(unsigned int level = 0) const;
};

class JavaClassUnit : public ClassUnit
{
public:
    explicit JavaClassUnit(const std::string& name, Flags modifier = ClassUnit::DEFAULT);
    ~JavaClassUnit();
    std::string compile(unsigned int level = 0) const;
};

#endif // CLASUNIT_H
