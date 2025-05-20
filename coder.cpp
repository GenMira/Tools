#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <stdio.h>
# include <fstream>
# include <sstream>
using namespace std;


int string_to_number(string origin){
    int leng = origin.length();
    long long result =0;
    for(int k=0;k<leng;k++){
        int aim = origin[k] - '0';
        result=result*10+aim;
    }
    return result;
}

string int_to_string(int origin){
    return to_string(origin);
}

string int_to_string_encoder(vector<int> line){
    string result_of_sentence;
    for(int v:line){
        char newI = v+31;
        result_of_sentence+= newI;
    }
    result_of_sentence="~"+result_of_sentence+"~";
    return result_of_sentence;
}

vector<int> string_to_number_decoder(string original){
    original = original.substr(1, original.length() - 2);
    vector<int> result;
    for(int f=0;f<original.size();f++){
        int k = original[f]- 31;
        result.push_back(k);
    }
    return result;
}