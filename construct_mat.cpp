#include <iostream>  
#include <stdlib.h>  
#include <ctime>
#include "construct_mat.h"
using namespace std;
#define RANGE 100

bool construct_mat(int n, int** adj_mat){
	int i,j;
	for (i = 0;i < (2*n-1);i++){ 
		for (j = (i+1);j < (2*n);j++){
				adj_mat[i][j] = (rand()%RANGE+1); 
		}
	}
	for (i = 0;i < (2*n);i++){ 
		for (j = 0;j <= i;j++){
			if (j == i)
				adj_mat[i][j] = 0;
			else
				adj_mat[i][j] = adj_mat[j][i];
		}
	}
			
	return true;
}