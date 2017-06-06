#include <iostream>  
#include <stdlib.h>  
#include "update_part.h"
using namespace std;

int update_part(int n, int** adj_mat, bool* part,int *change_index){
	int i,j,m;
	int gain = 0;
	int temp_gain;
	change_index[0] = 0;
	change_index[1] = 0;

	for (i = 0;i < (2*n);i++){ 
		for (j = (i+1);j < (2*n);j++){
			if (part[i] == part[j])
				continue;
			else {
			    temp_gain = 0;
			    for (m = 0;m < (2*n); m++){
				    if (part[i] == part[m])
					    temp_gain = temp_gain - adj_mat[i][m];
				    else
					    temp_gain = temp_gain + adj_mat[i][m];
			    }

			    for (m = 0;m < (2*n); m++){
				    if (part[j] == part[m])
					    temp_gain = temp_gain - adj_mat[j][m];
				    else
					    temp_gain = temp_gain + adj_mat[j][m];
			    }

				temp_gain = temp_gain - 2*adj_mat[i][j];

			    if (temp_gain >= gain){
				    change_index[0] = i;
				    change_index[1] = j;
				    gain = temp_gain;
			    }
			}
		}
	}

	part[(change_index[0])] = !part[(change_index[0])];
	part[(change_index[1])] = !part[(change_index[1])];

	return gain;
}