// User function template for C++
class TrieNode{
    public:
    TrieNode* children[26] ;
    bool isTerminal;
};
class Trie {
  public:
    TrieNode* root;
    Trie() {
        // implement Trie
        root = new TrieNode();
    }

    void insert(string &word) {
        // insert word into Trie
        TrieNode* node = root;
        for( char ch : word){
            int idx = ch -'a';
            if(node-> children[idx] == NULL){
                node -> children[idx] = new TrieNode();
            }
            node = node -> children[idx];
        }
        node -> isTerminal = true;
    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch -'a';
            if(node -> children[idx] == NULL){
                return false;
            }
            node = node-> children[idx];
        }
        return node -> isTerminal;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
          TrieNode* node = root;
        for(char ch : word){
            int idx = ch -'a';
            if(node -> children[idx] == NULL){
                return false;
            }
            node = node-> children[idx];
        }
        return true;
    }
};
