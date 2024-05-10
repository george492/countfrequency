#include "WordFrequancy.h"
#include "displaymenu.h"
#include "finalmenu.h"
#include "autocorrect.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <QFile>
#include <QTextStream>
using namespace std;
string WordFrequancy::globalString ;

WordFrequancy::WordFrequancy(string paragraph)
{
    this->paragraph = paragraph;
}
bool sortByFrequencyAndSize(const pair<string, int> a, const pair<string, int> b)
{
    if (a.second != b.second) {
        return a.second < b.second; // Sort by frequency in descending order
    }
    // If frequencies are equal, compare the word sizes
    if (a.first.size() != b.first.size())
        return a.first.size() < b.first.size();
    // If frequencies are equal, compare the words lexicographically
    return a.first > b.first;
}


unordered_map<string, int> WordFrequancy::count(string paragraph)
{
    string singleWord;
    unordered_map<string, int> wordWithFrequancy;
    for (int i = 0; i < paragraph.size(); i++) {
        if (paragraph[i] == ' ' || paragraph[i] == ',') {
            while (paragraph[i] == ' ' || paragraph[i] == ',')
                i++;
            singleWord = to_lower(singleWord);

            auto it = wordWithFrequancy.find(singleWord);
            if (it != wordWithFrequancy.end()) {
                wordWithFrequancy[singleWord]++;
            } else {
                wordWithFrequancy.insert({singleWord, 1});
            }
            singleWord = "";
        }
        singleWord.push_back(tolower(paragraph[i]));
    }

    if (!singleWord.empty() && singleWord[0] != '\0') {
        singleWord = to_lower(singleWord);
        bool found = false;
        singleWord = to_lower(singleWord);

        auto it = wordWithFrequancy.find(singleWord);
        if (it != wordWithFrequancy.end()) {
            wordWithFrequancy[singleWord]++;
        } else {
            wordWithFrequancy.insert({singleWord, 1});
        }
        singleWord = "";
    }
    return wordWithFrequancy;
}
string WordFrequancy::to_lower(string s)
{
    for (int i = 0; i < s.length(); ++i) {
        s[i] = tolower(s[i]);
    }
    return s;
}
stack<pair<string, int>> WordFrequancy::countFrequencySorted(string paragraph)
{
    unordered_map<string, int> freqMap = count(paragraph);

    // Convert the frequency map to a vector of pairs
    vector<pair<string, int>> wordFreqs(freqMap.begin(), freqMap.end());

    // Sort the vector of pairs by frequency in descending order
    sort(wordFreqs.begin(), wordFreqs.end(), sortByFrequencyAndSize);

    // Push sorted pairs into a stack
    stack<pair<string, int>> sortedWords;
    vector<pair<string, int>>::iterator it = wordFreqs.begin();
    while (it != wordFreqs.end()) {
        sortedWords.push({it->first, it->second});
        it++;
    }
    return sortedWords;
}

//display Word's frequancy

string WordFrequancy::displayFrequancy()
{
    unordered_map<string, int> displayMap = count(paragraph);
    string unorderedString;

    unorderedString = "Word\t\t\tFrequancy\n\n";
    for (auto t = displayMap.begin(); t != displayMap.end(); t++) {
        unorderedString += t->first + "\n\t\t\t       " + to_string(t->second)
                           + "\n----------------------------------------------------\n\n";
    }
    return unorderedString;
}

//display sorted word's frequancy

string WordFrequancy::displaySortedFrequancy()
{
    stack<pair<string, int>> displaySortedStack = countFrequencySorted(paragraph);
    int size = displaySortedStack.size();
    pair<string, int> data;
    string sortedString;

    sortedString = "    Word\t\t\tFrequancy\n\n";
    for (int i = 1; i <= size; i++) {
        data = displaySortedStack.top();
        displaySortedStack.pop();

        sortedString += "(" + to_string(i) + ")_" + data.first + "\n\t\t\t       "
                        + to_string(data.second)
                        + "\n----------------------------------------------------\n\n";
    }
    return sortedString;
}

//display common words

void WordFrequancy::displayCommonWords()
{
    autocorrect readObject;
    set<string> readText = readObject.load("C:\\Users\alima\\Documents\\countfrequency\\CommonWords.txt");
    stack<pair<string, int>> SortedStack = countFrequencySorted(paragraph);
    pair<string, int> data;
    int size = SortedStack.size();
    set<string> newWords;
    bool founded = false;

    for(int i = 0;i < size;i++){
        data = SortedStack.top();
        SortedStack.pop();

        if(data.second < 15){
            break;
        }

        else if(data.second >= 15){
            if(!readText.empty()){

                for(auto it = readText.begin();it != readText.end();it++){

                    if(data.first == it->data()){
                    founded = true;
                    break;
                    }
                }
            }
            if(!founded){
                newWords.insert(data.first);
            }
        }
        founded = false;
    }

    QFile file("C:\\Users\alima\\Documents\\countfrequency\\CommonWords.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
    }

    QTextStream writingFile(&file);
    for(auto it = newWords.begin();it != newWords.end();it++){
        writingFile<<it->data()<<" ";
    }

    file.close();

}
