#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > allpermutations;
vector<int> permutation;

void rec_permute(vector<int> &a,bool vis[]){
  if(permutation.size()==a.size()){
    allpermutations.push_back(permutation);
  }
  else{
    for(int i=0;i<a.size();i++){
      if(vis[i]) continue;
      permutation.push_back(a[i]);
      vis[i]=true;
      rec_permute(a,vis);
      vis[i]=false;
      permutation.pop_back();
    }
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  bool vis[n];
  memset(vis,false,sizeof(vis));
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  cout << "Permutations:\n";
  rec_permute(a,vis);
  for(auto i=allpermutations.begin();i!=allpermutations.end();i++){
    for(int j=0;j<(*i).size();j++){
      cout << (*i)[j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
