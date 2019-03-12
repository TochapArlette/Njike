#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define MIN 0
#define MAX 100


//function generates the numbers randomly in the range
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

//allocate memory for the numbers allocated
int* generate_array()
{
    int *array = malloc((N)*sizeof(int));
    for(int i= 0; i<N; i++)
    {
        array[i]=0;
    }
    return array;
}

//generates the numbers randomly and put in the array
int* generate_numbers(int* array)
{
    array = generate_array();
    int n,flag,count=0,i=0;

    while(i<5) //UNTIL I REACH THE LAST INDEX OF THE ARRAY
    {
       n = rand_a_b(MIN,MAX);  //GENERATE A NUMBER RANDOMLY
       i=i-count;
       count=0;
       flag=0;
       for(int j=0; j<N; j++)  //VERIFY IF THE NUMBER GENERATED IS ALREADY PRESENT IN THE ARRAY
       {
           if(n==array[j])
           {
               flag=1;
               break;
           }
       }
       if(flag==0)
       {
           array[i]=n;
       }
       else
       {
           count++;
       }
       i++;
    }

    return array;
}


void free_array(int*array)
{
    free(array);
}

int main(int argc,char*argv[])
{

    int n,flag=0;

    int *array;
    array=generate_array();

    if(argc!=2)
    {
        printf("\nerror in program parameters\n");
        return -1;
    }
    n = atoi(argv[1]);

    //printf("\n\nEnter the number n of operations you want to execute\n");
    //scanf("%d",&n);

    srand(time(NULL));

    printf("\n");

    float d=0;
    FILE *file=NULL;
    file =fopen("result.txt","w");

    if(file==NULL)
    {
        printf("error in the opening of file\n");
    }

    if(flag==0)
    {
        fprintf(file,"%d",1756144);
        flag=1;
        fprintf(file,"\n\n");
    }

    for(int k=0; k<n; k++)
    {
        array = generate_numbers(array);
    for(int j=0; j<5; j++)
    {
        if((array[j]/2)==0)
        {
            d = (float)array[j] + array[j+2] - array[j+1];
            fprintf(file,"%d + %d - %d = %.2f\n", array[j], array[j+2] , array[j+1],d);
            break;
        }
        else if(array[4]%2 !=0)
        {
            d = (float)array[j] / array[j+3] * array[j+2] + array[j+4];
            fprintf(file,"(%d / %d * %d + %d) = %.2f\n",array[j] , array[j+3] , array[j+2] , array[j+4],d);
            break;
        }
        else
        {
            d = (float)array[j+3] / array[j] + array[j+2] - array[j+4];
            fprintf(file,"(%d / %d + %d - %d) = %.2f\n",array[j+3] , array[j] , array[j+2] , array[j+4],d);
            break;
        }
    }
    }

    free_array(array);

    return 0;
}
