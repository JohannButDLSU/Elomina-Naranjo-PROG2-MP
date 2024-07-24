#pragma once

// -----------------------------------
// the actual structs
// -----------------------------------

struct sPlayer{
    char strName[31];
    char strJobClass[11];

    int nLevel; 
    int nHealth;
    int nEndurance;
    int nDexterity;
    int nStrength;
    int nIntelligence;
    int nFaith;
 }; typedef struct sPlayer Player;

 struct sJobClass{
    char strJobClass[11];
    int nLevel;
    int nHealth;
    int nEndurance;
    int nDexterity;
    int nStrength;
    int nIntelligence;
    int nFaith;
}; typedef struct sJobClass JobClass;

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
   strcpy(player.strName, "Goofy Goober");
   strcpy(player.strJobClass, "Jobless :(");
   player.nLevel = 0;
   player.nHealth = 0;
   player.nEndurance = 0;
   player.nDexterity = 0;
   player.nStrength = 0;
   player.nIntelligence = 0;
   player.nFaith = 0;

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