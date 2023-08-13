#include <bits/stdc++.h>

using namespace std;

struct defense{
  int shield;
  int armorPercent;
};

int main() {
  long double H;
  int h1;
  int D, E;
  cin >> H >> D >> E;
  cout << fixed;
  cout << setprecision(2);
  int dpsDFA[1001] = {0}, dps[1001] = {0};
  int maxSecond = 0;
  vector <defense> defenseModes;
  for(int i = 0; i < D; i++){
    defense tmp;
    cin >> tmp.armorPercent >> tmp.shield;
    defenseModes.push_back(tmp);
  }
  for(int i = 0; i < E; i++){
    int length, dps, startSecond;
    cin >> startSecond >> length >> dps;
    dpsDFA[startSecond] += dps;
    dpsDFA[startSecond + length] -= dps;
    if(startSecond + length - 1 > maxSecond)maxSecond = startSecond + length - 1;
  }
  //test cout dps 
  //convert dps to actual dps 
  for(int i = 0; i <= maxSecond; i++){
    dps[i] = (i == 0 ? 0 : dps[i - 1]) + dpsDFA[i];
    //cout << "actual damage: " << dps[i] << ' ';
    //cout << "damage done in the " << i << "th second: " << dps[i] << endl;
    //go through all the options
    double dmgDone = (double)dps[i];
    for(int j = 0; j < D; j++){
      if(dps[i] <= defenseModes[j].shield){
        //cout << "LESS THAN SHIELD ";
        dmgDone = 0.00;
        break;
      }else{
        double curDmg = 0.00;
        curDmg = dps[i] - defenseModes[j].shield;
        curDmg -= ((double)curDmg)*((double)defenseModes[j].armorPercent)/100.0;
        dmgDone = min(dmgDone, curDmg);
      }
    }
    //cout << dmgDone << " damage done in second " << i << endl;
    if(dmgDone <= dps[i])H -= dmgDone;
  }
  if(H <= 0.00){
      cout << "DO A BARREL ROLL!" << endl;
  }else cout << H << endl;
  return 0;
}