#ifndef GENERFACTORY_H
#define GENERFACTORY_H
#include "ClasUnit.h"
#include "MetodFactory.h"
#include "PrintFactory.h"
#include "ClassMetPrint.h"

class IGenerate
{
public:

    virtual std::shared_ptr<ClassUnit>GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT) = 0;

    virtual std::shared_ptr<MethodUnit>GenMethodUnit(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::DEFAULT) = 0;

    virtual  std::shared_ptr<PrintOperatorUnit>GenPrintOperatorUnit(const std::string text) = 0;

    virtual ~IGenerate() {};
};

class GenerateCDoublePlus : public IGenerate
{
public:
    explicit GenerateCDoublePlus();
    ~GenerateCDoublePlus();

    std::shared_ptr<ClassUnit>GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);

    std::shared_ptr<MethodUnit>GenMethodUnit(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::DEFAULT);

    std::shared_ptr<PrintOperatorUnit>GenPrintOperatorUnit(const std::string text);
};


class GenerateCSharp : public IGenerate
{
public:
    explicit GenerateCSharp();
    ~GenerateCSharp();

    std::shared_ptr<ClassUnit> GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);

    std::shared_ptr<MethodUnit> GenMethodUnit(const std::string name, const std::string returnType, unsigned int flags = MethodUnit::DEFAULT);

    std::shared_ptr<PrintOperatorUnit> GenPrintOperatorUnit(const std::string text);
};

class GenerateJava : public IGenerate
{
public:
    explicit GenerateJava();
    ~GenerateJava();

    std::shared_ptr<ClassUnit> GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);

    std::shared_ptr<MethodUnit> GenMethodUnit(const std::string name, const std::string returnType, unsigned int flags = MethodUnit::DEFAULT);

    std::shared_ptr<PrintOperatorUnit> GenPrintOperatorUnit(const std::string text);
};
#endif // GENERFACTORY_H
