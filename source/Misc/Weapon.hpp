#ifndef _MISC_WEAPON_HPP_
#define _MISC_WEAPON_HPP_

// ------------------------------------------------------------------------------------------------
#include "SqBase.hpp"

// ------------------------------------------------------------------------------------------------
namespace SqMod {

/* ------------------------------------------------------------------------------------------------
 * Retrieve the slot associated with a weapon identifier.
*/
Uint32 GetWeaponSlot(Uint32 id);

/* ------------------------------------------------------------------------------------------------
 * Retrieve the name associated with a weapon identifier.
*/
CSStr GetWeaponName(Uint32 id);

/* ------------------------------------------------------------------------------------------------
 * Modify the name associated with a weapon identifier.
*/
void SetWeaponName(Uint32 id, StackStrF & name);

/* ------------------------------------------------------------------------------------------------
 * Retrieve the total number of identifiers in the pool of custom weapon names.
*/
Uint32 GetCustomWeaponNamePoolSize();

/* ------------------------------------------------------------------------------------------------
 * Clear all identifiersand associated names from the pool of custom weapon names.
*/
void ClearCustomWeaponNamePool();

/* ------------------------------------------------------------------------------------------------
 * Modify the name associated with a weapon identifier.
*/
void SetWeaponName(Uint32 id, StackStrF & name);

/* ------------------------------------------------------------------------------------------------
 * Convert a weapon name to a weapon identifier.
*/
Int32 GetWeaponID(StackStrF & name);

/* ------------------------------------------------------------------------------------------------
 * See whether the specified weapon identifier is valid.
*/
bool IsWeaponValid(Int32 id);

/* ------------------------------------------------------------------------------------------------
 * Convert the given weapon identifier to it's associated model identifier.
*/
Int32 WeaponToModel(Int32 id);

/* ------------------------------------------------------------------------------------------------
 * See whether the given weapon identifier cannot be used by another player to inflict damage.
*/
bool IsWeaponNatural(Int32 id);

} // Namespace:: SqMod

#endif // _MISC_WEAPON_HPP_
