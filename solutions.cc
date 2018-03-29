#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
 public:
  Solution () {}
  ~Solution () {}

	/*
	首先简单介绍一下Anagram（回文构词法）。Anagrams是指由颠倒字母顺序组成的单词,
	比如“dormitory”颠倒字母顺序会变成“dirty room”，“tea”会变成“eat”。

	回文构词法有一个特点：单词里的字母的种类和数目没有改变，只是改变了字母的排列顺序。
	*/
  vector<string> Anagrams(vector<string> &strs) {
    string s;
    vector<string> res;
    map<string, int> anagram;
    for( int i = 0; i < strs.size(); ++i) {
      //int *arr = new int[26];
      int arr[26] = {0};
      for (int j = 0; j < strs[i].size(); ++j) {
        // Assume all char is lowcase
        arr[strs[i].at(j) - 'a'] += 1;
      }
      s = int_array_to_string(arr, 26);
     
      if (anagram.find(s) == anagram.end()) {
        // put into map if new
        anagram[s] = i;
      } else {
        if (anagram[s] >= 0) {
          // put the string into string array with same chars of current string
          res.push_back(strs[anagram[s]]);
          // set -1, only push back once
          anagram[s] = -1;
        }
        // current string is anagram
        res.push_back(strs[i]);
      }
    }
    return res;

  }

  string int_array_to_string(int int_array[], int size_of_array) {
    string str = "";
    for (int i = 0; i < size_of_array; ++i) {
      str += to_string(int_array[i]);
    }
    return str;
  }
};

int main(int argc, char* argv[]) {
  vector<string> strs;
  
  /*
  strs.push_back("lint");
  strs.push_back("intl");
  strs.push_back("inlt");
  strs.push_back("code");
  */
  strs.push_back("ab");
  strs.push_back("ba");
  strs.push_back("cd");
  strs.push_back("dc");
  strs.push_back("e");

  Solution solution;
  vector<string> anagrams = solution.Anagrams(strs);

  cout<<"anagrams = {"<<endl;
  for (int i = 0; i < anagrams.size(); ++i) {
    cout<<anagrams[i]<<endl;
  }
  cout<<"}"<<endl;

  return 0;
}
