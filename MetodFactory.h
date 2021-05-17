#ifndef METODFACTORY_H
#define METODFACTORY_H
#include "ClassMetPrint.h"
#include <memory>
#include <string>
#include <vector>

class CDoublePlusMethodUnit : public MethodUnit
{
public:
    explicit CDoublePlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CDoublePlusMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

class CSharpMethodUnit : public MethodUnit
{
public:
    explicit CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CSharpMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

class JavaMethodUnit : public MethodUnit
{
public:
    explicit JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~JavaMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

#endif // METODFACTORY_H
