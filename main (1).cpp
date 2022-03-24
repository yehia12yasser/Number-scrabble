#include <iostream>
#include <vector>
using namespace std;

bool checkwin(vector<int> A,int arr_size,int sum){
    for(int i=0;i<arr_size-2;i++){
        for(int j=i+1;j<arr_size - 1;j++){
            for( int k=j+1;k<arr_size;k++){
                if(A[i]+A[j]+A[k]==15){
                    return true;
        }
        }
}
    }
    return false;
}





bool check(int number , vector<int> vect){
    for(int n : vect){
        if (n == number){
            return true;
        }
    }
    return false;
}
string st_vect(vector<int> vect){
    string st = "";
    for(int n : vect){
        st += to_string(n) + ",";
    }
    return st;
}
vector<int> earase_number(int number,vector<int> vect1){
    vector<int> vect2 ;
    for(int i : vect1){
        if (i != number){
            vect2.push_back(i);
        }
    }
    return vect2;
}
int main()
{
    vector<int> numbers {1,2,3,4,5,6,7,8,9};
    vector<int> list1,list2;
    cout << st_vect(numbers) << endl;
    while (numbers.size() > 0){
        while (true){
            int inp;
            cout << "player 1 enter number from "<< st_vect(numbers) << " : ";
            cin >>inp;
            if (check(inp,numbers)){
                list1.push_back(inp);
                numbers = earase_number(inp,numbers);
                break;
            }else{
                cout << "Please Enter Another Number" << endl;
            }
        }
        if (checkwin(list1,list1.size(),15) and list1.size() >= 3){
            break;
        }
        while (true){
            int inp;
            cout << "player 2 enter number from "<< st_vect(numbers) << " : ";
            cin >>inp;
            if (check(inp,numbers)){
                list2.push_back(inp);
                numbers = earase_number(inp,numbers);
                break;
            }else{
                cout << "Please Enter Another Number" << endl;
            }
        }
        if (checkwin(list2,list2.size(),15) and list2.size() >= 3){
                break;
            }
    }
    bool player1_w = checkwin(list1,list1.size(),15);
    bool player2_w = checkwin(list2,list2.size(),15);
    if(player1_w){
        cout << "Player 1 Win" << endl;
    }
    else if(player2_w){
        cout << "Player 2 Win" << endl;
    }
    else{
        cout << "Draw" << endl;
    }
    return 0;
}
