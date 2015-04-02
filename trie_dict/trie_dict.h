// Filename: trie_dict.h
// Author: liubj77 - liubj77@gmail.com

#ifndef  _TRIE_DICT_H_
#define  _TRIE_DICT_H_

#include <string>
#include <list>

const size_t CHAR_SIZE = 26;
const int    MAX_WORD_LEN = 32;

typedef struct TrieNode {
    char key;
    bool is_word;       // indicate the node is the tail of the word
    int word_num;       // indicate the words number that has this prefix
    TrieNode *next[CHAR_SIZE];  // link
} TrieNode;

TrieNode * insert_word_to_dict(TrieNode *root, char *c);

int search_word_with_prefix(TrieNode *root, const char *prefix, 
                            std::list<std::string> & word_list);

int build_trie_dict_from_file(TrieNode *root, std::string file);


#endif //TRIE_DICT_H_

