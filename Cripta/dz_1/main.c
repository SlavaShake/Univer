#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

long char_to_int(char *c);
void arr_print(long *arr, long N);
void sort(long n, long *a);
int get_number_from_file(FILE* open_file,char number[]);
void file_arr_print(long *arr, long N, FILE* file);


int main(){

    FILE *in_file;
    char file[] = "C:\\data_in.txt";
    char number[20];
    long *a;

    if ((in_file = fopen(file,"r")) == NULL) {
        printf("Failed to open file: %10s\n",file);
        return EXIT_FAILURE;
    }
    long N;
    for(int number_of_number = 0, i = 0;!feof(in_file); ){

        if(get_number_from_file(in_file,number)){

            number_of_number++;

            if(number_of_number == 1){
                N = char_to_int(number);
                printf("N = %5ld\n",N);
                a = (long*)malloc(sizeof(N*sizeof(long)));
            }
            if(number_of_number > 1){
                a[i] = char_to_int(number);
                printf("a[%d] = %5ld\n",i,a[i]);
                i++;
            }
        }
    }
    fclose(in_file);
    printf("___________BEFORE___________\n");
    arr_print(a,N);
    printf("____________NOW___________\n");
    FILE* file_write = fopen("C:\\data_out.txt","wb");

    sort(N,a);
    arr_print(a,N);
    file_arr_print(a, N,file_write);

    free(a);
    return 0;
}

//вытаскиваем числа из потока чтения файла
int get_number_from_file(FILE* open_file,char number[]){

    char c = fgetc(open_file);
    int i = 0;
    for( ;(c >= 48 && c <= 57) || c == 45; i++, c = fgetc(open_file))
        number[i] = c;

    number[i] = '\0';


    if(number[0] == '\0')
        return 0;

    return 1;
}

long char_to_int(char *c){
    long Num = 0;
    int sign=1;
    for(int i = 0;c[i]!='\0';i++){
        if(c[i] == 45){
            sign = -1;
            continue;
        }

        Num = Num*10+(c[i]-'0');
    }
    return Num*sign;
}

void arr_print(long *arr, long N) {
    printf("The array is: ");
    for(int i = 0;i<N;i++)
        printf("%ld ",arr[i]);
    printf("\n");
}
void file_arr_print(long *arr, long N, FILE* file) {
    fprintf(file,"The array is: ");
    for(int i = 0;i<N;i++)
        fprintf(file,"%ld ",arr[i]);
    fprintf(file,"\n");
}

void sort(long n, long *a){
    for(long i = 0 ; i < n - 1; i++) {
           // сравниваем два соседних элемента.
           for(long j = 0 ; j < n - i - 1 ; j++) {
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
