/*
입력
첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)

둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)

출력
첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최솟값을 출력한다.
*/

#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n ;
    vector<int> p(n+1);//n만큼만 배열 동적 선언 
    vector<int> d(n+1,-1); //메모이제이션 배열 -1로 초기화 선언

    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    d[0]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(d[i]==-1 || d[i] > d[i-j]+p[j])
                d[i] = d[i-j]+p[j];
        }
    }
    cout<<d[n]<<'\n';
}