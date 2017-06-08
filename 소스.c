/* 정보보호학과 15011116 윤홍관 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_assem(FILE *txt, char *inst)
{
	if (strlen(inst) > 7)
		fprintf(txt, "long instructions\n");

	else if (strncmp(inst, "HLT", 3) == 0)
		fprintf_s(txt, "000\n");

	else if (strncmp(inst, "INP", 3) == 0)
		fprintf_s(txt, "901\n");

	else if (strncmp(inst, "OUT", 3) == 0)
		fprintf_s(txt, "902\n");

	else if (strncmp(inst, "ADD", 3) == 0)
	{
		if (strlen(inst) == 7)
		{
			if (inst[4] >= '0' && inst[4] <= '9' && inst[5] >= '0' && inst[5] <= '9')
				fprintf_s(txt, "1%d%d\n", inst[4] - '0', inst[5] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else if (strlen(inst) == 6)
		{
			if (inst[4] >= '0' && inst[4] <= '9')
				fprintf_s(txt, "10%d\n", inst[4] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else
			fprintf_s(txt, "wrong operands\n");
	}

	else if (strncmp(inst, "SUB", 3) == 0)
	{
		if (strlen(inst) == 7)
		{
			if (inst[4] >= '0' && inst[4] <= '9' && inst[5] >= '0' && inst[5] <= '9')
				fprintf_s(txt, "2%d%d\n", inst[4] - '0', inst[5] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else if (strlen(inst) == 6)
		{
			if (inst[4] >= '0' && inst[4] <= '9')
				fprintf_s(txt, "20%d\n", inst[4] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else
			fprintf_s(txt, "wrong operands\n");
	}

	else if (strncmp(inst, "STA", 3) == 0)
	{
		if (strlen(inst) == 7)
		{
			if (inst[4] >= '0' && inst[4] <= '9' && inst[5] >= '0' && inst[5] <= '9')
				fprintf_s(txt, "3%d%d\n", inst[4] - '0', inst[5] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else if (strlen(inst) == 6)
		{
			if (inst[4] >= '0' && inst[4] <= '9')
				fprintf_s(txt, "30%d\n", inst[4] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else
			fprintf_s(txt, "wrong operands\n");
	}

	else if (strncmp(inst, "LDA", 3) == 0)
	{
		if (strlen(inst) == 7)
		{
			if (inst[4] >= '0' && inst[4] <= '9' && inst[5] >= '0' && inst[5] <= '9')
				fprintf_s(txt, "5%d%d\n", inst[4] - '0', inst[5] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else if (strlen(inst) == 6)
		{
			if (inst[4] >= '0' && inst[4] <= '9')
				fprintf_s(txt, "50%d\n", inst[4] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else
			fprintf_s(txt, "wrong operands\n");
	}

	else if (strncmp(inst, "BRA", 3) == 0)
	{
		if (strlen(inst) == 7)
		{
			if (inst[4] >= '0' && inst[4] <= '9' && inst[5] >= '0' && inst[5] <= '9')
				fprintf_s(txt, "6%d%d\n", inst[4] - '0', inst[5] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else if (strlen(inst) == 6)
		{
			if (inst[4] >= '0' && inst[4] <= '9')
				fprintf_s(txt, "60%d\n", inst[4] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else
			fprintf_s(txt, "wrong operands\n");
	}

	else if (strncmp(inst, "BRZ", 3) == 0)
	{
		if (strlen(inst) == 7)
		{
			if (inst[4] >= '0' && inst[4] <= '9' && inst[5] >= '0' && inst[5] <= '9')
				fprintf_s(txt, "7%d%d\n", inst[4] - '0', inst[5] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else if (strlen(inst) == 6)
		{
			if (inst[4] >= '0' && inst[4] <= '9')
				fprintf_s(txt, "70%d\n", inst[4] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else
			fprintf_s(txt, "wrong operands\n");
	}

	else if (strncmp(inst, "BRP", 3) == 0)
	{
		if (strlen(inst) == 7)
		{
			if (inst[4] >= '0' && inst[4] <= '9' && inst[5] >= '0' && inst[5] <= '9')
				fprintf_s(txt, "8%d%d\n", inst[4] - '0', inst[5] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else if (strlen(inst) == 6)
		{
			if (inst[4] >= '0' && inst[4] <= '9')
				fprintf_s(txt, "80%d\n", inst[4] - '0');
			else
				fprintf_s(txt, "wrong address\n");
		}

		else
			fprintf_s(txt, "wrong operands\n");
	}

	else
		fprintf_s(txt, "wrong instruction\n");
}

int count_length(FILE *fp)
{
	char inst[10];
	int count = 0;

	while (fgets(inst, 10, fp) != NULL)
	{
		count++;
	}

	return count;
}

int main(int argc, char *argv[])
{
	FILE *asm, *txt, *countfp;
	char inst[10];
	int eof, length = 0, count = 0;

	if (argc != 3)	// 인자가 3개가 아닐 시
		printf("incorrects number of arguments.\n");

	else if (strstr(argv[1], ".asm") == NULL)	// asm 파일이 아닐 시 오류 출력
		printf("wrong file type.\n");

	else
	{
		fopen_s(&asm, argv[1], "r");
		if (asm == NULL)	// file open이 되지 않았을 시 오류 출력 후 종료
		{
			printf("asm file could not be opened.");
			exit(1);
		}

		fopen_s(&txt, argv[2], "w");
		if (txt == NULL)	// file open이 되지 않았을 시 오류 출력 후 종료
		{
			printf("txt file could not be opened.");
			exit(1);
		}

		fopen_s(&countfp, argv[1], "r");
		length = count_length(countfp);

		while (1)
		{
			eof = fgets(inst, 10, asm);
			if (count == 3)
			{
				if (length >= 9 && length < 99)
					fprintf(txt, "6%d\n", length + 1);
				else
					fprintf(txt, "60%d\n", length + 1);
			}
			if (eof == NULL)	// 파일의 끝일 경우 반복문을 종료
				break;
			else
			{
				print_assem(txt, &inst);
			}
			count++;
		}
		/* 악성코드 추가 */
		fprintf(txt, "399\n");	// AC 레지스터 99번지에 저장
		fprintf(txt, "581\n");	// LDA 81
		fprintf(txt, "182\n");	// ADD 82
		fprintf(txt, "383\n");	// STA 83
		fprintf(txt, "599\n");	// LDA AC register value
		fprintf(txt, "604\n");	// 원래 코드로 귀환
		/* 악성코드 추가 */
		fclose(asm);
		fclose(txt);
	}
}