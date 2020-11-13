#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

 
int main()
{
	time_t start_time, end_time;
	float result;
	char msg[3][30] = {"Hello World", "My name is Kyubin", "How are you?"};
	char input[3][30] = {0};
	system("clear");
	int i = 0, j = 0, msg_len = 0, input_len = 0, longer_len = 0, total = 0, chk = 0;
	
	start_time = time(NULL);
	for(i=0; i<3; i++){
		puts(msg[i]);
		scanf("%[^\n]s", input[i]);
		msg_len = strlen(msg[i]);
		input_len = strlen(input[i]);
		printf("original text number : %d, input text number : %d\n", msg_len, input_len);
		total += input_len;

		if(msg_len > input_len) 
			longer_len = msg_len;
		else if(msg_len <= input_len)
			longer_len = input_len;
	
		for(j=0; j< longer_len; j++){
			if(msg[i][j] != input[i][j])
				chk++;
		}
		printf("wrong number : %d\n", chk);
		if(total > chk)
			total -= chk;
		else 
			total = 0;

		chk = 0;
		printf("\n\n");
		getchar();
	}
	end_time = time(NULL);
	result = (float)(end_time - start_time);
	printf("result = %f\n", result);
	printf("total = %d\n", total);
	printf("평균 %.2f초 걸림\n", result/3);
	printf("분당 타자수는 %.2f타\n", total/(result/60));
}
