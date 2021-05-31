/*
문제
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
*/
#include <iostream>
#include <vector>


using namespace std;

int d[101][101];
int MOD = 1000000000;
int main(){
    int n ;
    cin>>n;

    for(int i=1; i<=9; i++){
        d[1][i] = 1;
    }

    for(int i=2; i<=n; i++){

        for(int j =1; j<=9; j++){
            if(j>1){
                d[i][j] += d[i-1][j-1]%MOD;
                d[i][j]%=MOD;
            }
            if(j<9){
                d[i][j] = d[i-1][j+1];
                d[i][j]%=MOD;
            }
        }
    }
    int ans = 0; 
    for(int i=1; i<=9; i++){
        ans+=d[n][i];
        ans%=MOD;
    }
    cout<<ans<<'\n';
}