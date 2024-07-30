#pragma once
#include "player_struct_manager.h"

Weapon initializeEmptyWeapon(){
    Weapon sEmptyWeapon;
    sEmptyWeapon.nWeaponIndex=-1;
    sEmptyWeapon.nBaseCost=0;
    sEmptyWeapon.nHealth=0;
    sEmptyWeapon.nEndurance=0;
    sEmptyWeapon.nDexterity=0;
    sEmptyWeapon.nStrength=0;
    sEmptyWeapon.nIntelligence=0;
    sEmptyWeapon.nFaith=0;
    strcpy(sEmptyWeapon.strName, "EMPTY");
    return sEmptyWeapon;
};

// Swords
shortSword
// Katanas
// Whips
// Greatswords
// Staves
// Seals
