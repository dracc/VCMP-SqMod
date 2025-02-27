#ifndef _SQMYSQL_STATEMENT_HPP_
#define _SQMYSQL_STATEMENT_HPP_

// ------------------------------------------------------------------------------------------------
#include "Handle/Statement.hpp"

// ------------------------------------------------------------------------------------------------
namespace SqMod {

/* ------------------------------------------------------------------------------------------------
 * Allows management and interaction with a statement handle.
*/
class Statement
{
private:

    // --------------------------------------------------------------------------------------------
    StmtRef m_Handle; // Reference to the actual database statement.

protected:

    /* --------------------------------------------------------------------------------------------
     * Validate the managed statement handle and throw an error if invalid.
    */
#if defined(_DEBUG) || defined(SQMOD_EXCEPTLOC)
    void Validate(CCStr file, Int32 line) const;
#else
    void Validate() const;
#endif // _DEBUG

    /* --------------------------------------------------------------------------------------------
     * Validate the managed statement handle and throw an error if invalid.
    */
#if defined(_DEBUG) || defined(SQMOD_EXCEPTLOC)
    void ValidateCreated(CCStr file, Int32 line) const;
#else
    void ValidateCreated() const;
#endif // _DEBUG

    /* --------------------------------------------------------------------------------------------
     * Validate the managed statement handle and throw an error if invalid.
    */
#if defined(_DEBUG) || defined(SQMOD_EXCEPTLOC)
    const StmtRef & GetValid(CCStr file, Int32 line) const;
#else
    const StmtRef & GetValid() const;
#endif // _DEBUG

    /* --------------------------------------------------------------------------------------------
     * Validate the managed statement handle and throw an error if invalid.
    */
#if defined(_DEBUG) || defined(SQMOD_EXCEPTLOC)
    const StmtRef & GetCreated(CCStr file, Int32 line) const;
#else
    const StmtRef & GetCreated() const;
#endif // _DEBUG

    /* --------------------------------------------------------------------------------------------
     * Validate the statement reference and parameter index, and throw an error if they're invalid.
    */
#if defined(_DEBUG) || defined(SQMOD_EXCEPTLOC)
    void ValidateParam(Int32 idx, CCStr file, Int32 line) const;
#else
    void ValidateParam(Int32 idx) const;
#endif // _DEBUG

public:

    /* --------------------------------------------------------------------------------------------
     * Default constructor.
    */
    Statement()
        : m_Handle()
    {
        /* ... */
    }

    /* --------------------------------------------------------------------------------------------
     * Construct a statement under the specified connection using the specified string.
    */
    Statement(const ConnRef & connection, CSStr query)
        : m_Handle(new StmtHnd())
    {
        m_Handle->Create(connection, query);
    }

    /* --------------------------------------------------------------------------------------------
     * Construct a statement under the specified connection using the specified string.
    */
    Statement(const Connection & connection, CSStr query);

    /* --------------------------------------------------------------------------------------------
     * Copy constructor.
    */
    Statement(const Statement & o) = default;

    /* --------------------------------------------------------------------------------------------
     * Move constructor.
    */
    Statement(Statement && o) = default;

    /* --------------------------------------------------------------------------------------------
     * Copy assignment operator.
    */
    Statement & operator = (const Statement & o) = default;

    /* --------------------------------------------------------------------------------------------
     * Move assignment operator.
    */
    Statement & operator = (Statement && o) = default;

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to compare two instances of this type.
    */
    Int32 Cmp(const Statement & o) const
    {
        if (m_Handle.Get() == o.m_Handle.Get())
        {
            return 0;
        }
        else if (m_Handle.Get() > o.m_Handle.Get())
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to convert an instance of this type to a string.
    */
    const String & ToString() const
    {
        // Do we have a valid handle?
        if (m_Handle)
        {
            m_Handle->mQuery;
        }
        // Default to an empty string
        return NullString();
    }

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to retrieve the name from instances of this type.
    */
    static SQInteger Typename(HSQUIRRELVM vm);

    /* --------------------------------------------------------------------------------------------
     * Retrieve the associated connection handle.
    */
    const StmtRef & GetHandle() const
    {
        return m_Handle;
    }

    /* --------------------------------------------------------------------------------------------
     * See whether the managed handle is valid.
    */
    bool IsValid() const
    {
        return m_Handle;
    }

    /* --------------------------------------------------------------------------------------------
     * Retrieve the currently associated statement connection.
    */
    Connection GetConnection() const;

    /* --------------------------------------------------------------------------------------------
     * Modify the currently associated statement connection.
    */
    void SetConnection(const Connection & conn);

    /* --------------------------------------------------------------------------------------------
     * Execute the statement.
    */
    Int32 Execute();

    /* --------------------------------------------------------------------------------------------
     * Execute the statement.
    */
    Uint32 Insert();

    /* --------------------------------------------------------------------------------------------
     * Execute the statement.
    */
    ResultSet Query();

    /* --------------------------------------------------------------------------------------------
     * Assign a signed 8bit integer to a parameter.
    */
    void SetInt8(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign an unsigned 8bit integer to a parameter.
    */
    void SetUint8(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a signed 16bit integer to a parameter.
    */
    void SetInt16(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign an unsigned 16bit integer to a parameter.
    */
    void SetUint16(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a signed 32bit integer to a parameter.
    */
    void SetInt32(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign an unsigned 32bit integer to a parameter.
    */
    void SetUint32(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a signed 64bit integer to a parameter.
    */
    void SetInt64(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign an unsigned 64bit integer to a parameter.
    */
    void SetUint64(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a signed long integer to a parameter.
    */
    void SetSLongInt(Uint32 idx, Object & val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign an unsigned long integer to a parameter.
    */
    void SetULongInt(Uint32 idx, Object & val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a native integer to a parameter.
    */
    void SetInteger(Uint32 idx, SQInteger val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a 32bit floating point to a parameter.
    */
    void SetFloat32(Uint32 idx, SQFloat val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a 64bit floating point to a parameter.
    */
    void SetFloat64(Uint32 idx, SQFloat val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a native float to a parameter.
    */
    void SetFloat(Uint32 idx, SQFloat val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a boolean to a parameter.
    */
    void SetBoolean(Uint32 idx, bool val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a date to a parameter.
    */
    void SetDate(Uint32 idx, Object & val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a time to a parameter.
    */
    void SetTime(Uint32 idx, Object & val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a date and time to a parameter.
    */
    void SetDatetime(Uint32 idx, Object & val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a string to a parameter.
    */
    void SetString(Uint32 idx, CSStr val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign an enumeration to a parameter.
    */
    void SetEnum(Uint32 idx, CSStr val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign an enumeration to a parameter.
    */
    void SetSet(Uint32 idx, CSStr val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a blob to a parameter.
    */
    void SetBlob(Uint32 idx, Object & val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a buffer to a paramete.
    */
    void SetData(Uint32 idx, Object & val) const;

    /* --------------------------------------------------------------------------------------------
     * Assign a null to a parameter.
    */
    void SetNull(Uint32 idx) const;

};
} // Namespace:: SqMod

#endif // _SQMYSQL_STATEMENT_HPP_
