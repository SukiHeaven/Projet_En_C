#include <stdio.h>
#include <string.h>
#include "atlacan.h"


bool Clayton(int uid){

	return uid & UID_CLAYTON;
}

bool Pertontan ( int gid){

	return gid & GID_PERTONTAN;
}


const char* test2(const char* path, int data_prec,int current, int * passage){

	if (strcmp(path,"camp")>0){ atl_cd(path);}
	else if (strcmp(path,"..")==0 ){atl_cd("..");}

	char ** paths;
	int i,num,data,comp_dossier;
	comp_dossier=0;
	struct atl_stat STAT;

	printf("mon dossier actuel = %s\n", atl_getpwd() );

	atl_ls(&paths,&num); 
	char * dossier[num];

	for (i=0 ; i<num ; i++){

		printf(" -le nom %s\n",paths[i] );

		atl_stat(paths[i],&STAT);

		if (atl_is_link(STAT.mode)){
			printf("  c'est un lien\n");
		}

		else if (atl_is_dir(STAT.mode)){
			printf("  c'est un dossier\n");
			if(!Clayton(STAT.uid)){
				dossier[comp_dossier] = paths[i];
				comp_dossier++;
			}
			else printf ("   c'est Clayton le fourbe!!!\n");
		}

		else if (atl_is_file(STAT.mode))	{
			printf("  c'est un fichier\n");
			if (Pertontan(STAT.gid)){
					printf("  pertontan les menteurs ! \n");
			}
			else{
				atl_cat(paths[i],&data);
				printf("   indice %d\n", data );
			}		
			
		}
		printf("\n");	
	}

	if (data_prec != data){passage[current]=0;}

	else passage[current]++;

	const char* path_join;

	if (comp_dossier!=0 && data<=data_prec){
		path_join = dossier[passage[current]];
		return test2(path_join,data,current+1,passage);
	}
	else{
		printf("c'était pas le bon chemin\n");
		path_join="..";
		return test2(path_join,data_prec,current-1,passage);
	}

}


int main(int argc, char const *argv[])
{	

	atl_init();

	int * passage;
	int current;

	current = 0;
	passage[current]=0;


	const char * path;
	path = atl_getpwd();

	test2(path,10000000,current,passage);


	atl_fini();
	printf("fin\n");
	return 0;
}