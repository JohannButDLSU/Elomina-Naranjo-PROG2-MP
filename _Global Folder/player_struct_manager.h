#pragma once

#define VAGABOND_ROW_0  "████████████0███████████████████"
#define VAGABOND_ROW_1  "█████████████1██████████████████"
#define VAGABOND_ROW_2  "██████████████2█████████████████"
#define VAGABOND_ROW_3  "███████████████3████████████████"
#define VAGABOND_ROW_4  "████████████████████████████████"
#define VAGABOND_ROW_5  "████████████████████████████████"
#define VAGABOND_ROW_6  "████████████████████████████████"
#define VAGABOND_ROW_7  "vagabond████████████████████████"
#define VAGABOND_ROW_8  "████████████████████████████████"
#define VAGABOND_ROW_9  "████████████████████████████████"
#define VAGABOND_ROW_10 "████████████████████████████████"
#define VAGABOND_ROW_11 "████████████████████████████████"
#define VAGABOND_ROW_12 "████████████████████████████████"
#define VAGABOND_ROW_13 "████████████████████████████████"
#define VAGABOND_ROW_14 "████████████████████████████████"
#define VAGABOND_ROW_15 "████████████████████████████████"

const String VAGABOND_ROWS[16] = {
   VAGABOND_ROW_0,
   VAGABOND_ROW_1,
   VAGABOND_ROW_2,
   VAGABOND_ROW_3,
   VAGABOND_ROW_4,
   VAGABOND_ROW_5,
   VAGABOND_ROW_6,
   VAGABOND_ROW_7,
   VAGABOND_ROW_8,
   VAGABOND_ROW_9,
   VAGABOND_ROW_10,
   VAGABOND_ROW_11,
   VAGABOND_ROW_12,
   VAGABOND_ROW_13,
   VAGABOND_ROW_14,
   VAGABOND_ROW_15,
};

// -----------------------------------
// the actual structs
// -----------------------------------

struct sPlayer{
   String strName;
   String strJobClass;

   int nLevel; 
   int nHealth;
   int nEndurance;
   int nDexterity;
   int nStrength;
   int nIntelligence;
   int nFaith;

   // Data for roundtable
   int nRunes;
   int nShards[7]; // 7 shards for the 7 areas
   // Data for area
   int nPlayerPos[3]; // row, column, floor
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

struct sPlayerSprite{
   SpriteString strRowPixels[16];
}; typedef struct sPlayerSprite PlayerSprite;

// integer Runes -> money?
// integer Shards -> keys after completing stage

// struct Inventory -> items n shtuff, contains these:
   // int Potions -> ???
   // structs Weapons
   // struct armor

struct Weapon{
   int type;
};

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

   return player;
}