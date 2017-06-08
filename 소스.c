/* ������ȣ�а� 15011116 ��ȫ�� */
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

	if (argc != 3)	// ���ڰ� 3���� �ƴ� ��
		printf("incorrects number of arguments.\n");

	else if (strstr(argv[1], ".asm") == NULL)	// asm ������ �ƴ� �� ���� ���
		printf("wrong file type.\n");

	else
	{
		fopen_s(&asm, argv[1], "r");
		if (asm == NULL)	// file open�� ���� �ʾ��� �� ���� ��� �� ����
		{
			printf("asm file could not be opened.");
			exit(1);
		}

		fopen_s(&txt, argv[2], "w");
		if (txt == NULL)	// file open�� ���� �ʾ��� �� ���� ��� �� ����
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
			if (eof == NULL)	// ������ ���� ��� �ݺ����� ����
				break;
			else
			{
				print_assem(txt, &inst);
			}
			count++;
		}
		/* �Ǽ��ڵ� �߰� */
		fprintf(txt, "399\n");	// AC �������� 99������ ����
		fprintf(txt, "581\n");	// LDA 81
		fprintf(txt, "182\n");	// ADD 82
		fprintf(txt, "383\n");	// STA 83
		fprintf(txt, "599\n");	// LDA AC register value
		fprintf(txt, "604\n");	// ���� �ڵ�� ��ȯ
		/* �Ǽ��ڵ� �߰� */
		fclose(asm);
		fclose(txt);
	}
}