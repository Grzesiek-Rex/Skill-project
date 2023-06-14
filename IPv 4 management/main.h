#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>     //for malloc, realloc, free

#define INITIAL_CAPACITY 5
#define GROWTH_RATE 5

struct IPv4Prefix 
{
    unsigned int baseIP;
    char mask;
};

struct IPv4PrefixManager 
{
    struct IPv4Prefix* prefixes;
    int count;
    int capacity;
    int growth_rate;
};

void initPrefixManager(struct IPv4PrefixManager* prefixManager, int initial_capacity, int growth_rate);
void freePrefixes(struct IPv4PrefixManager* prefixManager);
int add(struct IPv4PrefixManager* prefixManager, unsigned int baseIP, char mask);
int del(struct IPv4PrefixManager* prefixManager, unsigned int baseIP, char mask);
char check(struct IPv4PrefixManager* prefixManager, unsigned int ip);

#endif