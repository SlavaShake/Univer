#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int Char_to_Int(char *c);
void arr_print(int *arr);
void delete_arr(char *c);
void sort(int n, int *a);

int main() {

    FILE *in_file;
    char file[] = "data_in.txt";
    int c;
    int *a;
    int N;
    int k = 0, y = 0;
    int i = 0;
    char number[13];

    if ((in_file = fopen(file,"r")) == NULL) {
        perror("Failed to open file \"data_in.txt\"\n");
        return EXIT_FAILURE;
    }

    do{
        if ((c >= 48 && c <= 57) || c == 45){
            number[i] = c;
//            printf("number[%d] = %c\n",i,number[i]);
            i++;
        }

        if (c == 32 || c == '\n')
        {
            i=0;
            k+=1;
            if(k==1)
            {
                N = Char_to_Int(number);
                a = (int*) malloc(N*sizeof(int));
//                printf("N = %d\n",N);
                delete_arr(number);
            }
            if (k>1)
            {
                a[y] = Char_to_Int(number);
//                arr_print(a);
                y++;
                delete_arr(number);
            }
//            printf("________________\n");
        }

    }
    while((c = fgetc(in_file)) != EOF);
    printf("_______BEFORE_________\n");
    printf("N = %d\n",N);
    arr_print(a);
    printf("_______BEFORE_________\n");

    sort(N,a);
    printf("_______RESULT_________\n");
    printf("N = %d\n",N);
    arr_print(a);
    printf("_______RESULT_________\n");

    fclose(in_file);
    //Запись в фаил
    FILE *out_file;
    if ((out_file = fopen("data_out.txt","wb")) == NULL)
           printf("Failed to open file \"data_out.txt\"\n");
    else{
           int i = 0;
           while(a[i]!= '\0')
           {
               fprintf(out_file, "%d ", a[i]);
               i++;
           }

         }

    fclose(out_file);




    free(a);
    return 0;
}

int Char_to_Int(char *c){
    int Num = 0;
    int sign=1;
    for(int i = 0;c[i];i++)
    {
        if(c[i] == 45)
        {
            sign = -1;
            continue;
        }

        Num = Num*10+(c[i]-'0');
    }
//    printf("Num = %d \n",Num*sign);
    return Num*sign;
}

void arr_print(int *arr) {
    printf("The array is: ");
    while(*arr)
        printf("%d ", *arr++);
      printf("\n");
}

void delete_arr(char *c){
    while(*c)
    {
        *c = '\0';
        *c++;
    }
}

void sort(int n, int *a){
    for(int i = 0 ; i < n - 1; i++) {
           // сравниваем два соседних элемента.
           for(int j = 0 ; j < n - i - 1 ; j++) {
               if(a[j] > a[j+1]) {
                  // если они идут в неправильном порядке, то
                  //  меняем их местами.
                  int tmp = a[j];
                  a[j] = a[j+1] ;
                  a[j+1] = tmp;
               }
            }
        }
}

