#ifndef _ENTITY_PICKUP_HPP_
#define _ENTITY_PICKUP_HPP_

// ------------------------------------------------------------------------------------------------
#include "Base/Shared.hpp"

// ------------------------------------------------------------------------------------------------
namespace SqMod {

/* ------------------------------------------------------------------------------------------------
 * Circular locks employed by the pickup manager.
*/
enum PickupCircularLocks
{
    PICKUPCL_EMIT_PICKUP_OPTION     = (1 << 0),
    PICKUPCL_EMIT_PICKUP_WORLD      = (1 << 1),
    PICKUPCL_EMIT_PICKUP_ALPHA      = (1 << 2),
    PICKUPCL_EMIT_PICKUP_AUTOMATIC  = (1 << 3),
    PICKUPCL_EMIT_PICKUP_AUTOTIMER  = (1 << 4)
};

/* ------------------------------------------------------------------------------------------------
 * Manages a single pickup entity.
*/
class CPickup
{
    // --------------------------------------------------------------------------------------------
    friend class Core;

private:

    /* --------------------------------------------------------------------------------------------
     * Identifier of the managed entity.
    */
    Int32       m_ID;

    /* --------------------------------------------------------------------------------------------
     * User tag associated with this instance.
    */
    String      m_Tag;

    /* --------------------------------------------------------------------------------------------
     * User data associated with this instance.
    */
    LightObj    m_Data;

    /* --------------------------------------------------------------------------------------------
     * Prevent events from triggering themselves.
    */
    Uint32      m_CircularLocks;

    /* --------------------------------------------------------------------------------------------
     * Base constructor.
    */
    CPickup(Int32 id);

public:

    /* --------------------------------------------------------------------------------------------
     * Maximum possible number that could represent an identifier for this entity type.
    */
    static const Int32 Max;

    /* --------------------------------------------------------------------------------------------
     * Copy constructor. (disabled)
    */
    CPickup(const CPickup &) = delete;

    /* --------------------------------------------------------------------------------------------
     * Move constructor. (disabled)
    */
    CPickup(CPickup &&) = delete;

    /* --------------------------------------------------------------------------------------------
     * Destructor.
    */
    ~CPickup();

    /* --------------------------------------------------------------------------------------------
     * Copy assignment operator. (disabled)
    */
    CPickup & operator = (const CPickup &) = delete;

    /* --------------------------------------------------------------------------------------------
     * Move assignment operator. (disabled)
    */
    CPickup & operator = (CPickup &&) = delete;

    /* --------------------------------------------------------------------------------------------
     * See whether this instance manages a valid entity instance otherwise throw an exception.
    */
    void Validate() const
    {
        if (INVALID_ENTITY(m_ID))
        {
            STHROWF("Invalid pickup reference [%s]", m_Tag.c_str());
        }
    }

    /* --------------------------------------------------------------------------------------------
     * Used by the script engine to convert an instance of this type to a string.
    */
    const String & ToString() const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the associated null entity instance.
    */
    static SQInteger SqGetNull(HSQUIRRELVM vm);

    /* --------------------------------------------------------------------------------------------
     * Retrieve the associated null entity instance.
    */
    static LightObj & GetNull();

    /* --------------------------------------------------------------------------------------------
     * Retrieve the identifier of the entity managed by this instance.
    */
    Int32 GetID() const
    {
        return m_ID;
    }

    /* --------------------------------------------------------------------------------------------
     * Check whether this instance manages a valid entity.
    */
    bool IsActive() const
    {
        return VALID_ENTITY(m_ID);
    }

    /* --------------------------------------------------------------------------------------------
     * Retrieve the associated user tag.
    */
    const String & GetTag() const;

    /* --------------------------------------------------------------------------------------------
     * Modify the associated user tag.
    */
    void SetTag(StackStrF & tag);

    /* --------------------------------------------------------------------------------------------
     * Modify the associated user tag.
    */
    CPickup & ApplyTag(StackStrF & tag);

    /* --------------------------------------------------------------------------------------------
     * Retrieve the associated user data.
    */
    LightObj & GetData();

    /* --------------------------------------------------------------------------------------------
     * Modify the associated user data.
    */
    void SetData(LightObj & data);

    /* --------------------------------------------------------------------------------------------
     * Destroy the managed pickup entity.
    */
    bool Destroy()
    {
        return Destroy(0, NullLightObj());
    }

    /* --------------------------------------------------------------------------------------------
     * Destroy the managed pickup entity.
    */
    bool Destroy(Int32 header)
    {
        return Destroy(header, NullLightObj());
    }

    /* --------------------------------------------------------------------------------------------
     * Destroy the managed pickup entity.
    */
    bool Destroy(Int32 header, LightObj & payload);

    /* --------------------------------------------------------------------------------------------
     * Retrieve the events table of this entity.
    */
    LightObj & GetEvents() const;

    /* --------------------------------------------------------------------------------------------
     * Emit a custom event for the managed entity
    */
    void CustomEvent(Int32 header, LightObj & payload) const;

    /* --------------------------------------------------------------------------------------------
     * See if the managed pickup entity is streamed for the specified player.
    */
    bool IsStreamedFor(CPlayer & player) const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the current option value of the managed pickup entity.
    */
    bool GetOption(Int32 option_id) const;

    /* --------------------------------------------------------------------------------------------
     * Modify the current option value of the managed pickup entity.
    */
    void SetOption(Int32 option_id, bool toggle);

    /* --------------------------------------------------------------------------------------------
     * Modify the current option value of the managed pickup entity.
    */
    void SetOptionEx(Int32 option_id, bool toggle, Int32 header, LightObj & payload);

    /* --------------------------------------------------------------------------------------------
     * Retrieve the world in which the managed pickup entity exists.
    */
    Int32 GetWorld() const;

    /* --------------------------------------------------------------------------------------------
     * Mpdify the world in which the managed pickup entity exists.
    */
    void SetWorld(Int32 world);

    /* --------------------------------------------------------------------------------------------
     * Retrieve the alpha of the managed pickup entity.
    */
    Int32 GetAlpha() const;

    /* --------------------------------------------------------------------------------------------
     * Mpdify the alpha of the managed pickup entity.
    */
    void SetAlpha(Int32 alpha);

    /* --------------------------------------------------------------------------------------------
     * See whether the managed pickup entity is automatic.
    */
    bool GetAutomatic() const;

    /* --------------------------------------------------------------------------------------------
     * Set whether the managed pickup entity is automatic.
    */
    void SetAutomatic(bool toggle);

    /* --------------------------------------------------------------------------------------------
     * Retrieve the automatic timer of the managed pickup entity.
    */
    Int32 GetAutoTimer() const;

    /* --------------------------------------------------------------------------------------------
     * Mpdify the automatic timer of the managed pickup entity.
    */
    void SetAutoTimer(Int32 timer);

    /* --------------------------------------------------------------------------------------------
     * Refresh the managed pickup entity.
    */
    void Refresh() const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the position of the managed pickup entity.
    */
    Vector3 GetPosition();

    /* --------------------------------------------------------------------------------------------
     * Mpdify the position of the managed pickup entity.
    */
    void SetPosition(const Vector3 & pos) const;

    /* --------------------------------------------------------------------------------------------
     * Mpdify the position of the managed pickup entity.
    */
    void SetPositionEx(Float32 x, Float32 y, Float32 z) const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the model of the managed pickup entity.
    */
    Int32 GetModel() const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the quantity of the managed pickup entity.
    */
    Int32 GetQuantity() const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the position on the x axis of the managed pickup entity.
    */
    Float32 GetPositionX() const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the position on the y axis of the managed pickup entity.
    */
    Float32 GetPositionY() const;

    /* --------------------------------------------------------------------------------------------
     * Retrieve the position on the z axis of the managed pickup entity.
    */
    Float32 GetPositionZ() const;

    /* --------------------------------------------------------------------------------------------
     * Modify the position on the x axis of the managed pickup entity.
    */
    void SetPositionX(Float32 x) const;

    /* --------------------------------------------------------------------------------------------
     * Modify the position on the y axis of the managed pickup entity.
    */
    void SetPositionY(Float32 y) const;

    /* --------------------------------------------------------------------------------------------
     * Modify the position on the z axis of the managed pickup entity.
    */
    void SetPositionZ(Float32 z) const;
};

} // Namespace:: SqMod

#endif // _ENTITY_PICKUP_HPP_