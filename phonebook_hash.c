#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */


entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
       /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}


unsigned int BKDRHash(char *str)
{
    unsigned int hash = 0;
    while (*str) {
        hash = hash * 131 + (*str++);
    }   
    return (hash & 0x7FFFFFFF);
}

