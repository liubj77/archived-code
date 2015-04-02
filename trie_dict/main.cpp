// Filename: main.cpp
// Author: liubj77 - liubj77@gmail.com

#include <iostream>
#include "trie_dict.h"

int main()
{
    // create a root node which contains no data
    TrieNode * root = new TrieNode;

    build_trie_dict_from_file(root, "test_dict");

    int ret = -1;
    std::list<std::string> word_list;
    ret = search_word_with_prefix(root, "abj", word_list);

    std::cout << word_list.size() << std::endl;

    for (std::list<std::string>::const_iterator iter = word_list.begin();
            iter != word_list.end(); ++iter) {
        std::cout << *iter << std::endl;
    }

    return 0;
}
