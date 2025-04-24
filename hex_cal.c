#include <stdio.h>
int main(){
    int temp[2], opp, ans, true = 1;

    //input the Hexadecimal  number and convert the number to decimal

    for(int j = 0; j < 2 ; j++){
        char hex[17];
        int length, decimal = 0;
        printf("Enter the hexadecimal numbers : ");
        scanf("%16s", hex);
        for (length = 0; hex[length] != '\0'; length++ );
        int value = 0, base = 1, i; 
        for (i = length - 1; i >= 0; i--){
            if ( hex[i] >= '0' && hex[i] <= '9'){
                value = hex[i] - '0';
            }else if (hex[i] >= 'A' && hex[i] <= 'F'){
                value = hex[i] - 'A' + 10;
            }else {
                printf("Invalid hexadecimal number input !");
                return 1;
            }
            decimal += value * base;
            base *= 16;
        }
        temp[j]= decimal;
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

    //output, convert decimal answerr to hexadecimal

    if(true){
        int num[] = {10, 11, 12, 13, 14, 15};
        char hex_char[] = {'A', 'B', 'C', 'D', 'E', 'F'} ;
        int hex[32];
        int i;
        for (i = 0; ans > 0; i++ ){
            hex[i] = ans % 16;
            ans /= 16;
        }
        printf("The answer in hexadecimal is : ");
        for(int j = i - 1; j >= 0; j--) {
            int found = 0;
            char Ans;
            for (int n = 5; n >= 0 && !found ; n--){
            if (hex[j] >= num[n]){
                    Ans = hex_char[n];
                    found = 1;
                }
            }
            if (hex[j] >= 10){
                printf("%c", Ans);
            }else {
                printf("%d", hex[j]);
            }        
        }
    }

    return 0;
}