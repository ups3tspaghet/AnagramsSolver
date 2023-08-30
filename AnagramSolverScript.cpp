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
#include <unordered_set>
#include <map>

vector<string> EnglishWords;
vector<string> words;
unordered_set<string> englishWords;
int letterNums;

bool isWord(const string &s);

void find(const string &letters, const string &currStr) {
    if(isWord(currStr)) {
        words.push_back(currStr);

    }
    if (currStr.length() == letterNums && !isWord(currStr)) {
        return;
    }
    for (int i = 0; i < letters.size(); i++) {
        find(letters.substr(0, i) + letters.substr(i + 1), currStr + letters[i]);
    }
}

bool isWord(const string& s){
    if (englishWords.find(s) != englishWords.end()){
      englishWords.erase(englishWords.find(s));
      return true;
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
      englishWords.insert(line);
  }
  
  
  string letters;
  
  string currStr = "";
  cout <<"Six or Seven letters? Enter Number:";
  cin>> letterNums;
  while(letterNums!=6 && letterNums!= 7){
    cout<<"Not Six or Seven Letters. Try Again:";
    cin >> letterNums;
  }
  cout << "Give Me The Letters: ";
  cin >> letters;
  while(letters.length() != letterNums){
    if(letterNums==6){
      cout <<"Invalid Amount Please Type Six Letters: ";
      cin >> letters;
      }
    if(letterNums==7){
      cout <<"Invalid Amount Please Type Seven Letters: ";
      cin >> letters;
      }
  }
  find(letters, currStr);
  std::sort(words.begin(),words.end(), compareLength);
    for (const std::string &s : words) {
        std::cout << s << std::endl;
    }
  
  

  return 0;
}