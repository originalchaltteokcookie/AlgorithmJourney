#include<iostream>
#include<queue>
#include<utility>
#include<vector> // utility 헤더파일이 포함됨
#include<algorithm>  // utility 헤더파일이 포함됨
#define endl '\n'

using namespace std;

int main(){

    int x=0, n=0, m=0, k=0, index=0, value=0;
    queue<pair<int, int> > que;
    vector<int> s_vec;

    cin >> x;
    
    for(int i=0; i<x; i++){
        cin >> n >> m;
        s_vec.clear();
        for(int j=0; j<n; j++){
            cin >> k;
            que.push(make_pair(j, k));
            s_vec.push_back(k);
        }
        /*
        입력받은 중요도를 내림차순 정렬한다.
        그러면 중요도가 큰 순서로 정렬되는데,
        queue의 front부터 pop하면서 pop한 front의 중요도가 이 vector의 앞쪽 즉, 가장 큰 수라면
        그대로 pop 하고, 그렇지 않으면 pop한 것을 다시 queue에 push한다.
        */
        sort(s_vec.begin(), s_vec.end(), greater<int>());   // 내림차순 정렬
        for(int j=0; j<n; j++){
            while(true){
                index=que.front().first;
                value=que.front().second;
                que.pop();
                if(value == s_vec[j]){
                    if(index == m){
                        cout << (j+1) << endl;
                    }
                    break;
                }
                else{
                    que.push(make_pair(index, value));
                }
            }
        }
    }

    return 0;
}