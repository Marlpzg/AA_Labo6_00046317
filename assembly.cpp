#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int fastest(int a[][2], int t[][2], int* e, int* x, int n){
    int f1[n];
    int f2[n];
    f1[0] = e[0]+a[0][0];
    f2[0] = e[1]+a[0][1];
    string w1=to_string(e[0])+", "+to_string(a[0][0]);
    string w2=to_string(e[0])+", "+to_string(a[0][1]);

    for(int j = 1; j < n; j++){
        string tempw1 = w1;
        string tempw2 = w2;

        if(f1[j-1]+a[j][0] <= f2[j-1]+t[j-1][1]+a[j][0]){
            f1[j] = f1[j-1]+a[j][0];
            w1=tempw1+", "+to_string(a[j][0]);
        }else{
            f1[j] = f2[j-1]+t[j-1][1]+a[j][0];
            w1=tempw2+", "+to_string(a[j][0]);
        }

        if(f2[j-1]+a[j][1] <= f1[j-1]+t[j-1][0]+a[j][1]){
            f2[j] = f2[j-1]+a[j][1];
            w2=tempw2+", "+to_string(a[j][1]);
        }else{
            f2[j] = f1[j-1]+t[j-1][0]+a[j][1];
            w2=tempw1+", "+to_string(a[j][1]);
        }
        
    }

    if(f1[n-1]+x[0] <= f2[n-1]+x[1]){
        cout << w1 << ", " << x[0];
        return f1[n-1]+x[0];
    }else{
        cout << w2 << ", " << x[1];
        return f2[n-1]+x[1];
    }
}

int main(){
    int lines[][2] = {{4,2}, {5,10}, {3,1}, {2,4}};
    int times[][2] = {{7,9}, {4,2}, {5,8}};
    int e[] = {10, 12};
    int x[] = {18, 7};
    printf("\n%d",fastest(lines, times, e, x, 4));
    return 0;
}