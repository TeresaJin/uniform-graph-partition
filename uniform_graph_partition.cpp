#include <fstream>
#include <iostream>  
#include <stdlib.h>  
#include <ctime>
#include "construct_mat.h"
#include "calc_cost.h"
#include "update_part.h"
#include "construct_part.h"
#include "combine.h"
using namespace std;

#define NUM 10

int main(){
	int n = NUM;
	int i,j;
	int cost;
	srand(time(NULL));

	int **matrix;
	matrix = new int*[2*n];
	for (i = 0;i < 2*n;i++){   
		matrix[i] = new int[2*n]; } 

	bool *partition;
	partition = new bool[2*n];
	for (i = 0;i < 2*n; i++){
		if (i < n)
			partition[i] = 0;
		else
			partition[i] = 1;
	}
	
	int *change_index;
	change_index = new int[2];

	ofstream fout;
	fout.open("output.txt");

	construct_mat(n,matrix);

	cost = calc_cost(n,matrix,partition);

	fout << "Here is the matrix: "<<endl;
	for (i = 0;i < (2*n);i++){ 
		for (j = 0;j < (2*n);j++){
			fout<<matrix[i][j]<<"	";}
		fout<<endl;
	}
	fout <<"The value of cost function is:"<<cost<<endl;

	while (true){
		cost = cost - update_part(n,matrix,partition,change_index);
		if (change_index[0] == change_index[1])
			break;
	}
	fout <<endl;
	fout <<"Here is the partion: "<<endl;
	fout <<"Vertices in subset 0:"<<endl;
	for (i = 0;i < (2*n);i++){ 
		if (partition[i] == 0)
			fout<<i<<"\n";}
	fout<<endl;
	fout <<"Vertices in subset 1:"<<endl;
	for (i = 0;i < (2*n);i++){ 
		if (partition[i] == 1)
			fout<<i<<"\n";}
	fout <<"The value of cost function is:"<<cost<<endl;
	fout <<endl;

	//Here is the method of exhaustive search

	int cost_best = cost;
	bool *partition_best;
	partition_best = new bool[2*n];
	for (i = 0;i < 2*n; i++){
		partition_best[i] = partition[i];
	}

	int num[NUM];
	ifstream in;
	in.open("permutation.txt");
	if (!in.is_open())  
	{ cout << "Error opening file"; exit (1); }

	while (!in.eof()){
		for (i = 0;i < 2*n; i++){
			partition[i] = 0;
		}
		for (i=0;i<n;i++){
			in>>num[i];
			partition[num[i]] = 1;
		}
		cost = calc_cost(n,matrix,partition);
		if (cost < cost_best){
			cost_best = cost;
			for (i = 0;i < 2*n; i++){
				partition_best[i] = partition[i];
			}
		}
	}

	fout <<"Result of exhaustive method:"<<endl;
	fout <<"Here is the partion: "<<endl;
	fout <<"Vertices in subset 0:"<<endl;
	for (i = 0;i < (2*n);i++){ 
		if (partition_best[i] == 0)
			fout<<i<<"\n";}
	fout<<endl;
	fout <<"Vertices in subset 1:"<<endl;
	for (i = 0;i < (2*n);i++){ 
		if (partition_best[i] == 1)
			fout<<i<<"\n";}
	fout<<endl;
	fout <<"The value of cost function is:"<<cost_best<<endl;

	delete []partition_best;
	//End of the method of exhaustive search

	fout.close();

	delete []partition;

	for (i=0; i < n; i++){
		delete [] matrix[i];}
	delete [] matrix;

	delete [] change_index;

	return 0;
}