#include "ClasUnit.h"


CDoublePlusClassUnit::CDoublePlusClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier) {}

CDoublePlusClassUnit::~CDoublePlusClassUnit() {}

std::string CDoublePlusClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i])
        {
            if (f)
                result += f->compile(level + 1);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

CSharpClassUnit::CSharpClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier) {}

CSharpClassUnit::~CSharpClassUnit() {}

std::string CSharpClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_modifier & PROTECTED_INTERNAL)
        result += "PROTECTED_INTERNAL ";

    else if (m_modifier & INTERNAL)
        result += "INTERNAL ";
    else
        result += "PUBLIC ";

    result += "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
             result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level);

        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

JavaClassUnit::JavaClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier) {}

JavaClassUnit::~JavaClassUnit() {}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);


    if (m_modifier & PRIVATE)
        result += "PRIVATE ";
    else if (m_modifier & PROTECTED)
        result += "PROTECTED ";
    else
        result += "PUBLIC ";

    if (m_modifier & FINAL)
        result += "FINAL";

    else if (m_modifier & ABSTRACT)
        result += "ABSTRACT ";

    result += "class " + m_name + " ";

    result += " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
             result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level);
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}
