#include <iostream>  
#include <stdlib.h>  
#include "calc_cost.h"
using namespace std;

int calc_cost(int n, int** adj_mat, bool* part){
	int i,j;
	int cost = 0;
	for (i = 0;i < (2*n);i++){ 
		for (j = (i+1);j < (2*n);j++){
			if (part[j] != part[i]){
				cost = cost + adj_mat[i][j];
			}
		}
	}

	return cost;
}