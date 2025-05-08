class WordDictionary
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
    WordDictionary()
    {
        root = getNewNode();
    }

    void addWord(string word)
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

    bool searchUtil(Node *root, string word)
    {
        Node *crawl = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (crawl->children[j] != NULL)
                    {
                        if (searchUtil(crawl->children[j], word.substr(i + 1)) == true)
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
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

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};