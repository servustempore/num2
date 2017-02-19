/***********************************************************
Jacobi-Iterationsverfahren
- Jede Komponente des Lösungsvektors x_new wird für sich
  ohne Berücksichtigung der vorangegangen berechneten 
  Komponenten berechnet
***********************************************************/

#include <stdio.h>
#include <my_functions.h>

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
