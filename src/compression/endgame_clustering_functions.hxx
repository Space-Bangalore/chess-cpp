#ifndef _ENDGAME_CLUSTER_FUNCTIONS_
#define _ENDGAME_CLUSTER_FUNCTIONS_

// board.hxx contains definitions of DB_WPAWN_VALUE, etc.
#include "../board.hxx"

#if MAX_MEN == 5
typedef int (*ClusterFunction)(int,int,int,int,int);
#elif MAX_MEN == 4
typedef int (*ClusterFunction)(int,int,int,int);
#else
#error
#endif

void init_cluster_functions();

extern ClusterFunction cluster_functions[DB_ARRAY_LENGTH];
extern int cluster_functions_num_values[DB_ARRAY_LENGTH];

#endif
