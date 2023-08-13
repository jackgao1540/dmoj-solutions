#include <iostream>
#include <vector>

using namespace std;

/*
  Sample Input:
  8 5 15
  1 5 9 4 3 4 8 2
  1 2 3
  1 3 2 
  2 4 5
  2 5 4
  3 6 6
  3 7 9
  3 8 1
  Expected Output:
  2
*/

struct node{
  int cherries;
  vector <int> branches;
  vector <int> branchWeights;
  int parentBranchWeight;
  //int parent;
  int totalWeight = 0;
  int sumCherries;
};

int Patches, YCherries, YMax_Weight;
vector <node> tree;
int  count = 0;

void findSum(int cur){
  if(cur >= Patches)return;
  //find the sum of the cherries in the tree and the weight
  tree[cur].sumCherries = tree[cur].cherries;
  for(int i = 0; i < tree[cur].branches.size(); i++){
    // add the weight of the branch and the weight of the following cherry patch
    findSum(tree[cur].branches[i]);
    tree[cur].totalWeight += tree[cur].branchWeights[i] + tree[tree[cur].branches[i]].totalWeight; 
    tree[cur].sumCherries += tree[tree[cur].branches[i]].sumCherries; 
  }
  if((tree[cur].sumCherries >= YCherries) && ((tree[cur].totalWeight + tree[cur].parentBranchWeight)<= YMax_Weight)){
    //cout << "cut off at branch leading patch " << tree[cur].parent + 1 << " to patch " << cur + 1 << endl;
    //cout << "this leaves us with " << tree[cur].sumCherries << " cherries which weighs only " << tree[cur].totalWeight + tree[cur].parentBranchWeight << " kilograms." << endl;
    count++;
  }
  return;
}

int main() {
  cin >> Patches >> YCherries >> YMax_Weight;
  node t;
  for(int i = 0; i < Patches; i++){
    int d;
    cin >> d;
    t.cherries = d;
    tree.push_back(t);
  }
  for(int i = 0; i < Patches - 1; i++){
    int a, b, weight;
    cin >> a >> b >> weight;
    tree[a - 1].branches.push_back(b - 1);
    tree[a - 1].branchWeights.push_back(weight);
    tree[b - 1].parentBranchWeight = weight;
    //tree[b - 1].parent = a - 1;
  }
  //test
  /*for(int i = 0; i < Patches; i++){
    cout << i + 1 << " " << tree[i].cherries << endl;
    for(int j = 0; j < tree[i].branches.size(); j++){
      cout << "    " << tree[i].branches[j] + 1 << " ";
      cout << tree[i].branchWeights[j] << " ";
      cout << endl;
    }
    cout << endl;
  }*/
  //now find all unique answers to the constraints
  //unless the node is 0
  for(int i = 0; i < tree[0].branches.size(); i++){
    findSum(tree[0].branches[i]);
  }
  cout << count;
  return 0;
}