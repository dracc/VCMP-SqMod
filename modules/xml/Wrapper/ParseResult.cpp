// ------------------------------------------------------------------------------------------------
#include "Wrapper/ParseResult.hpp"

// ------------------------------------------------------------------------------------------------
namespace SqMod {

// ------------------------------------------------------------------------------------------------
SQInteger ParseResult::Typename(HSQUIRRELVM vm)
{
    static const SQChar name[] = _SC("SqXmlParseResult");
    sq_pushstring(vm, name, sizeof(name));
    return 1;
}

// ------------------------------------------------------------------------------------------------
void ParseResult::Validate() const
{
    // Is the documen handle valid?
    if (!m_Doc)
    {
        STHROWF("Invalid XML document reference");
    }
}

// ------------------------------------------------------------------------------------------------
void ParseResult::Check() const
{
    if (m_Result.status != status_ok)
    {
        STHROWF("XML parse error [%s]", m_Result.description());
    }
}

} // Namespace:: SqMod