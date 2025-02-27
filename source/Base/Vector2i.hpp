#ifndef _BASE_VECTOR2I_HPP_
#define _BASE_VECTOR2I_HPP_

// ------------------------------------------------------------------------------------------------
#include "SqBase.hpp"

// ------------------------------------------------------------------------------------------------
namespace SqMod {

/* ------------------------------------------------------------------------------------------------
 * Class used to represent a two-dimensional vector using integral values.
*/
struct Vector2i
{
    /* --------------------------------------------------------------------------------------------
     * The type of value used by components of type.
    */
    typedef int Value;

    /* --------------------------------------------------------------------------------------------
     * Helper instances for common values mostly used as return types or comparison.
    */
    static const Vector2i NIL;
    static const Vector2i MIN;
    static const Vector2i MAX;

    /* --------------------------------------------------------------------------------------------
     * The delimiter character to be used when extracting values from strings.
    */
    static SQChar Delim;

    /* --------------------------------------------------------------------------------------------
     * The x and y components of this type.
    */
    Value x, y;

    /* --------------------------------------------------------------------------------------------
     * Default constructor.
    */
    Vector2i();

    /* --------------------------------------------------------------------------------------------
     * Construct a vector with the same scalar value for all components.
    */
    explicit Vector2i(Value sv);

    /* --------------------------------------------------------------------------------------------
     * Construct a vector with the specified component values.
    */
    Vector2i(Value xv, Value yv);

    /* --------------------------------------------------------------------------------------------
     * Copy constructor.
    */
    Vector2i(const Vector2i & o) = default;

    /* --------------------------------------------------------------------------------------------
     * Copy constructor.
    */
    Vector2i(Vector2i && o) = default;

    /* --------------------------------------------------------------------------------------------
     * Destructor.
    */
    ~Vector2i() = default;

    /* --------------------------------------------------------------------------------------------
     * Copy assignment operator.
    */
    Vector2i & operator = (const Vector2i & o) = default;

    /* --------------------------------------------------------------------------------------------
     * Move assignment operator.
    */
    Vector2i & operator = (Vector2i && o) = default;

    /* --------------------------------------------------------------------------------------------
     * Scalar value assignment operator.
    */
    Vector2i & operator = (Value s);

    /* --------------------------------------------------------------------------------------------
     * Real two-dimensional vector assignment.
    */
    Vector2i & operator = (const Vector2 & v);

    /* --------------------------------------------------------------------------------------------
     * Addition assignment operator.
    */
    Vector2i & operator += (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Subtraction assignment operator.
    */
    Vector2i & operator -= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Multiplication assignment operator.
    */
    Vector2i & operator *= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Division assignment operator.
    */
    Vector2i & operator /= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Modulo assignment operator.
    */
    Vector2i & operator %= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Bitwise AND assignment operator.
    */
    Vector2i & operator &= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Bitwise OR assignment operator.
    */
    Vector2i & operator |= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Bitwise XOR assignment operator.
    */
    Vector2i & operator ^= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Bitwise left shift assignment operator.
    */
    Vector2i & operator <<= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Bitwise right shift assignment operator.
    */
    Vector2i & operator >>= (const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Scalar value addition assignment operator.
    */
    Vector2i & operator += (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value subtraction assignment operator.
    */
    Vector2i & operator -= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value multiplication assignment operator.
    */
    Vector2i & operator *= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value division assignment operator.
    */
    Vector2i & operator /= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value modulo assignment operator.
    */
    Vector2i & operator %= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise AND assignment operator.
    */
    Vector2i & operator &= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise OR assignment operator.
    */
    Vector2i & operator |= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise XOR assignment operator.
    */
    Vector2i & operator ^= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise left shift assignment operator.
    */
    Vector2i & operator <<= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise right shift assignment operator.
    */
    Vector2i & operator >>= (Value s);

    /* --------------------------------------------------------------------------------------------
     * Pre-increment operator.
    */
    Vector2i & operator ++ ();

    /* --------------------------------------------------------------------------------------------
     * Pre-decrement operator.
    */
    Vector2i & operator -- ();

    /* --------------------------------------------------------------------------------------------
     * Post-increment operator.
    */
    Vector2i operator ++ (int);

    /* --------------------------------------------------------------------------------------------
     * Post-decrement operator.
    */
    Vector2i operator -- (int);

    /* --------------------------------------------------------------------------------------------
     * Addition operator.
    */
    Vector2i operator + (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Subtraction operator.
    */
    Vector2i operator - (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Multiplication operator.
    */
    Vector2i operator * (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Division operator.
    */
    Vector2i operator / (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Modulo operator.
    */
    Vector2i operator % (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Bitwise AND operator.
    */
    Vector2i operator & (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Bitwise OR operator.
    */
    Vector2i operator | (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Bitwise XOR operator.
    */
    Vector2i operator ^ (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Bitwise shift left operator.
    */
    Vector2i operator << (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Bitwise shift right operator.
    */
    Vector2i operator >> (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value addition operator.
    */
    Vector2i operator + (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value subtraction operator.
    */
    Vector2i operator - (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value multiplication operator.
    */
    Vector2i operator * (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value division operator.
    */
    Vector2i operator / (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value modulo operator.
    */
    Vector2i operator % (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise AND operator.
    */
    Vector2i operator & (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise OR operator.
    */
    Vector2i operator | (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise XOR operator.
    */
    Vector2i operator ^ (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise shift left operator.
    */
    Vector2i operator << (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Scalar value bitwise shift right operator.
    */
    Vector2i operator >> (Value s) const;

    /* --------------------------------------------------------------------------------------------
     * Unary plus operator.
    */
    Vector2i operator + () const;

    /* --------------------------------------------------------------------------------------------
     * Unary minus operator.
    */
    Vector2i operator - () const;

    /* --------------------------------------------------------------------------------------------
     * Bitwise NOT operator.
    */
    Vector2i operator ~ () const;

    /* --------------------------------------------------------------------------------------------
     * Equality comparison operator.
    */
    bool operator == (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Inequality comparison operator.
    */
    bool operator != (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Less than comparison operator.
    */
    bool operator < (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Greater than comparison operator.
    */
    bool operator > (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Less than or equal comparison operator.
    */
    bool operator <= (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Greater than or equal comparison operator.
    */
    bool operator >= (const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to compare two instances of this type.
    */
    Int32 Cmp(const Vector2i & v) const;

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to compare an instance of this type with a scalar value.
    */
    Int32 Cmp(SQInteger s) const
    {
        return Cmp(Vector2i(static_cast< Value >(s)));
    }

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to compare an instance of this type with a scalar value.
    */
    Int32 Cmp(SQFloat s) const
    {
        return Cmp(Vector2i(static_cast< Value >(s)));
    }

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to compare an instance of this type with a scalar value.
    */
    Int32 Cmp(bool s) const
    {
        return Cmp(Vector2i(static_cast< Value >(s)));
    }

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to compare an instance of this type with a scalar value.
    */
    Int32 Cmp(std::nullptr_t) const
    {
        return Cmp(Vector2i(static_cast< Value >(0)));
    }

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to convert an instance of this type to a string.
    */
    CSStr ToString() const;

    /* --------------------------------------------------------------------------------------------
     * Set all components to the specified scalar value.
    */
    void SetScalar(Value ns);

    /* --------------------------------------------------------------------------------------------
     * Copy the values from another instance of this type.
    */
    void SetVector2i(const Vector2i & v);

    /* --------------------------------------------------------------------------------------------
     * Set all components to the specified values.
    */
    void SetVector2iEx(Value nx, Value ny);

    /* --------------------------------------------------------------------------------------------
     * Copy the values from a real two-dimensional vector.
    */
    void SetVector2(const Vector2 & v);

    /* --------------------------------------------------------------------------------------------
     * Set the values extracted from the specified string using the specified delimiter.
    */
    void SetStr(SQChar delim, StackStrF & values);

    /* --------------------------------------------------------------------------------------------
     * Generate random values for all components of this instance.
    */
    void Generate();

    /* --------------------------------------------------------------------------------------------
     * Generate random values for all components of this instance within the specified bounds.
    */
    void Generate(Value min, Value max);

    /* --------------------------------------------------------------------------------------------
     * Generate random values for all components of this instance within the specified bounds.
    */
    void Generate(Value xmin, Value xmax, Value ymin, Value ymax);

    /* --------------------------------------------------------------------------------------------
     * Clear the component values to default.
    */
    void Clear()
    {
        x = 0, y = 0;
    }

    /* --------------------------------------------------------------------------------------------
     * Retrieve a new instance of this type with absolute component values.
    */
    Vector2i Abs() const;

    /* --------------------------------------------------------------------------------------------
     * Extract the values for components of the Vector2i type from a string.
    */
    static const Vector2i & Get(StackStrF & str);

    /* --------------------------------------------------------------------------------------------
     * Extract the values for components of the Vector2i type from a string.
    */
    static const Vector2i & GetEx(SQChar delim, StackStrF & str);

};

} // Namespace:: SqMod

#endif // _BASE_VECTOR2I_HPP_
