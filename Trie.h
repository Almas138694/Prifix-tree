#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#define ALP_SIZE 26
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct TrieNode
{
	struct TrieNode* children[ALP_SIZE];
	//isEndOfWord true Усли являеться концом слова
	bool isEndOfWord;
	int count;
};
// Возвращет новый узел с пустыми детьми
TrieNode* getNewNode(void);
//Вставка узла
void insert(struct TrieNode* root, std::string key);
// Возвращает true если ключ есть в дереве, иначе false
bool search(struct TrieNode* root, std::string key);
// Возвращает true если root имеет лист, иначе false
bool isEmpty(TrieNode* root);
//Рекурсивная функция удаления ключа из дерева
TrieNode* remove(TrieNode* root, std::string key, int depth = 0);
//Функция для проверки являеться ли узел листовым
bool isLeafNode(struct TrieNode* root);
//Авто заполнения
void suggestionsRec(struct TrieNode* root, std::string currPrefix, std::vector<std::string>& t9);
int printAutoSuggesTions(TrieNode* root, const std::string query, std::vector<std::string>& t9);
void dictionary(struct TrieNode* root);
//вывод на экран
void display(struct TrieNode* root, char str[], int level);
void autoPodbor(struct TrieNode* root, std::string text);