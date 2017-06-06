# uniform-graph-partition

Instance: a complete graph on 2n vertices.
          a cost function costE->Z+∪{0} 
* In this program, cost function is between 1 to 100. It is also easy to change it if you like.

Find: the minimum value of c([X0,X1])=Sigma(cost(u,v)),{u,v}∈E,u∈X0,v∈X1,subject to V=X0∪X1 and |X0|=|X1|=n.

This program applys a heuristic search.
The beighborhood is the set of all partitions that can be obtained by the original set by exchange a pair of vertex.
It also use techniques to make slight changes in the partition in order to escape from local optimum.(Although it may not work well.)

To show the effectiveness of heuristic search, the program also do an exhaustive search to find the optimal solution and compare with the solution found by heuristic search.

Code:
uniform_graph_partition.cpp or uniform_graph_partition_2.cpp (main function)
construct_mat.cpp
construct_mat.h
update_part.cpp
update_part.h
calc_cost.cpp
calc_cost.h
permutation.txt (This is used in exhaustive search. It provides all possible partitions of 2n nodes.)

To generate permutation.txt, you need code:
combine.cpp

You can change NUM to see the result with different nodes.
NOTE that when you define NUM as n, there are actually 2n nodes in the graph.

You can change MAX_TRY, this makes it longer to run the program, but may possibly get a better result.

Example output:
Here is the matrix: 
0	30	99	15	65	78	74	33	55	82	24	47	9	70	99	49	8	52	24	96	
30	0	23	30	99	85	71	66	13	48	90	14	52	93	11	37	71	38	35	41	
99	23	0	31	15	78	83	29	89	21	15	24	25	94	37	61	40	13	64	74	
15	30	31	0	86	38	93	64	84	31	16	52	85	19	9	3	46	67	33	21	
65	99	15	86	0	14	28	69	47	82	5	12	37	56	30	25	51	21	25	12	
78	85	78	38	14	0	37	5	41	42	68	15	84	73	71	70	49	92	68	74	
74	71	83	93	28	37	0	73	6	35	46	45	74	72	78	61	44	40	55	8	
33	66	29	64	69	5	73	0	90	24	62	44	45	65	5	19	84	59	33	41	
55	13	89	84	47	41	6	90	0	69	80	85	76	88	92	70	46	85	39	20	
82	48	21	31	82	42	35	24	69	0	2	81	78	67	6	95	10	22	18	22	
24	90	15	16	5	68	46	62	80	2	0	37	96	65	67	2	71	4	13	91	
47	14	24	52	12	15	45	44	85	81	37	0	65	39	89	57	61	100	11	87	
9	52	25	85	37	84	74	45	76	78	96	65	0	19	85	88	59	100	94	86	
70	93	94	19	56	73	72	65	88	67	65	39	19	0	98	20	62	81	90	80	
99	11	37	9	30	71	78	5	92	6	67	89	85	98	0	10	63	93	94	28	
49	37	61	3	25	70	61	19	70	95	2	57	88	20	10	0	82	100	46	28	
8	71	40	46	51	49	44	84	46	10	71	61	59	62	63	82	0	68	5	16	
52	38	13	67	21	92	40	59	85	22	4	100	100	81	93	100	68	0	25	79	
24	35	64	33	25	68	55	33	39	18	13	11	94	90	94	46	5	25	0	48	
96	41	74	21	12	74	8	41	20	22	91	87	86	80	28	28	16	79	48	0	
The value of cost function is:5358

Here is the partion: 
Vertices in subset 0:
0
1
2
5
6
10
13
14
18
19

Vertices in subset 1:
3
4
7
8
9
11
12
15
16
17
The value of cost function is:4294

Result of exhaustive method:
Here is the partion: 
Vertices in subset 0:
0
1
2
5
6
10
13
14
18
19

Vertices in subset 1:
3
4
7
8
9
11
12
15
16
17

The value of cost function is:4294
