#include <stdio.h>
int main(){
    int ans, opp,temp[2], true = 1;

    //input the octal number

    printf("Enter the first octal numbers : ");
    scanf("%d", &temp[0]);
    printf("Enter the second octal numbers : ");
    scanf("%d", &temp[1]);

    //convert the octal number into decimal number

    for (int i = 0; i < 2; i++){
        int decimals = 0, binary_val , remainder = 0, base = 1;
        for(;temp[i] > 0;){
            remainder = temp[i] % 10;
            temp[i] = temp[i] / 10 ;
            decimals += remainder * base;
            base = base * 8;
        }
        temp[i] = decimals;
    }

    //opperations

    printf("Choose operation :\n1. +\n2. -\n3. *\n4. /\n");
    scanf("%d", &opp);
    if (opp == 1 ){
        ans = temp[0] + temp[1];
    }else if(opp == 2 && temp[0] >= temp[1]){
        ans = temp[0] - temp[1];
    }else if( opp == 3){
        ans = temp[0] * temp[1];
    }else if(opp == 4 && temp[0] % temp[1] == 0){
        ans = temp[0] / temp[1];
        
    }else if(opp == 4 && temp[0] % temp[1] != 0){
        printf("Your answer is a fractional number! we are not that  advance yet!");
        true = 0;
    }else if(opp == 2 && temp[0] < temp[1]){
        printf("make sure that ur first number is bigger than your secound number for subtraction!");
        true = 0;
    }else {
        printf("please enter a valid opporator!");
        true = 0;
    }

    //output

    if (true){
        printf("The answer is : ");
    }
    for (; true ;){
        int octal[32];
        int i;
        for (i = 0; ans > 0; i++ ){
            octal[i] = ans % 8;
            ans /= 8;
        }
        for(int j = i - 1 ; j >= 0; j--) {
            printf("%d", octal[j]);
        }
    }
    
    return 0 ;
}