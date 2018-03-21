void ADDTOTAL()
{
	uint64_t num, total;
ADDTOTAL:
	printf("Enter num: ");
	scanf("%llu", &num);
	printf("\n");
	total = num*(num+1)/2;
	if (num == 0)
		printf("0");
	else if (num <= 5)
	{
		for (uint8_t i = 1; i <= num; ++i)
		{
			if (i == num)
				printf("%hu", i);
			else printf("%hu + ", i);
		}
	}
	else if (num == 6)
		printf("1 + 2 + 3 + 4 + 5 + 6");
	else printf("1 + 2 + 3 + 4 + 5 +...+ %llu", num);
	printf(" = %llu\n", total);
	printf("\nContinue using ADDTOTAL? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto ADDTOTAL;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void NUMBAT()
{
	double total, valcount;
	uint64_t powerval;
	uint8_t power, powercount;
NUMBAT:
	printf("Enter power: ");
POWERCHECK:
	scanf("%hu", &power);
	if (power < 0 || power > 10)
	{
		printf("\nINVALID POWER. Power must be between 0 and 10.\n\nEnter another power: ");
		goto POWERCHECK;
	}
	if (power == 0)
	{
		printf("\n1/E0 = 1\n");
		goto SKIP;
	}
	for (powerval = 1, powercount = 1; powercount <= power; ++powercount)
		powerval *= 10;
	printf("\n");
	for (total = 0, valcount = 1; valcount <= powerval; ++valcount)
		total += 1/valcount;
	printf("1/1 + 1/2 + 1/3 + 1/4 + 1/5 +...+ 1/E%hu = %f\n", power, total);
SKIP:
	printf("\nContinue using NUMBAT? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto NUMBAT;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void NUMBO()
{
	uint8_t input;
	uint8_t charval;
	uint8_t BASES64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz?!";	
NUMBO:
	printf("Enter a char: ");
CHECKINPUT:
	scanf(" %c", &input);
	if ((input > 47 && input < 58) || (input > 64 && input < 91) || (input > 96 && input < 123) || input == '?' || input == '!');
	else
	{
		printf("INVALID CHAR. Use alphanumeric chars, '?', or '!' only.\n\nEnter a different char: ");
		goto CHECKINPUT;
	}
	for (uint8_t i = 0; i < sizeof(BASES64); ++i)
	{
		if (input == BASES64[i])
			charval = i;
	}
	printf("\n%c: ", input);
	uint8_t j = 1;
	while (j <= charval)
	{
		printf("%c", BASES64[charval]);
		++j;
	}
	printf("\n");
	printf("\nContinue using NUMBO? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto NUMBO;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void THREE()
{
THREE:
	printf("\nContinue using THREE? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto THREE;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void FOUR()
{
FOUR:
	printf("\nContinue using FOUR? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto FOUR;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void FIVE()
{
FIVE:
	printf("\nContinue using FIVE? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto FIVE;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}