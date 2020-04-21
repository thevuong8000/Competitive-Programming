#include <bits/stdc++.h>
using namespace std;

class Trie{
public:
	Trie* children[26];
	int endOfWord; // count how many words have this

	Trie(){
		endOfWord = 0;
		for(int i = 0; i < 26; i++) children[i] = NULL;
	}


	void insert(string key){
		Trie* cur = this;
		for(char c : key){
			int nextChar = c - 'a';
			if(cur -> children[nextChar] == nullptr) cur -> children[nextChar] = new Trie();
			cur = cur -> children[nextChar];
		}
		cur -> endOfWord++;
	}

	int count(string key){
		Trie* cur = this;
		for(char c : key){
			int nextChar = c - 'a';
			if(cur -> children[nextChar] == nullptr) return 0;
			cur = cur -> children[nextChar];
		}
		return cur -> endOfWord;
	}

	bool contains(string key){
		return count(key) != 0;
	}

	bool remove(string key){
		Trie* cur = this;
		for(char c : key){
			int nextChar = c - 'a';
			if(cur -> children[nextChar] == nullptr) return false;
			cur = cur -> children[nextChar];
		}
		if(!cur -> endOfWord) return false;

		cur -> endOfWord --;
		return true;
	}

};

int main(){
	string key[6] = {"a", "ab", "abc", "aba", "abab", "aba"};
	Trie myTrie;
	for(int i = 0; i < 6; i++) myTrie.insert(key[i]);
	(myTrie.contains("ab")) ? cout << "YES\n" : cout << "NO\n"; // print YES
	(myTrie.contains("abcd")) ? cout << "YES\n" : cout << "NO\n"; // print NO
	cout << myTrie.count("aba") << endl; // print 2
	myTrie.remove("aba");
	cout << myTrie.count("aba") << endl; // print 1
	return 0;
}