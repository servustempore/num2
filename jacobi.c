/***********************************************************
Jacobi-Iterationsverfahren
- Jede Komponente des Lösungsvektors x_new wird für sich
  ohne Berücksichtigung der vorangegangen berechneten 
  Komponenten berechnet
***********************************************************/

#include <stdio.h>
#include <math.h>
#define N 3

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

int main(void){
	
	double A[N][N] = {{7,3,2},{3,4,1},{1,2,5}}, D[N][N] = {0}, C[N][N];
	double b[N] = {4,5,2}, x_old[N] = {0}, x_new[N] = {0}, Ax[N] = {0}, subt[N] = {0};
	double len, sum, residuum;

	do{
		for(int i = 0; i < N; i++){
			x_old[i] = x_new[i];	
		}

		for(int i = 0; i < N; i++){
			sum = 0;
			
			for(int j = 0; j < N; j++){
				if(j != i)
					sum += (A[i][j]*x_old[j]);
			}

			x_new[i] = 1/A[i][i] * (b[i] - sum);
		}

		matVecMult(A,x_new,Ax);
		vecSubtract(b, Ax, subt);
		//residuum = vecLength(subt);					// absolutes Residuum
		residuum = vecLength(subt)/vecLength(x_new);	// relatives Residuum

	}while(residuum > 0.0000001);

	for(int i = 0; i < N; i++){
		printf("%lf\n",x_new[i]);
	}	

	return 0;
}

	/*
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%lf ", A[i][j]);
		}
		printf("\n");
	}
	*/