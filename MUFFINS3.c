// Code for cupcakes problem 
#include<stdio.h>
#include<stdlib.h>

int maxPackage(int N){
    int A = 1, C, P;
    int Cmax = 0, Amax = 0;
    while(A <= N){
        C = N%A;
        P = (N - C)/A;
        if (C >= Cmax){
            Cmax = C; Amax = A;
        }
        A++;
    } 
    return Amax;

}


int main(){
    int T, N;
    scanf("%d", &T);
    while(T > 0){
        scanf("%d", &N);
//        printf("T = %d and N = %d\n", T, N);
//        printf("maximum package size = %d\n", maxPackage(N));
        printf("%d\n", maxPackage(N));
        T--;
    }
    return 0;
}
