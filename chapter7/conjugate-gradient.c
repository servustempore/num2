
#include "my_functions.h"

double 	A[N][N];
double 	b[N], x_old[N] = {0}, x_new[N],
 		Ax[N], Ap[N], r_old[N], r_new[N],
 		p_old[N], p_new[N], alpha_p[N], beta_p[N];

int main(void){
	double alpha, beta, residuum;
	double dot_product_r_old;
	int count = 0;

	initCG(A,b);

	/*
	#ifdef PRINT
	printMatrix(A);
	printVector(b, 'b');
	#endif
	*/
	matVecMult(A, x_old, Ax);
	vecSubtract(b, Ax, r_old);
	copyVec(r_old, p_old);

	do{
		dot_product_r_old = dotProduct(r_old,r_old);
		matVecMult(A, p_old, Ap);
		alpha = dot_product_r_old/dotProduct(p_old,Ap); 	// alpha(i-1)

		scalarMult(alpha, p_old, alpha_p);
		vecAdd(x_old, alpha_p, x_new);						// x(i)

		scalarMult(alpha, Ap, alpha_p);
		vecSubtract(r_old, alpha_p, r_new);					// r(i)

		beta = dotProduct(r_new,r_new)/dot_product_r_old;	// beta(i)

		scalarMult(beta, p_old, beta_p);
		vecAdd(r_new, beta_p, p_new);						// p(i)

		copyVec(x_new, x_old);
		copyVec(r_new, r_old);
		copyVec(p_new, p_old);

		residuum = vecLength(r_new)/vecLength(x_new);
		count++;
	}while(residuum > 0.000000001);

	#ifdef PRINT
	printVector(x_new,'x');
	#endif

	printf("How many iterations? %d\n", count);

	return 0;
}