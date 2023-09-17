#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#define ALP_SIZE 26
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

struct TrieNode
{
	struct TrieNode* children[ALP_SIZE];
	//isEndOfWord true ���� ��������� ������ �����
	bool isEndOfWord;
	int count;
};
// ��������� ����� ���� � ������� ������
TrieNode* getNewNode(void);
//������� ����
void insert(struct TrieNode* root, std::string key);
// ���������� true ���� ���� ���� � ������, ����� false
bool search(struct TrieNode* root, std::string key);
// ���������� true ���� root ����� ����, ����� false
bool isEmpty(TrieNode* root);
//����������� ������� �������� ����� �� ������
TrieNode* remove(TrieNode* root, std::string key, int depth = 0);
//������� ��� �������� ��������� �� ���� ��������
bool isLeafNode(struct TrieNode* root);
//���� ����������
void suggestionsRec(struct TrieNode* root, std::string currPrefix, std::vector<std::string>& t9);
int printAutoSuggesTions(TrieNode* root, const std::string query, std::vector<std::string>& t9);
void dictionary(struct TrieNode* root);
//����� �� �����
void display(struct TrieNode* root, char str[], int level);
void autoPodbor(struct TrieNode* root, std::string text);