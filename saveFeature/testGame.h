#pragma once

struct statsTag{
    int maxHP;
    int hp;
    int mana;
    int runes;
    int shards;
};

struct profileTag{
    char name[21];
    char class[21];
    int level;
    struct statsTag stats;
};

void characterCreation(struct profileTag *player);
void runTestGame();
void roundTable(struct profileTag *player);
void dungeon(struct profileTag *player);