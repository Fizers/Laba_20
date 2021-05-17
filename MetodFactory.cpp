#include "MetodFactory.h"

CDoublePlusMethodUnit::CDoublePlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
   MethodUnit(name, returnType, flags) {}

CDoublePlusMethodUnit::~CDoublePlusMethodUnit() {}

std::string CDoublePlusMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
    {
        result += "STATIC ";
    }
    else if (m_flags & CONST)
    {
        result += "CONST ";
    }

    result += m_returnType + " ";
    result += m_name + "()";

    if (m_flags & VIRTUAL)
    {
        result += " VIRTUAL";
    }

    result += " {\n";

    for (const auto& b : m_body)
         result += b->compile(level + 1);

    result += generateShift(level) + "}\n";

    return result;
}

CSharpMethodUnit::CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags) {}

CSharpMethodUnit::~CSharpMethodUnit() {}

std::string CSharpMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
        result += "STATIC ";

    else if (m_flags & VIRTUAL)
        result += "VIRTUAL ";

    else
        result += "INTERNAL ";

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body)
         result += b->compile(level + 1);

    result += generateShift(level) + "}\n";

    return result;
}

JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags) {}

JavaMethodUnit::~JavaMethodUnit() {}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    // Методы abstract никогда не могут быть final или static

    if (m_flags & STATIC)
        result += "STATIC ";

    else if (m_flags & SEALED)
        result += "SEALED ";

    else if (m_flags & FINAL)
        result += "final ";

    else if (m_flags & ABSTRACT)
        result += "ABSTRACT ";


    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}
