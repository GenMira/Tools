#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <sstream>
#include <list>
#include <random>
#include <utility>
using namespace std;

int randomiser(int min = 1, int max = 1000) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

pair<list<int>, int> puller(int pickup_pull){
    int five_star = 0;
    int prob = 6;
    int pull_times = 1;
    bool defin = false;
    list<int> timelines;

    for(int i = 0;i<pickup_pull;i++){
        if(pull_times>=74){
            prob+=60;
        }

        if(randomiser(1,1000)<=prob){
            //cout << tryn << endl;
            if(randomiser(1,100)<=50 || defin){
                five_star+=1;
                timelines.push_back(pull_times);
                pull_times=1;
                prob=6;
                // timelines.push_back(-1);
                defin = false;
            }
            else if(randomiser(1,10)==1){
                five_star+=1;
                timelines.push_back(pull_times);
                pull_times=1;
                prob=6;
                // timelines.push_back(-2);
            }
            else{
                timelines.push_back(pull_times);
                pull_times=1;
                prob=6;                
                // timelines.push_back(-3);
                defin = true;
            }
        }
        else{
            pull_times+=1;
        }

    }
    return {timelines,five_star};
}

list<int> certain_counter(list<int> check_list){
    int ititial=0;
    int interval = 10;
    int counter =0;
    list<int> resu;
    for(int i;i<10;i++){
        for(int value:check_list){
            if(value>ititial){
                if(value<ititial+interval){
                    counter+=1;
                }
            }
        }
        resu.push_back(counter);
        counter=0;
        ititial+=interval;
    }
    return resu;


}

int main(){
    cout << "How many times do you pull?" << endl;
    int pick_times; cin >> pick_times;

    list<int> results;
    int re_five=0;
    long long sum =0;
    int triala=10000;
    for(int q=0; q<triala;q++){
        auto [pull_results, five_star] = puller(pick_times);
        for (int value : pull_results) {
            results.push_back(value);
        }
        re_five+=five_star;
    }
    for(int value:results){
        //cout << value << ",";
        sum+=value;
    }
  
    cout << endl;
    cout<< "average you can get 5 star : " <<static_cast<double>(sum)/results.size() <<endl;
    cout<< "ratio you can get picked up 5 star : "<<static_cast<double>(re_five)/results.size() <<endl;
    cout<< "the average number ofpicked up 5 star you can get : " <<static_cast<double>(re_five)/triala <<endl;
    cout << endl;
}
