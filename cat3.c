/* cat.c */
#include "ucode.c"



int main(int argc, char * argv[]) {

	int fd, nread;
	char buf[128];
	int i = 0;


	if(argc > 1){

		fd = open(argv[1], O_RDONLY);

		if(fd > 0){
			
			while((nread = read(fd, buf,128)) > 0){
				i = 0;
				while(i < nread){
					putc(buf[i++]);
				}
				
			}

		}else{
			printf("bad file");
		}

	}else{

		// Just echo whatever is inputted
		while(1){
			gets(buf);
			printf("%s\n", buf);
		}
	}

	return 0;
}