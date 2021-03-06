/*------------------------------------------------------------------------
 *   write models/snapshots without PML boundary layer
 *   
 *   D. Koehn
 *   Kiel, 1st of July 2016 
 *  ----------------------------------------------------------------------*/

#include "fd.h"


void writemod_true(char modfile[STRING_SIZE], float ** array, int format){


	/* extern variables */
	extern int MYID, NX, NY, IDX, IDY, NX0, NY0, NPML, FSSHIFT;
	extern FILE *FP;

	int i, j;
	FILE *fpmod;
	char file[STRING_SIZE];

	sprintf(file,"%s",modfile);

	if(MYID==0){
	    printf("\n\n PE %d is writing model to \n",MYID);
	    printf("\t%s\n\n", file);
	}

	fpmod=fopen(file,"wb");
	for (i=1;i<=NX0;i+=IDX){
	    for (j=1;j<=NY0;j+=IDY){
		fwrite(&array[j+FSSHIFT][i+NPML],sizeof(float),1,fpmod);
	    }
        }
				
	fclose(fpmod);

}


