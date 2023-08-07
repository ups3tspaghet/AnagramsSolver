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



string Solve(string let){
  return let + "a";
}


int main() {
  string letters;
  cout << "Give Me The Six Letters: ";
  cin >> letters;
  while(letters.length() != 6){
      cout <<"Invalid Amount Please Type Six Letters: ";
      cin >> letters;
  }
  cout << Solve(letters)<<endl;
  cout << letters;
}