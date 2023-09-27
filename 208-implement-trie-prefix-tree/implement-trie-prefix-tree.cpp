class TrieNode{
public:
    char data;
    TrieNode**children;
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];

        for(int i=0; i<26; i++) children[i]=NULL;
        isTerminal =false;
    }
};


class Trie {
    TrieNode*root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode*root, string s){
        if(s.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = s[0]-'a';
        TrieNode*child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(s[0]);
            root->children[index]=child;
        }

        insertWord(child, s.substr(1));
    }

    void insert(string word) {
        string s = word;
        insertWord(root,s);
    }
    
    bool search(TrieNode*root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        if(root->children[index] != NULL){
            return search(root->children[index], word.substr(1));
        }
        else return false;
    }

    bool search(string word) {
        string s = word;
        return search(root, s);
    }

    bool startsWith(TrieNode*root, string prefix){
        if(prefix.length()==0){
            return true;
        }

        int index = prefix[0]-'a';
        if(root->children[index] != NULL){
            return startsWith(root->children[index], prefix.substr(1));
        }
        else return false;
    }
    
    bool startsWith(string prefix) {
       string s = prefix;
       return startsWith(root, s); 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */