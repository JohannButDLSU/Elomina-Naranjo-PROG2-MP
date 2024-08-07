#pragma once
#include "weapon_details.h"

// -----------------------------------
// the actual structs
// -----------------------------------
struct sPlayer{
   String strName;
   String strJobClass;
   SpriteString spriteRows[16];

   int nLevel; 
   int nHealth;
   int nEndurance;
   int nDexterity;
   int nStrength;
   int nIntelligence;
   int nFaith;

   // For the battle
   int nMaxHealth;
   int nBattleMaxHealth;
   int nBattleCurrentHealth;

   // Data for roundtable
   int nRunes;
   int nShards[6]; // 6 shards for the 6 areas
   // Data for area
   int nPlayerPos[3]; // row, column, floor

   // Battle var
   Weapon sEquippedWeapon; //Equppied weapon
   int nPotions; // How many potions the player has

   //Inventory
   int nInventorySize;
   int *nInventory;
}; typedef struct sPlayer Player;

 struct sJobClass{
   String strJobClass;
   int nLevel;
   int nHealth;
   int nEndurance;
   int nDexterity;
   int nStrength;
   int nIntelligence;
   int nFaith;
}; typedef struct sJobClass JobClass;


// struct Inventory -> items n shtuff, contains these:
   // int Potions -> ???
   // structs Weapons
   // struct armor

// -----------------------------------
// Initializations
// -----------------------------------

Player setPlayer(){
   Player player;
   strcpy(player.strName, "Unnamed Bozo xD");
   strcpy(player.strJobClass, "Jobless :(");
   player.nLevel = 0;
   player.nHealth = 0;
   player.nEndurance = 0;
   player.nDexterity = 0;
   player.nStrength = 0;
   player.nIntelligence = 0;
   player.nFaith = 0;

   player.nRunes=0;
   for (int nShards=0; nShards<7; nShards++){
      player.nShards[nShards]=0;
   }
   for (int nPos=0; nPos<3; nPos++){
      player.nPlayerPos[nPos]=0;
   }
   player.sEquippedWeapon=initializeEmptyWeapon();
   player.nPotions=0;

   player.nInventorySize=0;
   player.nInventory=calloc(player.nInventorySize, sizeof(int));
   player.nMaxHealth = player.nHealth;
   return player;
 }

JobClass setJobClass(char* strJobClass, int nLevel, int nHealth, int nEndurance, int nDexterity, int nStrength, int nIntelligence, int nFaith){
   JobClass jobClass;
   strcpy(jobClass.strJobClass, strJobClass);
   jobClass.nLevel = nLevel;
   jobClass.nHealth = nHealth;
   jobClass.nEndurance = nEndurance;
   jobClass.nDexterity = nDexterity;
   jobClass.nStrength = nStrength;
   jobClass.nIntelligence = nIntelligence;
   jobClass.nFaith = nFaith;

   return jobClass;
 }

Player statCopy(Player player, JobClass jobClass){
   strcpy(player.strJobClass, jobClass.strJobClass);
   player.nLevel = jobClass.nLevel;
   player.nHealth = jobClass.nHealth;
   player.nEndurance = jobClass.nEndurance;
   player.nDexterity = jobClass.nDexterity;
   player.nStrength = jobClass.nStrength;
   player.nIntelligence = jobClass.nIntelligence;
   player.nFaith = jobClass.nFaith;

   player.nMaxHealth = player.nHealth;

   return player;
}