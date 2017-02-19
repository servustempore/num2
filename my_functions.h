#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS

#include <math.h>
#define N 3 // not clever to define it here, but everything in num2 just serves proof of concept

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

#endif