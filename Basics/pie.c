#include <stdio.h>

// TODO: it repeats the digits after 10 digits. find out why 

int main(){
    int numofdigits = 10;
    int a = 22;
    for(int i = 0; i < numofdigits; i++){
        int x = a/7;
        printf("%d",x);
        a = (a%7)*10;
    }

}
