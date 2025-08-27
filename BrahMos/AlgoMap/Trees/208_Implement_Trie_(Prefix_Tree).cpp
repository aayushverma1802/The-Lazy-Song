class Trie {
public:
    struct trieNode {
        bool isEndofWord;
        trieNode* children[26];

        trieNode() {
            isEndofWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    trieNode* root;

    Trie() {
        root = new trieNode();
    }

    void insert(string word) {
        trieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (crawler->children[idx] == nullptr) {
                crawler->children[idx] = new trieNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndofWord = true;
    }

    bool search(string word) {
        trieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return crawler->isEndofWord;
    }

    bool startsWith(string prefix) {
        trieNode* crawler = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return true;
    }
};