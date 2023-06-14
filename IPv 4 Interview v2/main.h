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

void initPrefixManager(int initial_capacity, int growth_rate);
void freePrefixes();
int add(unsigned int baseIP, char mask);
int del(unsigned int baseIP, char mask);
char check(unsigned int ip);

#endif