#include <stdio.h>
#include <string.h>

int count_charactor(char *input_char){
    int len;
    len = strlen(input_char);
    printf("The length of chars: %d \n", len);
    return len;
}
char *input_charactor(){
    char input_user;
    char *input_p;
    scanf("%c", &input_user);
    input_p = &input_user;
    return input_p;
}

int check_charactor(int len, char *input){
    char *p;
    p = input_charactor();
    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", p[i]);
    }
    return 0;
}
int main(){
    char input_char[20];
    char *p;
    scanf("%s", &input_char);
    p = input_char;
    // printf("%p", p);
    check_charactor(count_charactor(p), p);
}