#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
    int N = 26;
    vector<Trie*> children;
	int endOfWord; // count how many words have this
public:
	Trie(int nChars = 26){
        this->N = nChars;
		endOfWord = 0;
        children.assign(N, NULL);
	}

    /**
     * Insert a new string into Trie
     * 
     * @param key string to be inserted
     * @return the number of that string in Trie(inclusive)
     */
	int insert(string key){
		Trie* cur = this;
		for(char c : key){
			int nextChar = c - 'a';
			if(!cur->children[nextChar]) cur->children[nextChar] = new Trie();
			cur = cur->children[nextChar];
		}
		return ++cur->endOfWord;
	}

    /**
     * Count the number of appearance of {key} in Trie
     *
     * @param key string to be counted
     * @return the number of {key} in Trie
     */
	int count(string key){
		Trie* cur = this;
		for(char c : key){
			int nextChar = c - 'a';
			if(!cur->children[nextChar]) return 0;
			cur = cur->children[nextChar];
		}
		return cur->endOfWord;
	}

    /**
     * Check if {key} in Trie
     *
     * @param key
     * @return True if {key} in Trie, False otherwise
     */
	bool contains(string key){
		return count(key) != 0;
	}

    /**
     * Remove 1 {key} from Trie
     *
     * @param key
     * @return True if {key} in Trie, False otherwise
     */
	bool remove(string key){
		Trie* cur = this;
		for(char c : key){
			int nextChar = c - 'a';
			if(!cur->children[nextChar]) return false;
			cur = cur->children[nextChar];
		}
		if(!cur->endOfWord) return false;

		cur->endOfWord --;
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
