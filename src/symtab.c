#include <stdlib.h>
#include <memory.h>

#define KEYSPACE 256

typedef struct trie {
    struct trie *key[KEYSPACE];
    int value;
} trie_t;

trie_t *
trie_new_node()
{
    trie_t *t;
    t = (trie_t *) malloc(sizeof(trie_t));
    
    memset(t, 0, sizeof(trie_t));
    
    return t;
}

trie_t *
trie_new()
{
    return trie_new_node();
}

void
trie_insert(trie_t *root, char *key, int value)
{
    trie_t *t = root;
    
    while(*key) {
        /* Create a node if necessary */
        if(!(t->key[*key]))
            t->key[*key] = trie_new_node();
            
        /* Walk */
        t = t->key[*key];
        
        key++;
    }
    
    /* Insert the data */
    t->value = value;
}

int
trie_get(trie_t *root, char *key)
{
    trie_t *t = root;

    while(*key) {
        /* Return -1 if the key has not been found */
        if(!(t->key[*key]))
            return -1;
    
        t = t->key[*key];
        
        key++;
    }
    
    return t->value;
}

/* Symbol table */
trie_t *symtab;

void
symtab_init()
{
    symtab = trie_new();
}

void
symtab_add(char *symbol, short location)
{
    trie_insert(symtab, symbol, location); 
}

short
symtab_get(char *symbol)
{
    trie_get(symtab, symbol);
}