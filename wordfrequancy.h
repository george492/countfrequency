#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
class WordFrequancy
{
public :
    string paragraph;
    WordFrequancy(string paragraph);
    unordered_map<string, int> count(string paragraph);
    stack<pair<string, int>> countFrequencySorted(string paragraph);
    //void edit(string wordToEdit, string editedWord, string& paragraph);
    string to_lower(string paragraph);
   // void workFlow(string paragraph);
};
