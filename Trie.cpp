#include "Trie.h"

TrieNode* getNewNode(void)
{
    //�������� ������ �� ����� ����
    struct TrieNode* pNode = new TrieNode;
    //������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;
    //������� �� ������ ������
    pNode->count = 1;
    //������������ ����� ������� ����������
    for (int i = 0; i < ALP_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void insert(TrieNode* root, std::string key)
{
    TrieNode* node = root;
    node->count = 0;
    for (int i = 0; i < key.length(); i++)
    {
        //��������� ������ � �������� ����� �������� ������������ ������ �����

        int index = key[i] - 'a';
        //���� ��������� ������ �.� ����� � ����� ��������� ���
        //������� ����� ����
        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            node->children[index]->count++;
        node = node->children[index];
    }
    //�������� ��������� ���� ��� ����, �.� ����� �����
    node->isEndOfWord = true;
}

bool isEmpty(TrieNode* root)
{
    for(int i = 0; i < ALP_SIZE; i++)
        if(root->children[i])
            return false;
    return true;
}

bool isLeafNode(TrieNode* root)
{
    return root->isEndOfWord != false;
}

void suggestionsRec(TrieNode* root, std::string currPrefix, std::vector<std::string>& t9)
{
    //����� ������
    if (root->isEndOfWord) {
        
        //std::cout << currPrefix << std::endl;
        t9.push_back(currPrefix);
    }
    for(int i = 0; i < ALP_SIZE; i++)
        if (root->children[i])
        {
            //�������� ������� ��������� ����
            char child = 'a' + i;
            suggestionsRec(root->children[i], currPrefix + child, t9);
        }
}

int printAutoSuggesTions(TrieNode* root, const std::string query, std::vector<std::string>& t9)
{
    struct TrieNode* pCrawl = root;
    for (int i = 0; i < query.length(); i++)
    {
        int ind = query[i] - 'a';
        //��� ��������
        if (!pCrawl->children[ind])
            return 0;
        pCrawl = pCrawl->children[ind];
    }

    if (isEmpty(pCrawl)) {
        std::cout << query << std::endl;
        return -1;
    }
    int j = 0;
    suggestionsRec(pCrawl, query, t9);
    return 1;
}

void dictionary(TrieNode* root)
{
    std::string keys[] = { "hello", "help", "helps", "hi", "what" };
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
    {
        insert(root, keys[i]);
    }
}

void display(TrieNode* root, char str[], int level)
{
    /*���� ���� �������� ��������, ����� �� ���������
    * ����� ������, ������� ������������ ������� ������
    * � �������������� ������.*/
    if (isLeafNode(root))
    {
        str[level] = '\0';
        std::cout << str << std::endl;
    }
    int i;
    for (i = 0; i < ALP_SIZE; i++)
    {
        /*���� ������ �������� ������� NON NULL ���������
        *������������ ����� � str � ���������� �������� �������
        *����������� ��� ��������� ����*/
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

void autoPodbor(struct TrieNode* root, std::string text)
{
    std::vector<std::string>t9;
    printAutoSuggesTions(root, text, t9);
    if (t9.empty())
    {
        char n;
        std::cout << "====the text is not in the dictionary. Write the text into a dictionary?====" << std::endl;
        std::cout << "press y/n (y - yes. n - no)";
        std::cin >> n;
        if (n == 'y') {
            std::cout << "=========See the text==========" << std::endl;
            std::cin >> text;
            insert(root, text);
        }
        else {
            std::cout << text << std::endl;
            return;
        }
    }
    else 
    {
        int j = 0;
        int q = 0;
        std::cout << "=============== Select a text input option ================" << std::endl;
        for (int i = 0; i < t9.size(); i++)
        {
            std::cout << ++j << " -> " << t9[i] << std::endl;
        }
        std::cout << "=======================================" << std::endl;
        std::cin >> q;
        std::cout << "=======================================" << std::endl;
        for (int i = 0; i < t9.size(); i++)
        {
            if (i == q - 1) {
                std::cout << t9[i] << std::endl;
                break;
            }
        }
    }
}

