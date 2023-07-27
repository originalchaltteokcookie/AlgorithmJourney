#include<iostream>
#define endl '\n'
using namespace std;

int main(){

    int n=0, total=0;

    cin >> n;
    /*
    n! = 1 * 2 * 3 * ... * (n-2) * (n-1) * n
    n! = 2^a * 5^b * k 로 할 수 있는데,
    이때 a > b 는 자명하므로 5의 개수를 센다.
    이때, 25, 75, 125 는 5^2, 5^3 이므로 5가 2개, 3개로 세어진다.
    */
    // 1 ~ n 까지의 수에서 (2 * 5)
    for(int i=5; i<=n; i*=5){
        total += n/i;
    }

    cout << total << endl;
    return 0;
}