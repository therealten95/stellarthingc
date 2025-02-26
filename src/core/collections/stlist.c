#include <stdio.h>
#include <string.h>
#include "stlist.h"
#include "core/starry.h"

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
        nint new_cap = l->capacity * 2 + 1;
        if (!StList_resize(l, new_cap)) {
            return false;
        }
    }

    l->items[l->length] = item;
    l->length++;
    return true;
}

void* StList_at(StList* l, nint idx)
{
    // not a huge fan of segfaults
    if (idx >= l->length) {
        fprintf(stderr, "Index out of range\n");
        // a segfault is about to happen!
        fflush(stdout);
        return NULL;
    }
    
    return ((void**)l->items)[idx];
}

void StList_set(StList* l, nint idx, void* item)
{
    // not a huge fan of segfaults
    if (idx >= l->length) {
        fprintf(stderr, "Index out of range\n");
        // a segfault is about to happen!
        fflush(stdout);
        return;
    }

    ((void**)l->items)[idx] = item;
}

void StList_free(StList* l)
{
    free(l->items);
    free(l);
}

void StList_free_with_items(StList* l)
{
    for (nint i = 0; i < l->length; i++) {
        free(StList_at(l, i));
    }
    StList_free(l);
}