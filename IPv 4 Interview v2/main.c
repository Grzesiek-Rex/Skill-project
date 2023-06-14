#include "main.h"

//global variable due to the fact that the functions "add", "del" and "check" do not take this structure as an argument - according to the task
struct IPv4PrefixManager prefixManager; 

int main()
{
    initPrefixManager(INITIAL_CAPACITY, GROWTH_RATE);

    add(0xFFFFFA00, 24);
    add(0xFFFFFA00, 24); //duplicate
    add(0xFFFFFF0A, 33); //bad mask
    add(0xFFFF0000, 24);
    add(0x0A140000, 16);
    add(0x20408000, 22);
    add(0x20408000, 20);
    add(0x20408000, 18);

    check(0x20408888);

    del(0x20408000, 21); //such an element does not exist
    del(0x20408000, 20);    
    del(0x0A140000, 16);

    check(0x20408888);

    freePrefixes();
    return 0;
}

// Initializes the starting values of the structure from prefix management. 
// params: initial_capacity - the initial capacity of the prefix manager, growth_rate - by this much the capacity is increased
void initPrefixManager(int initial_capacity, int growth_rate) 
{
    prefixManager.prefixes = malloc(initial_capacity * sizeof(struct IPv4Prefix));
    prefixManager.count = 0;
    prefixManager.capacity = initial_capacity;
    prefixManager.growth_rate = growth_rate;
}

// Releases memory associated with prefixMenager structure
void freePrefixes() 
{
    free(prefixManager.prefixes);
    prefixManager.prefixes = NULL;
    prefixManager.count = 0;
    prefixManager.capacity = 0;
}

// Adding prefixes to the prefix manager with input control. Sorts the data, based on the mask, to optimize the "check" function.
// params: baseIP - baseIP (example: 0x10204000), mask - mask (example: 16)
int add(unsigned int baseIP, char mask) 
{
    if (mask < 0 || mask > 32) 
    {
        return -1; 
    }

    for (int i = 0; i < prefixManager.count; ++i) 
    {
        if (prefixManager.prefixes[i].baseIP == baseIP && prefixManager.prefixes[i].mask == mask) 
        {
            return 1;  
        }
    }

    if (prefixManager.count >= prefixManager.capacity) 
    {
        prefixManager.capacity += prefixManager.growth_rate;
        prefixManager.prefixes = realloc(prefixManager.prefixes, prefixManager.capacity * sizeof(struct IPv4Prefix));
    }

    int insertIndex = prefixManager.count;
    for (int i = 0; i < prefixManager.count; ++i) 
    {
        if (prefixManager.prefixes[i].mask < mask) 
        {
            insertIndex = i;
            break;
        }
    }

    for (int i = prefixManager.count; i > insertIndex; --i) 
    {
        prefixManager.prefixes[i] = prefixManager.prefixes[i - 1];
    }

    struct IPv4Prefix* prefix = &prefixManager.prefixes[insertIndex];
    prefix->baseIP = baseIP;
    prefix->mask = mask;
    prefixManager.count++;

    return 1;
}

// Removal of prefixes to the prefix manager along with data entry control.
// params: baseIP - baseIP (example: 0x10204000), mask - mask (example: 16)
int del(unsigned int baseIP, char mask) 
{
    if (mask < 0 || mask > 32) 
    {
        return -1;
    }

    for (int i = 0; i < prefixManager.count; ++i) 
    {
        if (prefixManager.prefixes[i].baseIP == baseIP && prefixManager.prefixes[i].mask == mask) 
        {
            struct IPv4Prefix* prefix = &prefixManager.prefixes[i];

            for (int j = i; j < prefixManager.count - 1; ++j) 
            {
                prefixManager.prefixes[j] = prefixManager.prefixes[j + 1];
            }

            prefixManager.count--;

            if (prefixManager.capacity - prefixManager.count > prefixManager.growth_rate) 
            {
                prefixManager.capacity -= prefixManager.growth_rate;
                prefixManager.prefixes = realloc(prefixManager.prefixes, prefixManager.capacity * sizeof(struct IPv4Prefix));
            }
            return 1;  
        }
    }
    return -1;  
}

// Check if the ip address is contained in a set of prefixes. Returns the mask of the smallest prefix in the set that contains the indicated address. 
// The computational complexity of the "check" function, depending on the case, ranges from O(1) to O(n).
// params: ip - IP address (example: 0x10204088)
char check(unsigned int ip) 
{
    char found_mask = -1;

    for (int i = 0; i < prefixManager.count; ++i) 
    {
        char mask = prefixManager.prefixes[i].mask;
        unsigned int baseIP = prefixManager.prefixes[i].baseIP;
        unsigned int full_mask = (0xFFFFFFFF << (32 - mask));

        if ((baseIP & full_mask) == (ip & full_mask)) 
        {
            found_mask = mask;
            break;
        }
    }

    return found_mask;
}