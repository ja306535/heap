// Pre-condition: h points to a valid hash table that IS NOT full.
// Post-condition: word will be inserted into the table h.
void insertTable(struct htable *h, char word[]) {
    int hashval;
    hashval = hashvalue(word);
    int i = 0;
    int index;
    
    do {
        index = (hashval + i*i) % TABLE_SIZE;
        if (strcmp(h->entries[index], "") == 0) {
            strcpy(h->entries[index], word);
            return;
        }
        i++;
    } while (i < TABLE_SIZE);
    }
    
    // Pre-condition: h points to a valid hash table.
    // Post-condition: 1 will be returned iff word is stored in the table pointed to
    // by h. Otherwise, 0 is returned.
    int searchTable(struct htable *h, char word[]) {
    int hashval;
    hashval = hashvalue(word);
    int i = 0;
    int index;
    // See what comes first, the word or a blank spot.
    do {
        index = (hashval + i*i) % TABLE_SIZE;
        if (strcmp(h->entries[index], "") == 0)
            return 0;
        if (strcmp(h->entries[index], word) == 0)
            return 1;
        i++;
    } while (i < TABLE_SIZE);
    // It wasn't.
    return 0;
    }
    
    // Pre-condition: h points to a valid hash table.
    // Post-condition: deletes word from the table pointed to by h, if word is
    // stored here. If not, no change is made to the table pointed
    // to by h.
    void deleteTable(struct htable *h, char word[]) {
    int hashval;
    hashval = hashvalue(word);
    int i = 0;
    int index;
    // See what comes first, the word or a blank spot.
    do {
        index = (hashval + i*i) % TABLE_SIZE;
        if (strcmp(h->entries[index], "") == 0)
            return;
        if (strcmp(h->entries[index], word) == 0) {
            strcpy(h->entries[index],"");
            return;
        }
        i++;
    } while (i < TABLE_SIZE);
    // If we get here, the word wasn't in the table, so nothing is done.
    }
    