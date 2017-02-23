#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define N 2000 // everything in num2 just serves proof of concept, so I define it here
//#define PRINT

void diag(double (*A)[N], double (*D)[N]){

	for(int ii = 0; ii < N; ii++){
		D[ii][ii] = A[ii][ii];
	}	

}

void matrixMult(double (*A)[N], double (*B)[N], double (*C)[N]){
	double sum = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				sum += (A[i][k] * B[k][j]);
			}
			C[i][j] = sum;
			sum = 0;
		}
	}
}

void matVecMult(double (*A)[N], double *B, double *C){
	double sum = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			sum += (A[i][j] * B[j]);
		}
		C[i] = sum;
		sum = 0;
	}
}

double vecLength(double* vec){
	double sum = 0;

	for(int i = 0; i < N; i++){
		sum += (vec[i]*vec[i]);
	}

	return sqrt(sum);
}

void vecSubtract(double* A,double* B, double* dest){
	for(int i = 0; i < N; i++){
		dest[i] = A[i] - B[i];
	}
}

void randMatrix(double (*A)[N]){
	int i, j;

	srand((unsigned) time(NULL));

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			A[i][j] = ((rand() % 11)/(10*(double)N));
		}
	}

	for(i = 0; i < N; i++){
		A[i][i] = (rand()%10)+1;
	}
}

void randVector(double* vec){
	int i;

	srand((unsigned) time(NULL));

	for(i = 0; i < N; i++){
		vec[i] = rand() % 100;
	}
}

void printMatrix(double (*A)[N]){
	printf("=============================\nA =\n");

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%2.2f\t", A[i][j]);
		}
		printf("\n");
	}
}

void printVector(double* vec, char x){
	printf("============================\n%c =\n",x);

	for(int i = 0; i < N; i++){
		printf("%lf\n", vec[i]);
	}

}

#endif
