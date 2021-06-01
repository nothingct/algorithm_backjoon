/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
lis -> 1로 초기화(자기자신 이 마지막 인 경우 는 모두 가지고 있음)
for(i=2->n): 
    if(a[i] > a[i-1])
        lis[i]=max(lis[i],lis[i-1]+1)
입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1010];
int lis[1010];
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        lis[i] = 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j]){
                lis[i] =max(lis[i],lis[j]+1); 
            }
        }
    }
    int ans =0;
    for(int i=1; i<=n; i++){
        ans =max(ans,lis[i]);
    }
    cout<<ans<<'\n';
}