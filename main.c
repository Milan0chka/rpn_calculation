#include <stdio.h>
#define INPUT_LIMIT 20

int calculateRPN(char *rpn, int length){
    int stack[10], head_index =-1, number =0;

    for(int i =0; i < length; i++){
        if (rpn[i] >= '0' && rpn[i] <= '9')
            number = number*10 + (rpn[i]-'0');

        else if (rpn[i] == ','){
            stack[++head_index] = number;
            number = 0;
        }

        else{
            if((rpn[i-1] >= '0' && rpn[i-1] <= '9')){
                stack[++head_index] = number;
                number = 0;
            }
            switch (rpn[i]) {
                case '+':
                    number = stack[head_index-1] + stack[head_index];
                    break;
                case '-':
                    number =  stack[head_index-1] - stack[head_index];
                    break;
                case '*':
                    number = stack[head_index-1] * stack[head_index];
                    break;
                case '/':
                    number =  stack[head_index-1] / stack[head_index];
                    break;
            }
            printf("\nOPERATION : %d %c %d = %d", stack[head_index-1], rpn[i], stack[head_index], number);
            stack[head_index] = 0;
            stack[head_index-1] = number;
            head_index--;
            number = 0;
        }
    }

    return stack[0];
}


int main() {
    char rpn[INPUT_LIMIT], input;
    int length =0;

    printf("Enter your RPN statement => ");
    do{
        input = getchar();

        if ((input >= '0' && input<= '9')||
            (input == '+') || input == '-' || input == '*' || input =='/' || input==',')
            rpn[length++] = input;

    }while(input !='\n' && length <= INPUT_LIMIT-1);
    rpn[length] = '\0';

    printf("Statement read => %s.\nStarting calculations ...", rpn);

    int result = calculateRPN(rpn, length);
    printf("\nResult equals to %d", result);

    return 0;
}
