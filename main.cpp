#include "Trie.h"

int main()
{
	bool start = true;
	struct TrieNode* root = getNewNode();
	dictionary(root);
	while (start)
	{
		std::string text;
		int a = 0;
		std::cout << "To enter text press 1 to exit 0" << std::endl;
		std::cout << "======================================" << std::endl;
		std::cin >> a;
		if (a == 0)
			start = false;
		else {
			std::cout << "================= See the text ===================" << std::endl;
			std::cin >> text;
			autoPodbor(root, text);
			std::cout << std::endl << "======================================" << std::endl;			
		}
	}

}