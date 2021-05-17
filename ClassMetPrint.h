#ifndef CLASSMETPRINT_H
#define CLASSMETPRINT_H
#include "Unit.h"
#include <vector>
#include <iostream>
#include <string>


class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT,
        INTERNAL,
        PROTECTED_INTERNAL,
        FINAL,
        ABSTRACT,
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string& name, Flags modifier = AccessModifier::DEFAULT);
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string m_name;
    Flags m_modifier;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        DEFAULT = 0,
        INTERNAL = 1 << 3,
        SEALED    = 1 << 4,
        FINAL = 1 << 5,
        ABSTRACT = 1 << 6,

    };
public:
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags);

    void add( const std::shared_ptr< Unit >& unit, Flags = Modifier::STATIC);

    std::string compile( unsigned int level = 0 ) const = 0;
protected:
     std::string m_name;
     std::string m_returnType;
     Flags m_flags;
     std::vector< std::shared_ptr< Unit > > m_body;
};

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const std::string& text );
    std::string compile( unsigned int level = 0 ) const = 0;
protected:
    std::string m_text;
};

#endif // CLASSMETPRINT_H
