#include<stdio.h>
#include<math.h>


int * decimal(int n)
{
    int *Vetor = malloc(23 * sizeof(int));
    int k;
    for (int i=0; i <=23; i++)
   {
      k = n >> i;
      if (k & 1)
        Vetor[i] = 1;
      else
        Vetor[i] = 0;
    }
    return Vetor;
}

void inverte(int* vetor, int tamanho)
{
   int *ptr1 = vetor;
   int *ptr2 = ptr1 + tamanho - 1;
   while(ptr1 < ptr2)
   {
      *ptr1 ^= *ptr2 ^= *ptr1 ^= *ptr2;
      ++ptr1;
      --ptr2;
   }
}

int binario(int n, int i)
{
    int k;
    for (i--; i >= 0; i--)
   {
      k = n >> i;
      if (k & 1)
          printf("1");
      else
         printf("0");
    }
}

typedef union {
	float f;
	struct {
		unsigned int mantissa : 23;
		unsigned int exponente : 8;
		unsigned int sinal : 1;
	} field;
} unionfloat;

typedef union {
	float a;
	struct {
		unsigned int mantissa : 23;
		unsigned int exponente : 8;
		unsigned int sinal : 1;
	} secon;
} second;

typedef union {
	float r;
	struct {
		unsigned int mantissa : 23;
		unsigned int exponente : 8;
		unsigned int sinal : 1;
	} result;
} resultado;

int* vet(int, int);

int main() {
    resultado soma;
    second variavel;
	unionfloat var;

    printf("Entre com um ponto flutuante: ");
    scanf("%f",&var.f);

    printf("Entre com o segundo ponto flutuante: ");
    scanf("%f",&variavel.a);

    printf("%d ",var.field.sinal);
    binario(var.field.exponente, 8);
    printf(" ");
    binario(var.field.mantissa, 23);
    printf("\n");

    printf("%d ",variavel.secon.sinal);
    binario(variavel.secon.exponente, 8);
    printf(" ");
    binario(variavel.secon.mantissa, 23);
    printf("\n");

    //printf("numero reconstituido 1 : %f", pow(-1,(var.field.sinal)) * ( 1.0 + var.field.mantissa / pow(2,23)) * pow(2,(var.field.exponente - 127)));
    //printf("\n");

    //printf("numero reconstituido 2   : %f", pow(-1,(variavel.secon.sinal)) * ( 1.0 + variavel.secon.mantissa / pow(2,23)) * pow(2,(variavel.secon.exponente - 127)));
    //printf("\n");

    int expoente1 = var.field.exponente - 127;
    int expoente2 = variavel.secon.exponente - 127;

    printf("expoente 1: %d", expoente1);
    printf("\n");
    printf("expoente 2: %d", expoente2);
    printf("\n");


    int *mantissa1 = decimal(var.field.mantissa);
    int *mantissa2 = decimal(variavel.secon.mantissa);
    inverte(mantissa1,23);
    inverte(mantissa2,23);

    for (int i = 0; i < 23; i++)
        printf("%d", mantissa1[i]);

    printf("\n");

    for (int i = 0; i < 23; i++)
        printf("%d", mantissa2[i]);




    free(mantissa1);
    free(mantissa2);
    return 0;
}


   /* char mantissa1[23];
    mantissa1[23] = montaMantissa(var.field.mantissa);
    int aux = 23;
    for (aux--; aux >= 0; aux--)
    {
        printf("%c",mantissa1[aux]);
    }




     return 0;
}




    /*printf("mantissa 1: %d", mantissa1);
    binario(variavel.secon.mantissa, 23);
    printf("mantissa 2: %d", mantissa2);
    printf("\n");

    if(expoente1 < expoente2)
{
    int i;
        soma.result.exponente = expoente2+127;
        for (i=0;i<=expoente2-expoente1; i++)
        {

        }
    }

    if(expoente1 > expoente2)
    {
        int i;
        soma.result.exponente = expoente1+127;
        for (i =0;i<=expoente1-expoente2; i++)
        {

        }
    }


*/

