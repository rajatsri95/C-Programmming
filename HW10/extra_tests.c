#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

#define PASS 1
#define FAIL 0
char* test_discriptions[] = {"Basic test to verify that the table is created correctly", 
    "Basic test to add a single key",
    "Basic set/get pair test",
    "Basic test for get() without key",
    "A few sets and gets, without any chaining",
    "Basic test to see if chaining works"};
    
int test1() {
    
    /**
     * Basic test to verify that the table is created correctly
     */
    int ret = PASS;
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) { 
    printf("Failed to create hashtable!\n");
        return FAIL;
    }
    if (ht->table_len != 1024) { 
    printf("The hashtable we just created has the wrong table_len!\n");
    ret= FAIL;   
    }
    int i;
    for (i = 0; i < 1024; i++)
        if (ht->table[i] != NULL) { 
    printf("The hashtable we just created has an entry != NULL even though we have not added anything!\n Remember to clear your newly allcoated memory, or use calloc()\n");
        ret= FAIL;
    }
    free_hashtable(ht);
    return ret;
}

/**
 * Basic test to add a single key
 */
int test2() {
    int ret = 1;
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) { 
    printf("Failed to create hashtable!\n");
        return FAIL;
    }
    if (set(ht, "Hi bob", 0) != 0) { 
    printf("set() Failed to set a simple key-value pair!\n");
        ret= FAIL;
    }
    free_hashtable(ht);
    return ret;
}

/**
 * Basic set/get pair test
 */
int test3() {
    int ret = PASS;
    double val;
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) { 
    printf("Failed to create hashtable!\n");
        return FAIL;
    }
    if (set(ht, "Hello", 4.5) != 0) { 
    printf("set() Failed to set a simple key-value pair!\n");
        ret= FAIL;
    }
    if (get(ht, "Hello", &val) != 0 || val != 4.5) { 
    printf("get() Failed to get a simple key-value pair we just set, or the value was off!\n");
        ret= FAIL;
    }
    free_hashtable(ht);
    return ret;
}

/**
 * Basic test for get() without key
 */
int test4() {
    int ret = PASS;
    double val;
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) { 
    printf("Failed to create hashtable!\n");
        return FAIL;
    }
    if (get(ht, "No such key", &val) != -1) ret = FAIL;
    free_hashtable(ht);
    return ret;
}
    /**
     * A few sets and gets, without any chaining
     */
int test5() {
    int ret = PASS;
    double val;
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL){ 
    printf("Failed to create hashtable!\n");
        return FAIL;
    }
/* Use same buffer to catch shallow copies */
    char buf[1024];
    /* Add four keys */
    int i;
    for (i = 1; i <= 4; i++) {
        sprintf(buf, "MyKey:%d", i);
        if (set(ht, buf, 45.0 + i) != 0){
         printf("set() Failed to set key: %s\n", buf);   
        ret= FAIL;        
        }        
        if (key_exists(ht, buf) != 1) {
         printf("key_exists() Failed to find key we only just set: %s\n", buf);   
    ret= FAIL;        }   
    }

    /* Remove the middle key */
    strcpy(buf, "MyKey:2");
    if (remove_key(ht, buf) != 0){
         printf("remove_key() returned that it Failed to remove key: %s\n", buf);   
        ret= FAIL;        
        }   
    if (key_exists(ht, buf) != 0) {
         printf("key_exists() found the key we only just removed: %s\n", buf);   
        ret= FAIL;        
        }   

    /* Ensure we can access two of the others */
    strcpy(buf, "MyKey:1");
    if (get(ht, buf, &val) != 0 || val != 46.0) {
         printf("get() could not get: %s, or the value was wrong.\n", buf);   
        ret= FAIL;        
        }   

    strcpy(buf, "MyKey:4");
    if (get(ht, buf, &val) != 0 || val != 49.0) {
         printf("get() could not get: %s, or the value was wrong.\n", buf);   
        ret= FAIL;        
        }   

    free_hashtable(ht);
    return ret;
}
    /**
     * Basic test to see if chaining works
     */
int test6() {
    int ret = PASS;
    double val;
    hashtable_t* ht = create_hashtable(1); //This hashtable is WAYYYY TOO SMALL! This will cause chaining
    if (ht == NULL){ 
    printf("Failed to create hashtable!\n");
        return FAIL;
    }
    /* Use same buffer to catch shallow copies */
    char buf[1024];
    /* Add four keys */
    int i;
    for (i = 1; i <= 4; i++) {
        sprintf(buf, "MyKey:%d", i);
        if (set(ht, buf, 45.0 + i) != 0){
         printf("set() Failed to set key: %s\n", buf);   
        ret= FAIL;        
        }        
        if (key_exists(ht, buf) != 1) {
         printf("key_exists() Failed to find key we only just set: %s\n", buf);   
        ret= FAIL;        
        }   
    }
     /* Remove the middle key */
    strcpy(buf, "MyKey:2");
    if (remove_key(ht, buf) != 0){
         printf("remove_key() returned that it Failed to remove key: %s\n", buf);   
        ret= FAIL;        
        }   
    if (key_exists(ht, buf) != 0) {
         printf("key_exists() found the key we only just removed: %s\n", buf);   
        ret= FAIL;        
        }   

    /* Ensure we can access two of the others */
    strcpy(buf, "MyKey:1");
    if (get(ht, buf, &val) != 0 || val != 46.0) {
         printf("get() could not get: %s, or the value was wrong.\n", buf);   
        ret= FAIL;        
        }   

    strcpy(buf, "MyKey:4");
    if (get(ht, buf, &val) != 0 || val != 49.0) {
         printf("get() could not get: %s, or the value was wrong.\n", buf);   
        ret= FAIL;        
        }   
    

    free_hashtable(ht);
    return ret;
}

/** START INSTUCTOR TESTS **/

/** Parameter testing **/

/**
 * Validate create_hashtable() parameter handling
 */
int test7() {
    /* Invalid parameter to create_hashtable() */
    hashtable_t* ht = create_hashtable(-1);
    if (ht != NULL) return FAIL;
    ht = create_hashtable(0);
    if (ht != NULL) return FAIL;
    return PASS;
}

/**
 * Validate free_hashtable() parameter handling
 */
int test8() {
    /* Shouldn't crash and Valgrind should come up clean here */
    free_hashtable(NULL);
    return PASS;
}

/**
 * Validate remove_key() parameter handling
 */
int test9() {
    hashtable_t* ht = NULL;
    if (remove_key(ht, "Key") != -1) return FAIL;
    if ((ht = create_hashtable(1024)) == NULL) return FAIL;
    if (remove_key(ht, NULL) != -1) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Validate get() parameter handling
 */
int test10() {
    hashtable_t* ht = NULL;
    /* NULL hashtable param */
    double val;
    if (get(ht, "Key", &val) != -1) return FAIL;
    if ((ht = create_hashtable(256)) == NULL) return FAIL;
    if (get(ht, NULL, &val) != -1) return FAIL;
    if (get(ht, "Key", NULL) != -1) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Validate set() parameter handling
 */
int test11() {
    hashtable_t* ht = NULL;
    if (set(ht, "Key", 4.5) != -1) return FAIL;
    if ((ht = create_hashtable(1024)) == NULL) return FAIL;
    if (set(ht, NULL, 4.5) != -1) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Validate key_exists() parameter handling
 */
int test12() {
    hashtable_t* ht = NULL;
    if (key_exists(ht, "Key") != -1) return FAIL;
    if ((ht = create_hashtable(1024)) == NULL) return FAIL;
    if (key_exists(ht, NULL) != -1) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Test two nodes in single chain
 */
int test13() {
    /* Size 1 forces collisions */
    hashtable_t* ht = create_hashtable(1);
    if (ht->table_len != 1) return FAIL;
    if (ht == NULL) return FAIL;
    if (set(ht, "OurKey", 2.4) != 0) return FAIL;
    if (set(ht, "OurOtherKey", -0.5) != 0) return FAIL;
    double val;
    if (get(ht, "OurKey", &val) != 0 || val != 2.4) return FAIL;
    if (get(ht, "OurOtherKey", &val) != 0 || val != -0.5) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Test basic removal
 */
int test14() {
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) return FAIL;
    if (set(ht, "MyKeyForLater", -1040.0) != 0) return FAIL;
    if (remove_key(ht, "MyKeyForLater") != 0) return FAIL;
    if (key_exists(ht, "MyKeyForLater") != 0) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Test very long keys and deep copy
 */
int test15() {
    char buf[1024];
    char buf2[1024];
    memset(buf, 'a', 1023);
    memset(buf2, 'a', 1023);
    buf[1023] = '\0';
    buf2[1023] = '\0';
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) return FAIL;
    if (set(ht, buf, 2.4) != 0) return FAIL;
    double val;
    if (get(ht, buf, &val) != 0 || val != 2.4) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Test deep vs. shallow copy of strings
 */
int test16() {
    char buf[1024];
    char buf2[1024];
    memset(buf, 'a', 1023);
    memset(buf2, 'a', 1023);
    buf[1023] = '\0';
    buf2[1023] = '\0';
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) return FAIL;
    if (set(ht, buf, 2.4) != 0) return FAIL;
    memset(buf, 'b', 1023);
    if (set(ht, buf, -5.0) != 0) return FAIL;
    double val;
    if (get(ht, buf2, &val) != 0 || val != 2.4) return FAIL;
    free_hashtable(ht);
    return PASS;
}

/**
 * Test more complex insertion/deletion sequence
 */
int test17() {
    /* Use same buffer to catch shallow copies */
    char buf[1024];
    hashtable_t* ht = create_hashtable(1024);
    if (ht == NULL) return FAIL;
    strcpy(buf, "NonExistantKey");
    if (key_exists(ht, buf) != 0) return FAIL;
    double val;
    if (get(ht, buf, &val) != -1) return FAIL;
    
    /* Add four keys */
    int i;
    for (i = 1; i <= 4; i++) {
        sprintf(buf, "MyKey:%d", i);
        if (set(ht, buf, 45.0 + i) != 0) return FAIL;
        if (key_exists(ht, buf) != 1) return FAIL;
    }

    /* Remove the middle key */
    strcpy(buf, "MyKey:2");
    if (remove_key(ht, buf) != 0) return FAIL;
    if (key_exists(ht, buf) != 0) return FAIL;

    /* Ensure we can access two of the others */
    strcpy(buf, "MyKey:1");
    if (get(ht, buf, &val) != 0 || val != 46.0) return FAIL;

    strcpy(buf, "MyKey:4");
    if (get(ht, buf, &val) != 0 || val != 49.0) return FAIL;

    free_hashtable(ht);
    return PASS;
}

/**
 * Same as previous test, but force chaining
 */
int test18() {
    /* Use same buffer to catch shallow copies */
    char buf[1024];
    hashtable_t* ht = create_hashtable(1);
    if (ht == NULL) return FAIL;
    strcpy(buf, "NonExistantKey");
    if (key_exists(ht, buf) != 0) return FAIL;
    double val;
    if (get(ht, buf, &val) != -1) return FAIL;
    
    /* Add four keys */
    int i;
    for (i = 1; i <= 4; i++) {
        sprintf(buf, "MyKey:%d", i);
        if (set(ht, buf, 45.0 + i) != 0) return FAIL;
        if (key_exists(ht, buf) != 1) return FAIL;
    }

    /* Remove the middle key */
    strcpy(buf, "MyKey:2");
    if (remove_key(ht, buf) != 0) return FAIL;
    if (key_exists(ht, buf) != 0) return FAIL;

    /* Ensure we can access two of the others */
    strcpy(buf, "MyKey:1");
    if (get(ht, buf, &val) != 0 || val != 46.0) return FAIL;

    strcpy(buf, "MyKey:4");
    if (get(ht, buf, &val) != 0 || val != 49.0) return FAIL;

    free_hashtable(ht);
    return PASS;
}

/**
 * Test that they are storing in the correct slots
 * and aren't playing tricks internally
 */
int test19() {
    hashtable_t* ht = create_hashtable(32);
    if (ht == NULL) return FAIL;
    if (ht->table_len != 32) return FAIL;

    int i;
    for (i = 0; i < ht->table_len; i++)
        if (ht->table[i] != NULL) return FAIL;

    if (set(ht, "MyKey", 10) != 0) return FAIL;
    if (set(ht, "MyOtherKey", 20) != 0) return FAIL;
   
    if (ht->table[hash("MyKey") % ht->table_len] == NULL) return FAIL;
    if (ht->table[hash("MyOtherKey") % ht->table_len] == NULL) return FAIL;
    
    free_hashtable(ht);
    return PASS;
}

/** END INSTURCTOR TESTS **/

int dispatch_test(int (*test)(), int idx) {
    int ret = test();
    if(idx< 7){
        printf("\n********TEST %d: %s********\n", idx, test_discriptions[idx-1]);
    }
    if (ret == PASS) fprintf(stderr, "PASS: test%d\n", idx);
    else fprintf(stderr, "FAIL: test%d\n", idx);
    return ret;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <caseid>\n", argv[0]);
        return 1;
    }

    int (*tests[])() = {
        test1, test2, test3,
        test4, test5, test6,
        test7, test8, test9,
        test10, test11, test12,
        test13, test14, test15,
        test16, test17, test18,
        test19
    };
    const int testcount = sizeof(tests)/sizeof(int(*)());
    int testcase = atoi(argv[1]);
    if (testcase == 0) {
        int idx, ret = 1;
        for (idx = 1; idx <= testcount; idx++)
            ret = dispatch_test(tests[idx - 1], idx) && ret;
        return !ret;
    } else {
        return !dispatch_test(tests[testcase - 1], testcase);
    }
}
