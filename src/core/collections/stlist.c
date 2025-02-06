#include <stdio.h>
#include <string.h>
#include "stlist.h"

StList* StList_new(nint capacity)
{
    StList* l = (StList*)malloc(sizeof(StList));
    l->items = malloc(capacity * sizeof(void*));
    l->capacity = capacity;
    l->length = 0;
    return l;
}

bool StList_resize(StList* l, nint new_capacity)
{
    void* newdata = realloc(l->items, new_capacity * sizeof(void*));
    if (newdata == NULL) {
        fprintf(stderr, "Memory reallocation error\n");
        return false;
    }

    l->items = newdata;
    l->capacity = new_capacity;
    return true;
}

bool StList_add(StList* l, void* item)
{
    if (l->length >= l->capacity) {
        nint new_cap = l->capacity == 0 ? 8 : l->capacity * 2;
        if (!StList_resize(l, new_cap)) {
            return false;
        }
    }
    // man
    ((void**)l->items)[l->length] = item;
    l->length++;
    return true;
}

void* StList_at(StList* l, nint idx)
{
    fflush(stdout);
    // not a huge fan of segfaults
    if (idx >= l->length) {
        fprintf(stderr, "Index out of range\n");
        return NULL;
    }

    return ((void**)l->items)[idx];
}

void StList_set(StList* l, nint idx, void* item)
{
    // not a huge fan of segfaults
    if (idx >= l->length) {
        fprintf(stderr, "Index out of range\n");
        return;
    }

    ((void**)l->items)[idx] = item;
}

void StList_free(StList* l)
{
    free(l->items);
    free(l);
}
