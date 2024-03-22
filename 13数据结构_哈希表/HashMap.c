// HashMap.c
#include "HashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define DEFAULT_CAPACITY	8
#define LOAD_FACTOR      0.75

// �����յĹ�ϣ��
HashMap* hashmap_create(void) {
    HashMap* map = malloc(sizeof(HashMap));
    if (!map) {
        printf("Error: malloc failed,\n");
        exit(0);
    }
    else {
        map->table = calloc(DEFAULT_CAPACITY, sizeof(Entry*));
        if (!map->table) {
            printf("Error: calloc failed.\n");
            free(map);
            exit(1);
        }
    }
    map->size = 0;
    map->capacity = DEFAULT_CAPACITY;
    map->hashseed = time(NULL);
    return map;
}

// ��ϣ��ı���
void hashmap_destroy(HashMap* map) {
    // 1. �ͷ����н��
    for (int i = 0; i < map->capacity; i++) {
        Entry* curr = map->table[i];
        while (curr) {
            Entry* next = curr->next;
            free(curr);
            curr = next;
        }
    }
    // 2. �ͷ�table
    free(map->table);
    // 3. �ͷ�map
    free(map);
}

// key: �ؼ��ֵĵ�ַ
// len: �ؼ��ֵ��ֽڳ���
// seed: ��ϣ���ӣ����⹥��
uint32_t hash(const void* key, int len, uint32_t seed) {
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    uint32_t h = seed ^ len;
    const unsigned char* data = (const unsigned char*)key;

    while (len >= 4) {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len)
    {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

// ���key�����ڣ������(key, val)
// ���key���ڣ�����key������ֵ��������ԭ��������ֵ��
V hashmap_put(HashMap* map, K key, V val) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // map->table[idx]: key���ڵ�����
    // ��������
    Entry* curr = map->table[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // ����curr������ֵ
            V oldvalue = curr->val;
            curr->val = val;
            return oldvalue;
        }
        curr = curr->next;
    }   // curr == NULL
    // ������key, ��Ӽ�ֵ��(key, val)
    Entry* entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->val = val;
    // ͷ�巨
    entry->next = map->table[idx];
    map->table[idx] = entry;
    // ���¹�ϣ��
    map->size++;

    return NULL;
}

V hashmap_get(HashMap* map, K key) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // map->table[idx]: key���ڵ�����
    Entry* curr = map->table[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->val;
        }
        curr = curr->next;
    } // curr == NULL
    return NULL;
}

void hashmap_delete(HashMap* map, K key) {
    int idx = hash(key, strlen(key), map->hashseed) % map->capacity;
    // map->table[idx]: key���ڵ�����
    Entry* prev = NULL;
    Entry* curr = map->table[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // TODO: ɾ��curr���
            if (prev == NULL) {
                map->table[idx] = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            map->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    } // curr == NULL
}

void hashmap_expand_capacity(HashMap* map) {
    //����
    int new_capacity = 2 * map->capacity;
    Entry** new_table = malloc(new_capacity * sizeof(Entry*));
    if (!new_table) {
        printf("Error: malloc failed.\n");
        exit(1);
    }
    //����ԭtable�е�Ԫ�ص���������ڴ�ռ�
    
    for (int i = 0; i < map->capacity; i++) {
        //������table�Ľ����table[i]�����еĵ�һ�����
        Entry* current = map->table[i];
        while (current) {
            Entry* next = current->next;
            //��ȡԭtable����ϣ���ֵ
            int idx = hash(current->key, sizeof(Entry), map->hashseed) % map->hashseed;
            current->next = new_table[idx];
            new_table[idx] = current;
            current = next;
        }

    }

    //�ͷ�ԭ�ڴ�
    free(map->table);
    //����map��Ϣ
    
    map->table = new_table;
    map->capacity = new_capacity;

}