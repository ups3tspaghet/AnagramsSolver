#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::atan;
using std::pow;
using namespace std;
#include <string>
using std:: string;
#include <vector>
using std:: vector;
using namespace std;
#include <fstream>
#include <algorithm>

vector<string> EnglishWords;
vector<string> words;

bool isWord(const string &s);

void find(const string &letters, const string &currStr) {
    if(isWord(currStr)) {
        words.push_back(currStr);
    }
    if (currStr.length() == 6 && !isWord(currStr)) {
        return;
    }
    for (int i = 0; i < letters.size(); i++) {
        find(letters.substr(0, i) + letters.substr(i + 1), currStr + letters[i]);
    }
}
bool isWord(const string &s) {
    for (const string &w : EnglishWords) {
        if (s == w) {
            return true;
        }
    }
    return false;
}
bool compareLength (const string &a, const string &b){
   return a.length() > b.length();
}
 

int main() {
  std::ifstream inputFile("letters7.txt");
  if (!inputFile.is_open()) {
        std::cerr << "Could not open the file." << endl;
        return 1;
  }
  string line;
  while (std::getline(inputFile, line)) {
      EnglishWords.push_back(line);
  }
  string letters;
  string currStr = "";
  cout << "Give Me The Six Letters: ";
  cin >> letters;
  while(letters.length() != 6){
      cout <<"Invalid Amount Please Type Six Letters: ";
      cin >> letters;
  }
  find(letters, currStr);
  std::sort(words.begin(),words.end(), compareLength);
    for (const std::string &s : words) {
        std::cout << s << std::endl;
    }

  inputFile.close();

  return 0;
}