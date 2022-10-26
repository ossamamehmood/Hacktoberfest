#include<iostream>
#include<vector>

int bool compare(pair <int,int> p1,pairn<int,int> p2){
    return p1.second>p2.second;
}
int main(){
    int n,k,max=0;
    cin>>n;
    int a[n];
    int fr[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    int final[k];
    
    for(int i=0;i<n;i++){
    int c=1;
    for(int j=i+1;j<n;j++){
      if(a[i]==a[j]){
        c++;
        fr[j]=visited;
      }
    }
    if(fr[i]!=visited){
      fr[i]=c;
    }
  }
  for(int i=0;i<n;i++){
    cout<<fr[i]<<" ";
  }
   cout<<"\n";
   vector <pair<int,int>> v;
   for(int i=0;i<n;i++){
    vector.push_back(make_pair(a[i],fr[i]));
   }
   sort(v.begin(), v.end(), compare);
   for(auto element:v){
    cout<<element<<endl;
   }
}