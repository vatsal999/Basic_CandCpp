#include <stdio.h>

char pixel = '*';

void slant(int n){
    // *
    // **
    // ***
    // ****
    for (int i = 1; i <= n; i++){
        for ( int j = 1; j <= i; j++){
            printf("%c",pixel);

        }
        printf("\n");
    }


}

void render(int n){
    // ####*
    // ###***
    // ##*****
    // #*******

    // number of lines
    for(int i = 0; i < n; i++){
        // print spaces
        for(int j = 0; j > n; j--){
            printf(" ");
        }
            printf("\n");
    }
}

int main(){
    slant(5);

}
