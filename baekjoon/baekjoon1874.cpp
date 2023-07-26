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
    output_i=0;

    while(input_arr[back]<=n && back>=0 && number <= n){
        if(number == input_arr[back]){
            stk.push(number);
            vec.push_back('+');
            number+=1;
            back-=1;
        }
        else if(number < input_arr[back]){
            int start=0, end=0, count=0;
            for(int i=0; i<n; i++){
                if(number <= input_arr[i] && input_arr[i] < input_arr[back]){
                    end=i;
                }
            }
            if(end>=most_big){possible=false; break;}
            count=(input_arr[back]-number);
            start=end-count+1;

            while(start<=end){
                if(number < input_arr[start]){
                    stk.push(number);
                    vec.push_back('+');
                    number+=1;
                }
                else if(number == input_arr[start]){
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
                    output_arr[output_i]=stk.top();
                    stk.pop();
                    vec.push_back('-');
                    output_i+=1;
                    start+=1;
                }
            }

        }
        else{
            possible=false;
            break;
        }
    }

    if(possible){
        for(int i=output_i; i<n; i++){
            output_arr[i]=stk.top();
            stk.pop();
            vec.push_back('-');
        }
        for(int i=0; i< n; i++){
            if(input_arr[i] != output_arr[i])   {possible=false;}
        }
    }
    if(possible){
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