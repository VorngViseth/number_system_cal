#include <stdio.h>
int main(){
    int ans, opp,temp[2], true = 1;

    // input the binary number

    printf("Enter the first binary numbers : ");
    scanf("%d", &temp[0]);
    printf("Enter the second binary numbers : ");
    scanf("%d", &temp[1]);

    //convert the binary number into decimal number

    for (int i = 0; i < 2; i++){
        int decimals = 0, binary_val , number, remainder = 0, base = 1;
        number = temp[i];
        for(;number > 0;){
            remainder = number % 10;
            number = number / 10 ;
            decimals += remainder * base;
            base = base * 2;
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
        int binary[32];
        int i;
        for (i = 0; ans > 0; i++ ){
            binary[i] = ans % 2;
            ans /= 2;
        }
        for(int j = i - 1 ; j >= 0; j--) {
            printf("%d", binary[j]);
        }
    }
    
    return 0 ;
}