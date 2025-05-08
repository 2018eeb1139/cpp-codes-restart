class Trie
{
public:
    struct Node
    {
        bool isEndWord;
        Node *children[26];
    };
    Node *getNewNode()
    {
        Node *newNode = new Node();
        newNode->isEndWord = false;
        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    Node *root;
    Trie()
    {
        root = getNewNode();
    }

    void insert(string word)
    {
        Node *crawl = root;
        for (char &c : word)
        {
            int idx = c - 'a';
            if (crawl->children[idx] == NULL)
            {
                crawl->children[idx] = getNewNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->isEndWord = true;
    }

    bool search(string word)
    {
        Node *crawl = root;
        for (char &c : word)
        {
            int idx = c - 'a';

            if (crawl->children[idx] == NULL)
            {
                return false;
            }
            crawl = crawl->children[idx];
        }
        if (crawl != NULL && crawl->isEndWord == true)
        {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        Node *crawl = root;
        int i = 0;
        for (char &c : prefix)
        {
            int idx = c - 'a';
            if (crawl->children[idx] == NULL)
            {
                return false;
            }
            i += 1;
            crawl = crawl->children[idx];
        }
        if (i == prefix.size())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */