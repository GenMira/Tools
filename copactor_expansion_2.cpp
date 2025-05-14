#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <sstream>
using namespace std;


vector<string> splitByComma(const string &sentence) {
    vector<string> parts;
    stringstream ss(sentence);
    string part;

    while (getline(ss, part, ',')) {
        parts.push_back(part);
    }

    return parts;
}

vector<vector<int>> cofacterer(vector<vector<int>> matrics,int splitnum){
    matrics.erase(matrics.begin());
    for (int k=0;k<matrics.size();k++){
        matrics[k].erase(matrics[k].begin()+splitnum);
    } 
    return matrics;
}

int expansionner(vector<vector<int>> matrics){
  if (matrics.size()==2){
    return matrics[0][0]*matrics[1][1]-matrics[0][1]*matrics[1][0];
  }
  else{
    int expresult =0;
    for (int k = 0; k < matrics.size(); k++) {
      int eq_zero = matrics[0][k];
      if(eq_zero!=0){
        int sign = (k % 2 == 0) ? 1 : -1;
        expresult += sign * eq_zero * expansionner(cofacterer(matrics, k));
      }
    }
    return expresult;
  }
}


void cofactor_expansion(){
    cout << "what is the size of matrics?" << endl;
    int size_of_matrics; cin >> size_of_matrics;
    vector<vector<int>> matrics(size_of_matrics,vector<int>(size_of_matrics,-1));
    cout << "input the elements of the matrics" << endl;

    for (int i = 0; i < size_of_matrics; ++i) {
        string line; cin >> line;
        vector<string> result_of_split = splitByComma(line);
        for (int j = 0; j < size_of_matrics; ++j) {
            int num = stoi(result_of_split[j]);
            matrics[i][j] = num;
        }
    }


    cout << "-------" <<endl;

    cout << expansionner(matrics)<<endl;

}



int main() {
    cofactor_expansion();
}