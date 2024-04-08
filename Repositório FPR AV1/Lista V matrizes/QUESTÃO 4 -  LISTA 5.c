/*
QUEST�O 04:
Fazer uma fun��o que, dada uma matriz M6�6,
determine se ela � sim�trica.
*/
#include <stdio.h>

int verificarSimeria( int n, int m[n][n] ){
	
	int i, j;
	
	for (i = 0; i < n; i++){
		
		for(j = 0; j < n; j++){
			
			if(m[i][j] != m[j][i]){
				return 0;
			}
		}
	}
	
	return 1;
}
