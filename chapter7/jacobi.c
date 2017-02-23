/***********************************************************
Jacobi-Iterationsverfahren
- Jede Komponente des Lösungsvektors x_new wird für sich
  ohne Berücksichtigung der vorangegangen berechneten 
  Komponenten berechnet
***********************************************************/
#include "my_functions.h"

// define global variables to avoid stackoverflow (happens for very large
// arrays)
double A[N][N] = {0}; 
double b[N] = {0}, x_old[N] = {0}, x_new[N] = {0}, Ax[N] = {0}, subt[N] = {0};

int main(void){

	double sum, residuum;
	int i, j, count = 0;

	randMatrix(A);
	randVector(b);

	#ifdef PRINT
	printMatrix(A);
	printVector(b,'b');
	#endif

	do{
		copyVec(x_new, x_old);

		for(i = 0; i < N; i++){
			sum = 0;
			
			for(j = 0; j < N; j++){
				if(j != i)
					sum += (A[i][j]*x_old[j]);
			}

			x_new[i] = 1/A[i][i] * (b[i] - sum);
		}

		matVecMult(A,x_new,Ax);
		vecSubtract(b, Ax, subt);
		//residuum = vecLength(subt);					// absolutes Residuum
		residuum = vecLength(subt)/vecLength(x_new);	// relatives Residuum
		count++;

	}while(residuum > 0.0000001);

	#ifdef PRINT
	printVector(x_new,'x');
	#endif

	printf("How many iterations? %d\n", count);

	return 0;
}
