#include "WordFrequancy.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
WordFrequancy::WordFrequancy(string paragraph) {
    this->paragraph = paragraph;
}
// void WordFrequancy::workFlow(string paragraph) {
//     int choice;
//     while (1) {
//         cout << "Enter 1 to exit:\nEnter 2 to edit:\nEnter 3 to display frequency sorted from greater to smaller: ";
//         cin >> choice;
//         if (choice == 1)
//             break;
//         if (choice == 2) {
//             string wordToEdit, editedWord;
//             cout << "Word you want to edit: ";
//             cin >> wordToEdit;
//             cout << "Edited word: ";

//             cin >> editedWord;
//             edit(wordToEdit, editedWord, paragraph);

//         }
//         if (choice == 3) {


//             stack <pair<string, int>> sortedStack;
//             sortedStack = countFrequencySorted(paragraph);

//             while (!sortedStack.empty()) {
//                 cout << sortedStack.top().first << " : " << sortedStack.top().second << endl;
//                 sortedStack.pop();
//             }
//         }
//     }

//     cout << "==============================================================" << endl;
//     cout << "paragraph : " << paragraph << endl;
//     cout << "==============================================================" << endl;
//     unordered_map<string, int > wordWithFrequancy;
//     wordWithFrequancy = count(paragraph);
//     unordered_map<string, int >::iterator it = wordWithFrequancy.begin();
//     while (it != wordWithFrequancy.end()) {
//         cout << it->first << " : " << it->second << endl;
//         it++;
//     }
//     cout << "==============================================================" << endl;

//     // Printing word frequencies
// }
bool sortByFrequencyAndSize(const pair<string, int> a, const pair<string, int> b) {
    if (a.second != b.second) {
        return a.second < b.second; // Sort by frequency in descending order
    }
    // If frequencies are equal, compare the word sizes
    if (a.first.size() != b.first.size())
        return a.first.size() < b.first.size();
    // If frequencies are equal, compare the words lexicographically
    return a.first > b.first;
}


// void WordFrequancy::edit(string wordToEdit, string editedWord, string& paragraph) {
//     wordToEdit = to_lower(wordToEdit);
//     editedWord = to_lower(editedWord);
//     unordered_map<string, int> wordWithFrequancy;

//     size_t pos = paragraph.find(wordToEdit); // Find the position of the original word in the sentence
//     if (pos != string::npos) { // If the word is found in the sentence
//         paragraph.replace(pos, wordToEdit.length(), editedWord); // Replace the original word with the edited word

//     }
//     else {
//         cout << "Word not found in the sentence.\n";
//     }
// }


unordered_map<string, int> WordFrequancy::count(string paragraph) {


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
            }
            else {
                wordWithFrequancy.insert({ singleWord,1 });
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
        }
        else {
            wordWithFrequancy.insert({ singleWord,1 });
        }
        singleWord = "";
    }
    return wordWithFrequancy;

}
string  WordFrequancy::to_lower(string s) {
    for (int i = 0; i < s.length(); ++i) {
        s[i] = tolower(s[i]);
    }
    return s;
}
stack<pair<string, int>> WordFrequancy::countFrequencySorted(string paragraph) {
    unordered_map<string, int> freqMap = count(paragraph);

    // Convert the frequency map to a vector of pairs
    vector<pair<string, int>> wordFreqs(freqMap.begin(), freqMap.end());

    // Sort the vector of pairs by frequency in descending order
    sort(wordFreqs.begin(), wordFreqs.end(), sortByFrequencyAndSize);

    // Push sorted pairs into a stack
    stack<pair<string, int>> sortedWords;
    vector<pair<string, int>>::iterator it = wordFreqs.begin();
    while (it != wordFreqs.end())
    {
        sortedWords.push({ it->first,it->second });
        it++;
    }
    return sortedWords;
}
