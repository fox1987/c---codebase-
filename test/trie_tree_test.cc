#include <iostream>
#include "../base/logging.h"
#include "../base/trie_tree.h"
using namespace std;
using namespace base;

int main(int argc, char** argv) {
  LOG::s_logging_level = 3;
  base::TrieTree trie;
  trie.Insert("HelloWorld");
  trie.Insert("HelloChina");
  trie.Insert("Helloyou");
  trie.Insert("Hello World");
  trie.Insert("Hello China");
  trie.Insert("Hello you");
  VLOG(3) << "Hello : " << trie.Search("Hello");
  VLOG(3) << "HelloWorld : " << trie.Search("HelloWorld");
  VLOG(3) << "HelloWorldToyou : " << trie.Search("HelloWorldToyou");
  VLOG(3) << "Hello World: " << trie.Search("Hello World");
  VLOG(3) << "Hello World To you : " << trie.Search("Hello World To you");
  return 0;
}
