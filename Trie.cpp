#include "Trie.h"

TrieNode* getNewNode(void)
{
    //Выделяем память на новый узел
    struct TrieNode* pNode = new TrieNode;
    //устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;
    //счетчмк на всякий случай
    pNode->count = 1;
    //инцализируем детей нулевым указателем
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
        //вычисляем индекс в алфавите через смещение относительно первой буквы

        int index = key[i] - 'a';
        //Усли указатель пустой т.е детей с таким прификсом нет
        //создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            node->children[index]->count++;
        node = node->children[index];
    }
    //Помечаем последний узел как лист, т.е конец слова
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
    //Поиск строки
    if (root->isEndOfWord) {
        
        //std::cout << currPrefix << std::endl;
        t9.push_back(currPrefix);
    }
    for(int i = 0; i < ALP_SIZE; i++)
        if (root->children[i])
        {
            //Значение символа дочернего узла
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
        //нет прификса
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
    /*если узел является листовым, узлом он указывает
    * конец строки, поэтому добавляеться нулевой символ
    * и оторобажаеться строка.*/
    if (isLeafNode(root))
    {
        str[level] = '\0';
        std::cout << str << std::endl;
    }
    int i;
    for (i = 0; i < ALP_SIZE; i++)
    {
        /*Если найден дочерний элемент NON NULL добавляем
        *родительский ключь в str и рекурсивно вызываем функцию
        *отоброжения для дочернего узла*/
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

