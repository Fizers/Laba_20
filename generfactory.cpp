#include "generfactory.h"


GenerateCDoublePlus::GenerateCDoublePlus() {}

GenerateCDoublePlus::~GenerateCDoublePlus() {}

std::shared_ptr<ClassUnit>GenerateCDoublePlus::GenClassUnit(const std::string name, unsigned int modifier)
{
    return std::make_shared<CDoublePlusClassUnit >(name, ClassUnit::DEFAULT);
}

std::shared_ptr<MethodUnit>GenerateCDoublePlus::GenMethodUnit(const std::string name, const std::string returnType, unsigned int Flags)
{
    return std::make_shared<CDoublePlusMethodUnit >(name, returnType, Flags);
}

std::shared_ptr<PrintOperatorUnit>GenerateCDoublePlus::GenPrintOperatorUnit(const std::string text)
{
    return std::make_shared<CDoublePlusPrintOperatorUnit >(text);
}


GenerateCSharp::GenerateCSharp() {}
GenerateCSharp::~GenerateCSharp() {}

std::shared_ptr<ClassUnit> GenerateCSharp::GenClassUnit(std::string name, unsigned int modifier)
{
    return std::make_shared< CSharpClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> GenerateCSharp::GenMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared< CSharpMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> GenerateCSharp::GenPrintOperatorUnit(std::string text)
{
    return std::make_shared< CSharpPrintOperatorUnit >(text);
}

GenerateJava::GenerateJava() {}
GenerateJava::~GenerateJava() {}

std::shared_ptr<ClassUnit> GenerateJava::GenClassUnit(std::string name, unsigned int modifier)
{
    return std::make_shared< JavaClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> GenerateJava::GenMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared< JavaMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> GenerateJava::GenPrintOperatorUnit(std::string text)
{
    return std::make_shared< JavaPrintOperatorUnit >(text);
}
