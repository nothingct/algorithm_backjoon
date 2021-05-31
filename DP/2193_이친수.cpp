
#include <iostream>
using namespace std;
//1차원 점화식으로 할 경우 
long long d[91];
//2차원 점화식으로 할 경우
long long d2[91][2];
int main(){
    int n;
    cin>>n;
    //1차원 점화식 으로 구현
    /*
    d[1]=1;
    for(int i=2; i<=n; i++)
        d[i] = d[i-1]+d[i-2];
    cout<<d[n]<<'\n';
    */
    //2차원 점화식으로 구현 
    //0 01 11 X
    d2[1][1] =1; //1
    for(int i=2; i<=n; i++){
        d2[i][1] = d2[i-1][0];
        d2[i][0] = d2[i-1][0]+d2[i-1][1];
    }
    cout<<d2[n][0] + d2[n][1] <<'\n';
}