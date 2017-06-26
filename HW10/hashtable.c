#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

static hashtable_ent_t* add_new(hashtable_ent_t** entry, const char* key) {
    if (entry == NULL || key == NULL) return NULL;
    *entry = (hashtable_ent_t*)malloc(sizeof(hashtable_ent_t));
    if (*entry == NULL) return NULL;
    (*entry)->key = strdup(key);
    if ((*entry)->key == NULL) {
        free(*entry);
        return NULL;
    }
    (*entry)->next = NULL;
    return *entry;
}

/*
 * Helper function that does most of the implemention work
 */
static hashtable_ent_t* locate(hashtable_t* ht, const char* key, int create_if_missing) {
    if (ht == NULL || key == NULL) return NULL;
    int h = hash(key) % ht->table_len;
    hashtable_ent_t* node = ht->table[h];
    if (node != NULL) {
        /* Search until we find a match or hit the end */
        while (node->next != NULL && strcmp(key, node->key)) node = node->next;
        if (!strcmp(key, node->key)) {
            return node;
        } else if (node->next == NULL && create_if_missing) {
            /* If we failed to find the key, we can create an entry in place */
            return add_new(&node->next, key);
        }
    } else if (create_if_missing) {
        return add_new(&ht->table[h], key);
    }
    return NULL;
}

hashtable_t *create_hashtable(int max_size) {
   //TODO
	if (max_size <=0) return NULL;
	
	hashtable_t* myTable = (hashtable_t*)malloc(sizeof(hashtable_t));
    myTable->table_len = max_size;
	myTable->table = (hashtable_ent_t**)malloc(max_size*sizeof(hashtable_ent_t*));
    int i = 0;
    for (i = 0; i < max_size; i++) {
        myTable->table[i] = NULL;
    }

	return myTable;	
}

void free_hashtable(hashtable_t *ht) {
    //TODO
	int i =0;
	if (ht == NULL) {
		return;		
	}	
	if (ht->table == NULL) {
		return;
	}

    hashtable_ent_t* A;
    for(i = 0; i < ht->table_len; i++ ) {
        while(ht->table[i] != NULL) {
		    A = ht->table[i]->next;
            free(ht->table[i]->key);
            free(ht->table[i]);
            ht->table[i] = A;
		}
        
	}
    free(ht->table);
	free(ht);
    /*
    Player * curr = allPlayers;
    Player * next = allPlayers->_next;
    while(next != NULL) {
        freePlayer(curr);       
        curr = next;
        next = next->_next; 
        
    }
    freePlayer(curr);       
    free(t);
    */


}

int get(hashtable_t *ht, const char *key, double *value) {
    //TODO
	if ((ht == NULL) || (key == NULL) || (value == NULL)) {
			return -1;
	}
	hashtable_ent_t* entry = locate(ht, key, 0);
	if (entry == NULL) return -1;
	*value = (entry->value);
 
	return 0;
}

int set(hashtable_t *ht, const char *key, double value) {
   //TODO
	if ((ht == NULL) || (key == NULL)) {
		 return -1;
	}
	// ht is main struct
	// call locate with 1 (if null then in table
	hashtable_ent_t* entry = locate(ht, key, 1);
	
	if (entry == NULL) {
		return -1;				
	}
	
	entry->value = value;
	return 0;
	
}


int key_exists(hashtable_t *ht, const char *key) {
//TODO
	if ((key == NULL) || (ht == NULL)) {
		return -1;	
	}
	else if (locate(ht, key, 0) == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

int remove_key(hashtable_t *ht, const char *key) {
//TODO
   
    if ((ht == NULL) || (key == NULL)) return -1;
    // If Key didn't exist
    if (key_exists(ht,key) == 0) {
        return -1;
    }

    hashtable_ent_t* A =  ht->table[hash(key)% ht->table_len];
    if (A == NULL) {
        return -1;
    }
    hashtable_ent_t* B = A->next; 
    if(strcmp(A->key, key) == 0) {
        free(A->key);
        free(A);
        ht->table[hash(key)% ht->table_len] = B;
        return 0;
    }

    hashtable_ent_t* C;
  
    while(B != NULL) {
        if (strcmp(B->key, key) == 0) {
            C = B->next;
            free(B->key);
            free(B);
            A->next = C;
            return 0;
        }
        else {
            C = B->next;
            A = B;
            B = C;
        }

    }

    /*
       hashtable_ent_t* A;
    for(i = 0; i < ht->table_len; i++ ) {
        while(ht->table[i] != NULL) {
            A = ht->table[i]->next;
            free(ht->table[i]->key);
            free(ht->table[i]);
            ht->table[i] = A;
        }
        
    }
    free(ht->table);
    free(ht);
    */

	return 0;

}