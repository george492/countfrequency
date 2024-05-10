#include <algorithm>
#include <iostream>
#include <QString>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class WordFrequancy
{
public:
    string paragraph;
    static unordered_map<string,int> globalMap;
    WordFrequancy(string paragraph);
    unordered_map<string, int> count(string paragraph);
    stack<pair<string, int>> countFrequencySorted(string paragraph);
    //void edit(string wordToEdit, string editedWord, string& paragraph);
    string to_lower(string paragraph);
    // void workFlow(string paragraph);
    void static loadHistoryFromFile(const QString& fileName);

    void static storeHistoryFromFile(const QString& fileName);

    void static clearFile(const QString& fileName);

    string displayFrequancy();

    string displaySortedFrequancy();

    void dispalyHistoryFrequancy();

};
