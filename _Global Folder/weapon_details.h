#pragma once
#include "player_struct_manager.h"

struct sWeapon{
   int nWeaponIndex;
   int nBaseCost;
   int nHealth;
   int nEndurance;
   int nDexterity;
   int nStrength;
   int nIntelligence;
   int nFaith;
   char strName[36];
}; typedef struct sWeapon Weapon;

// Each i in [i][j] is the weapon index with their corresponding data [j]
char weaponIcons[24][8]={"🗡"};
char weaponNames[24][36]={"Short Sword","Rogier's Rapier", "Coded Sword", "Sword of Night and Flame", "Uchigatana","Moonveil","Rivers of Blood","Hand of Malenia"};
int nWeaponStats[24][8]={
    {1,1000,0,15,13,15,15,15},
    {2,2000,10,25,18,13,35,35},
    {3,4000,20,35,21,40,40,40},
    {4,8000,30,45,25,55,55,55}
};

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

Weapon setWeaponStats(char strName[36], int nWeaponIndex, int nBaseCost,int nHealth,int nEndurance,int nDexterity, int nStrength, int nIntelligence, int nFaith){
    Weapon setWeapon;
    setWeapon.nWeaponIndex=nWeaponIndex;
    setWeapon.nBaseCost=nBaseCost;
    setWeapon.nHealth=nHealth;
    setWeapon.nEndurance=nEndurance;
    setWeapon.nDexterity=nDexterity;
    setWeapon.nStrength=nStrength;
    setWeapon.nIntelligence=nIntelligence;
    setWeapon.nFaith=nFaith;
    strcpy(setWeapon.strName, strName);
    return setWeapon;
}
