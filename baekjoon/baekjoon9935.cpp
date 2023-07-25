#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

int main(){
    
    string input;   // 입력문자열
    string boom;    // 폭발문자열
    string reverse_boom;    // 편의를 위해 boom을 reverse함
    string tmp="";
    stack<char>st;

    cin >> input;
    cin >> boom;
    reverse_boom=boom;
    reverse(reverse_boom.begin(), reverse_boom.end());
    int boom_len=boom.length();

    for(int i=0;i<input.length(); i++){
        st.push(input[i]); // stack에 input을 처음부터 차례로 push한다.
        if(input[i]==boom[boom_len-1] && st.size()>=boom_len){  // stack에 들어간 input 의 문자가 boom의 마지막 글자와 같으면 boom길이만큼 stack의 글자를 pop한다.
            for(int j=0; j<boom_len; j++){
                tmp.push_back(st.top());
                st.pop();
            }
            if(tmp.compare(reverse_boom)!=0){ // stack에서 pop한 문자가 boom과 같지 않으면 stack에 다시 push하여 원상복구한다.(이때 reverse를 잘 고려한다.)
                for(int j=boom_len-1; j>=0; j--){
                    st.push(tmp[j]);
                }
            } // stack에서 pop한 문자가 boom과 같으면 pop을 유지한다.(stack에서 제거한다.)
            tmp.clear();
        }
    }

    if(st.empty()){
        cout << "FRULA" << endl;
    }
    else{
        input.clear();
        int st_size=st.size(); // pop 하면 스택의 사이즈가 계속 변함을 유의한다.
        for(int j=0; j < st_size; j++){
            input.push_back(st.top());
            st.pop();
        }
        reverse(input.begin(), input.end()); // 최종 stack을 출력한다.
        cout << input << endl;
    }
}