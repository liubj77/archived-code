// Filename: trie_dict.cpp
// Author: liubj77 - liubj77@gmail.com

#include <string.h>
#include <fstream>
#include "trie_dict.h"

TrieNode *insert_word_to_dict(TrieNode *root, char *word)
{
    if (word == NULL || *word == '\0') {
        return root;
    }
    /* root node not contain any characters */
    TrieNode *p = root;
    while (*word != '\0') {
        int idx = *word - 'a';
        if (p->next[idx] == NULL) {
            TrieNode *tmp = new TrieNode;
            tmp->key = *word;
            tmp->word_num = 0;
            tmp->is_word = false;
            for (int i = 0; i < CHAR_SIZE; ++i) {
                tmp->next[i] = NULL;
            }
            p->next[idx] = tmp;
        }

        p = p->next[idx];
        ++p->word_num; // inc word_num
        ++word;
    }

    p->is_word = true;

    return root;
}

void search_word_dfs(TrieNode *node, char *temp_word, int temp_len,
                    std::list<std::string> &word_list)
{
    for (int i = 0; i < CHAR_SIZE; ++i) {
        if (node->next[i] != NULL) {
            temp_word[temp_len ++] = node->next[i]->key;
            temp_word[temp_len] = '\0';
            if (node->next[i]->is_word) {
                word_list.push_back(temp_word);
            }

            search_word_dfs(node->next[i], temp_word, temp_len, word_list);

            // after search this node, should rollback the sibling node
            temp_word[--temp_len] = '\0';
        }
    }
}

int search_word_with_prefix(TrieNode *root, const char *prefix, std::list<std::string> & word_list)
{
    if (prefix == NULL || *prefix == '\0') {
        return -1;    
    }

    int idx, ret;
    TrieNode *tmp = root;

    for (int i = 0; prefix[i] != '\0'; ++i) {
        idx = prefix[i] - 'a';
        tmp = tmp->next[idx];
        if (tmp == NULL) { // has no such prefix
            return -1;
        }
    }

    // if has such prefix and the prefix is a whole word
    if (tmp->is_word) {
        word_list.push_back(std::string(prefix));
    }

    // after skip prefix, all child leef node is satisfied
    // next use deep-first-search to find all word

    char temp_word[MAX_WORD_LEN]; // used to store the found word
    strcpy(temp_word, prefix);    // first add the prefix header
    int temp_len = strlen(prefix);

    search_word_dfs(tmp, temp_word, temp_len, word_list);

    return 0;
}

int build_trie_dict_from_file(TrieNode *root, std::string file)
{
    char word[MAX_WORD_LEN];
    std::ifstream if_data;

    if_data.open(file.c_str(), std::ios::in);
    if (if_data.is_open()) {
        while (!if_data.eof()) {
            if_data.getline(word, MAX_WORD_LEN);
            insert_word_to_dict(root, word);
        } 

        if_data.close();
    } else {
        fprintf(stderr, "open the file fail\n");
        return -1;
    }

    return 0;
}
