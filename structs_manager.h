#include "string.h"

struct Player{
    char strName[31];
    char strJobClass[11];

    int nLevel; 
    int nHealth;
    int nEndurance;
    int nDexterity;
    int nStrength;
    int nIntelligence;
    int nFaith;
 };

 struct JobClass{
    char strJobClass[11];
    int nLevel;
    int nHealth;
    int nEndurance;
    int nDexterity;
    int nStrength;
    int nIntelligence;
    int nFaith;
};

// struct Runes -> money?
// struct Shards -> keys after completing stage

// struct Inventory -> items n shtuff, contains these:
   // struct Potions -> ???
   // structs Weapons
   // struct armor


struct Save{
   struct Player player;
   struct JobClass jobClass;

};

 struct Player setPlayer(){
    struct Player player;
    strcpy(player.strName, "Goofy Goober");
    strcpy(player.strJobClass, "Jobless :(");
    player.nLevel = 1;
    player.nHealth = 1;
    player.nEndurance = 1;
    player.nDexterity = 1;
    player.nStrength = 1;
    player.nIntelligence = 1;
    player.nFaith = 1;

    return player;
 }

 struct JobClass setJobClass(char* strJobClass, int nLevel, int nHealth, int nEndurance, int nDexterity, int nStrength, int nIntelligence, int nFaith){
    struct JobClass jobClass;
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

 struct Player statCopy(struct Player player, struct JobClass jobClass){
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