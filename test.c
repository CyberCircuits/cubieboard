
//gpio testing in c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  //for sleep()


int main(){
	
	FILE * fp;
	int ch;
	int i = 0;
	char myfile[100];//make a buffer

	//open pins 1-3
	for (i = 1; i < 4; i++){

		sprintf(myfile, "/sys/class/gpio/gpio%d_pd%d/direction",i,i-1);  //create filename
		printf("activating pin %i\n",i);


		//export
		if((fp = fopen("/sys/class/gpio/export", "w")) == NULL){
			 printf("export %d not writeable",i);
			exit(-1);
		}

		fprintf(fp,"%d",i);
		fclose(fp);


		//set direction
		if((fp = fopen(myfile, "w")) == NULL){
			printf("Error on direction %d",i);
			exit(-1);
		};
		fprintf(fp,"in");
		fclose(fp);

	}	
	//check value

	while(1){

		for(i=1;i < 4 ; i++){
	
			sprintf(myfile, "/sys/class/gpio/gpio%d_pd%d/value",i,i-1);  //create filename

			fp = fopen(myfile, "r");
			ch = fgetc(fp);
			if(ch == '0'){
				//printf("0");
			}else{
				printf("\nPin #%d change detected",i);
			}
			fflush(stdout);
			sleep(1);

			fclose(fp);
		}
	}
	return 0;
}
