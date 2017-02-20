/***********************************************************
Gauß-Seidel-Iterationsverfahren
- Unterscheidet sich von Jacobi im Hinblick auf das direkte einsetzen
  neu berechneter Komponenten des iterierten Lösungsvektors,
  statt diesen zuerst komplett zu bestimmen
***********************************************************/
#include "my_functions.h"
  
// define global variables to avoid stackoverflow (happens for very large
// arrays)
double A[N][N] = {0}; 
double b[N] = {0}, x_old[N] = {0}, x_new[N] = {0}, Ax[N] = {0}, subt[N] = {0};

int main(void){
	double sum, residuum;
	int i, j, count = 0;

	fillMatrix(A);
	fillVector(b);

	#ifdef PRINT
	printMatrix(A);
	printVector(b,'b');
	#endif

	do{
		for(i = 0; i < N; i++){
			x_old[i] = x_new[i];	
		}

		for(i = 0; i < N; i++){
			sum = 0;
			
			for(j = 0; j < N; j++){
				if(j != i)
					sum += (A[i][j]*x_new[j]);			// x_new statt x_old!
			}

			x_new[i] = 1/A[i][i] * (b[i] - sum);
		}

		matVecMult(A,x_new,Ax);
		vecSubtract(b, Ax, subt);
		//residuum = vecLength(subt);					// absolutes Residuum
		residuum = vecLength(subt)/vecLength(x_new);	// relatives Residuum
		count++;
		printf("residuum = %lf\n", residuum);

	}while(residuum > 0.0000001);

	#ifdef PRINT
	printVector(x_new,'x');
	#endif

	printf("How many iterations? %d\n", count);

	return 0;
}
