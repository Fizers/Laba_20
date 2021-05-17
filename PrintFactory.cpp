#include "PrintFactory.h"

CDoublePlusPrintOperatorUnit::CDoublePlusPrintOperatorUnit(const std::string& text) :
    PrintOperatorUnit(text) {}

CDoublePlusPrintOperatorUnit::~CDoublePlusPrintOperatorUnit() {}

std::string CDoublePlusPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}

CSharpPrintOperatorUnit::CSharpPrintOperatorUnit(const std::string& text) :
    PrintOperatorUnit(text) {}

CSharpPrintOperatorUnit::~CSharpPrintOperatorUnit() {}

std::string CSharpPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}



JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string& text) :
    PrintOperatorUnit(text) {}

JavaPrintOperatorUnit::~JavaPrintOperatorUnit() {}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}
