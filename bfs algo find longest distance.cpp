#include<iostream>
#include<vector>
#include <queue>
using namespace std;
vector<int>List[100];
queue<int>Q;
int c[100];
int d[100];
int p[100];
 int highs[20];
int counter[100];
void highest(int A[],int n){
    int counter=A[0];
    int high=0;

    for(int i=1; i<n;i++){
        if(A[i]>counter){
            counter=A[i];
            high=i;
        }
    }

for(int i=0;i<n;i++){
    if(A[i]==counter){
        highs[i]=counter;
    }
}


}
int main(){
int n;
int u,v;

cout<< "enter the number of edge" ;
cin>>n;
cout<<"enter the number of vertex ";
int m;
cin>>m;
int counter[n];
cout<<"enter the edges of vertex ";
for(int i=0;i<n;i++){
   cin>>u>>v;
   List[u].push_back(v);
    List[v].push_back(u);

}
for(int i=0;i<100;i++){
    c[i]=0;
    d[i]=999;
    p[i]=-1;
}

Q.push(2);
    c[2]=1;//white=0 gray=1 black=2
    d[2]=0;
    p[2]=-1;

    while(!Q.empty()){

        int q= Q.front();
        Q.pop();

        for(auto x:List[q]){
                if(c[x]==0){
            c[x]=1;//white=0 gray=1 black=2
            d[x]=d[q]+1;
            p[x]=q;
             Q.push(x);
                }
        }
        c[q]=2;



    }


    for(int i=0;i<m;i++){
        cout<<i<<" vertex distance "<<d[i]<<endl;
    }

   highest(d,m);

for(int i=0;i<m;i++){

        if(highs[i]>0){
            cout<<"highest distance has "<<i <<"vertex"<<endl;
        }
    }

}
