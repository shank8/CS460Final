/* cp.c */

#include "ucode.c"

int main(int argc, char * argv[0]) {
	
	int rfd, wfd;
	int nread, nwrite;
	int totalBytes = 0;
	char buf[512];

	if(argc < 3){
		printf("invalid usage: cp source dest");

	}else{

		rfd = open(argv[1], O_RDONLY);
		if(rfd < 0){
			printf("error opening read file\n");
			return -1;
		}

		wfd = open(argv[2], O_WRONLY | O_CREAT);
		if(wfd < 0){
			printf("error opening write file\n");
			return -1;
		}

		

		// Now we will just read 512 bytes at a time
		while(nread = read(rfd, buf, 512)){
			totalBytes += nread;
			nwrite = write(wfd, buf, nread);
		}
	
		close(rfd);
		close(wfd);

		printf("Copied %d bytes from %s to %s\n", totalBytes, argv[1], argv[2]);

	}
	return 0;
}