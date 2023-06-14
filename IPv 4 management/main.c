#include "main.h"

int main()
{
    struct IPv4PrefixManager prefixManager; 
    initPrefixManager(&prefixManager, INITIAL_CAPACITY, GROWTH_RATE);

    add(&prefixManager, 0xFFFFFF0A, 24);
    add(&prefixManager, 0xFFFFFF0A, 24); //duplicate
    add(&prefixManager, 0xFFFFFF0A, 33); //bad mask
    add(&prefixManager, 0xFFFF00FA, 24);
    add(&prefixManager, 0x0A140000, 16);
    add(&prefixManager, 0x20408000, 20);
    add(&prefixManager, 0x20408000, 18);
    add(&prefixManager, 0x20408000, 16);

    check(&prefixManager, 0x20408888);

    del(&prefixManager, 0x20408000, 21); //bad mask
    del(&prefixManager, 0x20408000, 20);    
    del(&prefixManager, 0x0A140000, 16);

    check(&prefixManager, 0x20408888);

    freePrefixes(&prefixManager);
    return 0;
}

// Initializes the starting values of the structure from prefix management. 
// params: initial_capacity - the initial capacity of the prefix manager, growth_rate - by this much the capacity is increased
void initPrefixManager(struct IPv4PrefixManager* prefixManager, int initial_capacity, int growth_rate)
{
    prefixManager->prefixes = malloc(initial_capacity * sizeof(struct IPv4Prefix));
    prefixManager->count = 0;
    prefixManager->capacity = initial_capacity;
    prefixManager->growth_rate = growth_rate;
}

// Releases memory associated with prefixMenager structure
void freePrefixes(struct IPv4PrefixManager* prefixManager)
{
    free(prefixManager->prefixes);
    prefixManager->prefixes = NULL;
    prefixManager->count = 0;
    prefixManager->capacity = 0;
}

// Adding prefixes to the prefix manager with input control.
// params: baseIP - baseIP (example: 0x10204000), mask - mask (example: 16)
int add(struct IPv4PrefixManager* prefixManager, unsigned int baseIP, char mask)
{
    if (mask < 0 || mask > 32) 
    {
        return -1; 
    }

    for (int i = 0; i < prefixManager->count; ++i) 
    {
        if (prefixManager->prefixes[i].baseIP == baseIP && prefixManager->prefixes[i].mask == mask) 
        {
            return 1;  
        }
    }

    if (prefixManager->count >= prefixManager->capacity) 
    {
        prefixManager->capacity += prefixManager->growth_rate;
        prefixManager->prefixes = realloc(prefixManager->prefixes, prefixManager->capacity * sizeof(struct IPv4Prefix));
    }

    struct IPv4Prefix* prefix = &prefixManager->prefixes[prefixManager->count];
    prefix->baseIP = baseIP;
    prefix->mask = mask;
    prefixManager->count++;

    return 1;
}

// Removal of prefixes to the prefix manager along with data entry control.
// params: baseIP - baseIP (example: 0x10204000), mask - mask (example: 16)
int del(struct IPv4PrefixManager* prefixManager, unsigned int baseIP, char mask) 
{
    if (mask < 0 || mask > 32) 
    {
        return -1;
    }

    for (int i = 0; i < prefixManager->count; ++i) 
    {
        if (prefixManager->prefixes[i].baseIP == baseIP && prefixManager->prefixes[i].mask == mask) 
        {
            struct IPv4Prefix* prefix = &prefixManager->prefixes[i];

            for (int j = i; j < prefixManager->count - 1; ++j) 
            {
                prefixManager->prefixes[j] = prefixManager->prefixes[j + 1];
            }

            prefixManager->count--;

            if (prefixManager->capacity - prefixManager->count > prefixManager->growth_rate) 
            {
                prefixManager->capacity -= prefixManager->growth_rate;
                prefixManager->prefixes = realloc(prefixManager->prefixes, prefixManager->capacity * sizeof(struct IPv4Prefix));
            }
            return 1;  
        }
    }
    return -1;  
}

// Check if the ip address is contained in a set of prefixes. Returns the mask of the smallest prefix in the set that contains the indicated address. 
// params: ip - IP address (example: 0x10204088)
char check(struct IPv4PrefixManager* prefixManager, unsigned int ip)
{
    char found_mask = -1;

    for (int i = 0; i < prefixManager->count; ++i) 
    {
        char mask = prefixManager->prefixes[i].mask;
        unsigned int baseIP = prefixManager->prefixes[i].baseIP;
        unsigned int full_mask = (0xFFFFFFFF << (32 - mask));

        if ((baseIP & full_mask) == (ip & full_mask)) 
        {
            if (found_mask == -1 || mask > found_mask) 
            {
                found_mask = mask;
            }
        }
    }

    return found_mask;
}