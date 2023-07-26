#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){

    int n=0, back=0, number=0, output_i=0, front=0, most_big=0;
    int *input_arr=nullptr;
    int *output_arr=nullptr;
    bool possible=true;
    stack<int> stk;
    vector<char>vec;
    vector<char>::iterator iter;

    cin >> n;
    input_arr=new int[n];
    output_arr=new int[n];
    for(int i=0;i<n; i++){
        cin >> input_arr[i];
        if(input_arr[i]==n){most_big=i;} // 가장 큰 수가 있는 곳의 index
    }

    back=n-1; // 입력 배열의 가장 뒤 위치
    number=1;
    output_i=0; // pop 되면 output 배열에 pop된 숫자들을 차례로 넣는다. 이때 사용하는 index변수

    // while문 안에서 number 는 1부터 n까지 차례로 증가한다.
    // 주어진 수열에서 가장 큰 수인 n을 기준으로, n의 오른쪽으로 갈수록 pop이 가장 늦게 된다.
    // back은 수열의 맨 뒤를 가리키는 index로, 가장 큰 수인 n의 오른쪽 index까지만 이동한다.
    while(input_arr[back]<=n && back>=0 && number <= n){
        if(number == input_arr[back]){
            // 1부터 증가하는 number보다 수열의 뒤쪽 숫자보다(index가 back) 작다 
            // -> back이 가리키는 숫자보다 작은 number들이 pop되었으며, 
            // back이 가리키는 숫자는 가장 큰 수인 n이 pop될 때까지 stack안에 남아있다는 것을 의미한다.
            // -> 따라서 stack에 넣기만 한다.(빼는 것은 나중에한다.)
            stk.push(number);
            vec.push_back('+');
            number+=1;
            back-=1;
        }
        else if(number < input_arr[back]){
            // number가 back이 가리키는 숫자보다 작다면, 이미 pop되었음을 의미한다.
            // 수열에서 n 왼쪽에 있는 숫자들 중 number <= x < back이 가리키는 숫자들이 있는 구간을 찾는다.
            // 이때 이 구간의 시작index를 start, 끝index를 end, 그 구간에 있는 숫자들의 개수를 count로 놓는다.
            int start=0, end=0, count=0;
            for(int i=0; i<n; i++){
                if(number <= input_arr[i] && input_arr[i] < input_arr[back]){
                    end=i;
                }
            }
            if(end>=most_big){possible=false; break;} // n의 왼쪽에 찾고자 하는 number구간이 존재하지 않으면 while문을 탈출한다.
            count=(input_arr[back]-number);
            start=end-count+1;

            while(start<=end){ // 찾은 구간의 처음부터 끝까지 탐색한다.
                // 찾은 number구간의 앞쪽일수록 빨리 pop된 숫자들이다.
                /*
                1. (number < start가 가리키는 숫자)라면 start가 가리키는 숫자보다 일찍 push되었지만
                start가 가리키는 숫자보다 늦게 pop되었음을 의미한다.
                즉, start가 가리키는 숫자가 pop될때까지는 stack에 존재함한다.
                따라서 별다른 pop없이 number를 stack에 push만 해준다.

                2. (number == start가 가리키는 숫자)라면 push되었다가 pop되었다는 것을 의미한다.
                pop되었기 때문에 start를 하나 증가하여 number구간 내에서 그 다음 위치로 이동한다.

                3. 1, 2번에 해당하지 않는다면 (number > start가 가리키는 숫자) 이다.
                이때는 이미 stack안에 push되었던 number들이 pop된다.
                pop되었기 때문에 start를 하나 증가하여 number구간 내에서 그 다음 위치로 이동한다.
                (number == start가 가리키는 숫자) 가 될때까지 pop된다.
                */

                if(number < input_arr[start]){ // 1
                    stk.push(number);
                    vec.push_back('+');
                    number+=1;
                }
                else if(number == input_arr[start]){ // 2
                    stk.push(number);
                    vec.push_back('+');
                    output_arr[output_i]=stk.top();
                    stk.pop();
                    vec.push_back('-');
                    output_i+=1;
                    number+=1;
                    start+=1;
                }
                else{
                    output_arr[output_i]=stk.top(); // 3
                    stk.pop();
                    vec.push_back('-');
                    output_i+=1;
                    start+=1;
                }
            }

        }
        else{ // 오름차순으로 push되기 때문에 (number > input_arr[back]) 라면 오류가 있다는 것이다.
            possible=false;
            break;
        }
    }

    if(possible){
        for(int i=output_i; i<n; i++){ // stack에 남아있는 숫자들을 모두 pop하여 output 배열에 넣는다.
            output_arr[i]=stk.top();
            stk.pop();
            vec.push_back('-');
        }
        for(int i=0; i< n; i++){ // input 배열과 output배열을 비교하여 수열이 동일한지 확인
            if(input_arr[i] != output_arr[i])   {possible=false;}
        }
    }
    if(possible){ // 동일하면 출력
        for(iter=vec.begin(); iter != vec.end(); iter++){
            cout << *iter << '\n';
        }
    }
    else{
        cout << "NO" << '\n';
    }
    
    delete[] input_arr;
    delete[] output_arr;

    return 0;
}