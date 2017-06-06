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
#define MAX_TRY 10000

int main(){
	int n = NUM; //Number of nodes in one partitiopn;Total nodes=2*n
	int i,j;
	int cost;
	int max_try = 1;
	srand(time(NULL));

	int **matrix; //Weighted adjacent matrix
	matrix = new int*[2*n];
	for (i = 0;i < 2*n;i++){   
		matrix[i] = new int[2*n]; } 

	bool *partition; //Partition of nodes,belong to partition0 or partition1
	partition = new bool[2*n];
	//Initailly, the partition is "randomly" choosed.
	for (i = 0;i < n; i++){
		partition [2*i] =rand()%2;
		partition [2*i+1] = !partition [2*i];
	}
	
	//The beighborhood is the set of all partitions that can be obtained by the original set by exchange a pair of vertex.
	int *change_index; 
	change_index = new int[2];

	int *random_index;
	random_index = new int[2];

	ofstream fout;
	fout.open("output.txt");

	construct_mat(n,matrix); //Randomly constract a graph, weights of the edges range from 1 to 100.

	cost = calc_cost(n,matrix,partition); //Calculation the cost function of the initial partition.

	fout << "Here is the matrix: "<<endl;
	for (i = 0;i < (2*n);i++){ 
		for (j = 0;j < (2*n);j++){
			fout<<matrix[i][j]<<"	";}
		fout<<endl;
	}
	fout <<"The value of cost function is:"<<cost<<endl;

	//Do the neighborhood search
	while (true){
		cost = cost - update_part(n,matrix,partition,change_index);
		if (change_index[0] == change_index[1]){ //The result is already the optimal in the neighborhood
			if (max_try == MAX_TRY)
				break;
			else{  //And some randomization in the partition in order to escape from local optimum
				
				for (i=0; i< 500;i++)
				{
					random_index[0] = rand()%(2*n);
					random_index[1] = rand()%(2*n);
					while (random_index[0] == random_index[1])
						random_index[1] = rand()%(2*n);
					bool tmp;
					tmp = partition[random_index[0]];
					partition[random_index[0]] = partition[random_index[1]];
					partition[random_index[1]] = tmp;	
				}
				max_try+=1;
				cost = calc_cost(n,matrix,partition);
			}
		}
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
	
	//Here is the method of exhaustive search,only apply for NUM=10

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

	//delete []partition;

	for (i=0; i < 2*n; i++){
		delete [] matrix[i];}
	delete [] matrix;

	delete [] change_index;
	delete [] random_index;
	
	return 0;
}
