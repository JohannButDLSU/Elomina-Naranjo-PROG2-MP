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
char strWeaponNames[24][36]={"Short Sword","Rogier's Rapier", "Coded Sword", "Sword of Night and Flame", "Uchigatana","Moonveil","Rivers of Blood","Hand of Malenia","Whip","Urumi","Thorned Whip","Hoslow's Petal Whip","Claymore","Starscourge Greatsword","Inseparable Sword","Maliketh's Black Blade","Astrologer's Staff","Albinauric Staff","Staff of The Guilty","Carian Regal Scepter","Finger Seal","Godslayer's Seal","Golden Order Seal","Dragon Communion Seal"};
int nWeaponStats[24][8]={
    {1,1000,0,15,13,15,15,15},// Short Swords
    {2,2000,10,25,18,13,35,35},// Short Swords
    {3,4000,20,35,21,40,40,40},// Short Swords
    {4,8000,30,45,25,55,55,55},// Short Swords

    {5,1875,20,35,15,30,0,0},//Katanas
    {6,3750,30,40,20,45,0,0},//Katanas
    {7,7500,40,45,25,60,0,0},//Katanas
    {8,15000,50,50,30,75,0,0},//Katanas

    {9,1500,15,60,20,20,0,0},//Whips
    {10,3000,20,70,25,40,10,0},//Whips
    {11,5000,30,80,30,50,0,40},//Whips
    {12,10000,35,90,35,55,20,20},//Whips

    {13,3000,15,10,9,20,0,0},//Great Swords
    {14,6000,20,15,14,40,0,20},//Great Swords
    {15,12000,25,20,19,70,60,60},//Great Swords
    {16,24000,30,25,24,80,40,60},//Great Swords

    {17,2000,5,20,12,5,25,15},//Staves
    {18,4000,10,30,14,10,45,35},//Staves
    {19,8000,15,40,16,15,65,60},//Staves
    {20,16000,25,50,18,20,85,75},//Staves

    {21,2500,10,45,10,0,15,20},//Seals
    {22,5000,15,50,12,0,35,40},//Seals
    {23,10000,20,55,14,0,65,65},//Seals
    {24,15000,25,60,18,0,75,80}//Seals
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
    strcpy(sEmptyWeapon.strName,"EMPTY");
    return sEmptyWeapon;
};

Weapon setWeaponStats(char strName[36], int* nWeaponStats){
    Weapon setWeapon;
    setWeapon.nWeaponIndex=nWeaponStats[0];
    setWeapon.nBaseCost=nWeaponStats[1];
    setWeapon.nHealth=nWeaponStats[2];
    setWeapon.nEndurance=nWeaponStats[3];
    setWeapon.nDexterity=nWeaponStats[4];
    setWeapon.nStrength=nWeaponStats[5];
    setWeapon.nIntelligence=nWeaponStats[6];
    setWeapon.nFaith=nWeaponStats[7];
    strcpy(setWeapon.strName, strName);
    return setWeapon;
}
