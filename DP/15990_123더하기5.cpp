

#include <iostream>
#include <vector>
using namespace std;

int MOD =1000000009;
int limit = 100000;
long long d[100100][4];


int main(){
    int t,n;
    cin>>t;
    for(int i=1; i<=limit; i++){    
        //d[i][1]
        if(i>=1){
            d[i][1]= (d[i-1][2]+d[i-1][3]);
            if(i==1)
                d[i][1] = 1;
        }
        //d[i][2]
        if(i>=2){
            d[i][2]= (d[i-2][1]+d[i-2][3])%MOD;
            if(i==2)
                d[i][2] =1;
        }
        if(i>=3){
            d[i][3] = (d[i-3][1]+d[i-3][2])%MOD;
            if(i==3)
                d[i][3] =1;
        }
        d[i][1]%=MOD;
        d[i][2]%=MOD;
        d[i][3]%=MOD;
    }

    while(t--){
        cin>>n;
        long long ans = (d[n][1]+d[n][2]+d[n][3])%MOD;
        cout<<ans<<'\n';
    }
}