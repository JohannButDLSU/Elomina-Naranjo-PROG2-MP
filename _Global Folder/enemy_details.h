#define TYPE_1_LOWHP 20
#define TYPE_1_HIGHHP 30
#define TYPE_2_LOWHP 25
#define TYPE_2_HIGHHP 35
#define TYPE_3_LOWHP 70
#define TYPE_3_HIGHHP 80

#define TYPE1_PHYSDEF 0.2
#define TYPE1_SORCDEF 0.15
#define TYPE1_INCADEF 0.1
#define TYPE2_PHYSDEF 0.5
#define TYPE2_SORCDEF 0.15
#define TYPE2_INCADEF 0.2
#define TYPE3_PHYSDEF 0.25
#define TYPE3_SORCDEF 0.25
#define TYPE3_INCADEF 0.2

struct sEnemy{
    String strName;
    int nType;

    int nMaxHealth;
    int nHealth; // random at start
    // I won't put attack here since it's basically a random int based on nType

    float fPhysDef;
    float fSorcDef;
    float fIncaDef;

}; typedef struct sEnemy Enemy;

Enemy initializeEnemy(int nRoomIndex, int nType){ // nRoomIndex shud be based on room, and nType is random 1-3
    Enemy toReturn;

    toReturn.nType = nType;

    switch (nType)
    {
        case 1:
            toReturn.nHealth = (rand() % (TYPE_1_HIGHHP - TYPE_1_LOWHP + 1) + TYPE_1_LOWHP);
            toReturn.fPhysDef = TYPE1_PHYSDEF;
            toReturn.fSorcDef = TYPE1_SORCDEF;
            toReturn.fIncaDef = TYPE1_INCADEF;
            break;
        case 2:
            toReturn.nHealth = (rand() % (TYPE_2_HIGHHP - TYPE_2_LOWHP + 1) + TYPE_2_LOWHP);
            toReturn.fPhysDef = TYPE2_PHYSDEF;
            toReturn.fSorcDef = TYPE2_SORCDEF;
            toReturn.fIncaDef = TYPE2_INCADEF;
            break;
        case 3:
            toReturn.nHealth = (rand() % (TYPE_3_HIGHHP - TYPE_3_LOWHP + 1) + TYPE_3_LOWHP);
            toReturn.fPhysDef = TYPE3_PHYSDEF;
            toReturn.fSorcDef = TYPE3_SORCDEF;
            toReturn.fIncaDef = TYPE3_INCADEF;
            break;
        default: break;
    }
    toReturn.nHealth *= nRoomIndex;

    if (nRoomIndex == 1){
        if (nType == 1) strcpy(toReturn.strName, "Godrick Soldier");
        if (nType == 2) strcpy(toReturn.strName, "Godrick Archer");
        if (nType == 3) strcpy(toReturn.strName, "Godrick Knight");
        if (nType == 4){
            strcpy(toReturn.strName, "Godrick");
            toReturn.nHealth = 200;
            toReturn.fPhysDef = 0.35;
            toReturn.fSorcDef = 0.2;
            toReturn.fIncaDef = 0.15;
        }
    }
    else if (nRoomIndex == 2){
        if (nType == 1) strcpy(toReturn.strName, "Living Jar");
        if (nType == 2) strcpy(toReturn.strName, "Glintstone Sorcerer");
        if (nType == 3) strcpy(toReturn.strName, "Battlemage");
        if (nType == 4){
            strcpy(toReturn.strName, "Rennala");
            toReturn.nHealth = 400;
            toReturn.fPhysDef = 0.15;
            toReturn.fSorcDef = 0.35;
            toReturn.fIncaDef = 0.25;
        }
    }
    else if (nRoomIndex == 3){
        if (nType == 1) strcpy(toReturn.strName, "Radahn Soldier");
        if (nType == 2) strcpy(toReturn.strName, "Radahn Archer");
        if (nType == 3) strcpy(toReturn.strName, "Radahn Knight");
        if (nType == 4){
            strcpy(toReturn.strName, "Radahn");
            toReturn.nHealth = 600;
            toReturn.fPhysDef = 0.15;
            toReturn.fSorcDef = 0.25;
            toReturn.fIncaDef = 0.30;
        }
    }
    else if (nRoomIndex == 4){
        if (nType == 1) strcpy(toReturn.strName, "Man-Serpent");
        if (nType == 2) strcpy(toReturn.strName, "Mage-Serpent");
        if (nType == 3) strcpy(toReturn.strName, "Abductor Virgin");
        if (nType == 4){
            strcpy(toReturn.strName, "Rykard");
            toReturn.nHealth = 600;
            toReturn.fPhysDef = 0.15;
            toReturn.fSorcDef = 0.25;
            toReturn.fIncaDef = 0.30;
        }
    }
    else if (nRoomIndex == 5){
        if (nType == 1) strcpy(toReturn.strName, "Leyndell Soldier");
        if (nType == 2) strcpy(toReturn.strName, "Leyndell Archer");
        if (nType == 3) strcpy(toReturn.strName, "Leyndell Knight");
        if (nType == 4){
            strcpy(toReturn.strName, "Morgott");
            toReturn.nHealth = 800;
            toReturn.fPhysDef = 0.35;
            toReturn.fSorcDef = 0.3;
            toReturn.fIncaDef = 0.2;
        }
    }
    else if (nRoomIndex == 6){
        if (nType == 4){
            strcpy(toReturn.strName, "Radagon");
            toReturn.nHealth = 1000;
            toReturn.fPhysDef = 0.35;
            toReturn.fSorcDef = 0.25;
            toReturn.fIncaDef = 0.40;
        }
    }
    else if (nRoomIndex == 7){
        if (nType == 4){
            strcpy(toReturn.strName, "Elden Beast");
            toReturn.nHealth = 1250;
            toReturn.fPhysDef = 0.25;
            toReturn.fSorcDef = 0.50;
            toReturn.fIncaDef = 0.40;
        }
    }
    else strcpy(toReturn.strName, "ERROR???");
    toReturn.nMaxHealth = toReturn.nHealth;
    return toReturn;
}

int enemyAttack(int nRoomIndex, Enemy enemy){ // This will be formatted like playerHP -= enemyAttack(room, enemy)
    int nMin = 0;
    int nMax = 0;

    switch (enemy.nType)
    {
    case 1:
        nMin = 70;
        nMax = 80;
        break;
    case 2:
        nMin = 110;
        nMax = 120;
        break;
    case 3:
        nMin = 120;
        nMax = 130;
        break;
    case 4:
        if (strcmp(enemy.strName, "Godrick") == 0){
            nMin = 150;
            nMax = 300;
        }
        if (strcmp(enemy.strName, "Rennala") == 0){
            nMin = 200;
            nMax = 300;
        }
        if (strcmp(enemy.strName, "Radahn") == 0){
            nMin = 200;
            nMax = 400;
        }
        if (strcmp(enemy.strName, "Rykard") == 0){
            nMin = 250;
            nMax = 350;
        }
        if (strcmp(enemy.strName, "Morgott") == 0){
            nMin = 250;
            nMax = 500;
        }
        if (strcmp(enemy.strName, "Radagon") == 0){
            nMin = 300;
            nMax = 600;
        }
        if (strcmp(enemy.strName, "Elden Beast") == 0){
            nMin = 450;
            nMax = 900;
        }
        
        break;
    default:
        printf("\nenemyAttack() error. Enemy type is %d\n", enemy.nType);
        break;
    }

    return (rand() % (nMax - nMin + 1) + nMin);
}