uint8_t getdivisors(uint32_t**, uint32_t*, uint32_t, uint16_t, uint8_t, uint8_t);
void FACTOR() //prime factorization, list divisors
{
	uint32_t num;
FACTOR:
	printf("Enter a number: ");
CHECKNUM:
	scanf("%du", &num);
	if (num < 0)
	{
		printf("\nINVALID NUMBER. Number must be non-negative.\n\nEnter another number: ");
		goto CHECKNUM;
	}
	/*else if (num > 516667634)
	{
		printf("\nINVALID NUMBER. Number must be less than 516667634.\n\nEnter a smaller number: ");
		goto CHECKNUM;	
	}*/
	else if (num == 0)
	{
		printf("\n0 is neither prime nor composite, has no factors, and no divisors.\n");
		goto SKIP;
	}
	else if (num == 1)
	{
		printf("\n1 is neither prime nor composite and has 1 divisor.\nFACTORIZATION: 1\nDIVISORS: 1\n");
		goto SKIP;
	}
	else if (num == 2)
	{
		printf("\n2 is prime and has 2 divisors.\nFACTORIZATION: 2^1\nDIVISORS: 1 2\n");
		goto SKIP;
	}
	uint16_t primeval = sqrt((double)num)/2 + 2; //why +2? because +1 for the ceiling and +1 for extra zero buffer in getdivisors
	uint16_t powernum = sqrt((double)num) + 2; //why +2? because sqrt(2^n) < n+1 from [2,5] and since n=3 needs 2 more (1 more than the rest)
	if (num%2 == 0) //check two to see if composite
		goto COMPOSITE;
	for (uint32_t checkcomp = 3; checkcomp <= num; checkcomp += 2) //check all odds to see if composite
	{
		if (num%checkcomp == 0) //found a number divisible by checkcomp
		{
			if (num/checkcomp != 1) //is the number not checkcomp? then it must be composite
				goto COMPOSITE;
			else
			{
				printf("\n%d is prime and has 2 divisors.\nPRIME FACTORIZATION: %d^1\nDIVISORS: 1 %d\n", num, num, num);
				goto SKIP;
			}
		}
	}
COMPOSITE:
	uint32_t val = num;
	uint32_t **FACT = new uint32_t *[primeval];
	for (uint16_t dw0 = 0; dw0 < primeval; ++us0)
		FACT[us0] = new uint32_t[powernum];
	uint16_t dw1, dwj1;
	for (us1 = 0; dw1 < primeval; ++us1) //write all zeroes to array
	{
		for (usj1 = 0; dwj1 < powernum; ++usj1)
			FACT[us1][usj1] = 0;
	}
	uint32_t p;
	uint8_t db2, dbj2;
	for (db2 = 0, dbj2 = 0, p = 2; p != 3;) //checks if 2 is a factor so we can skip evens after
	{
		if (val%p == 0)
		{
			FACT[db2][dbj2] = p;
			val /= p;
			++dbj2;
		}
		else if (num%2 == 0)
		{
			++db2;
			++dbj2 = 0;
			p = 3;
		}
		else p = 3;
	}
	while (val != 1) //skips evens after 2
	{
		if (val%p == 0)
		{
			FACT[db2][dbj2] = p;
			val /= p;
			++dbj2;
		}
		else if (FACT[db2][0] == 0) //if first slot is empty
			p += 2;
		else
		{
			++db2;
			dbj2 = 0;
			p += 2;
		}
	}
	uint16_t dw3;
	uint8_t dbj3, power;
	for (us3 = 0, dbj3 = 0, power = 0; dw3 < primeval;) //places power at end of numbers in array (not at actual end)
	{
		if (FACT[us3][dbj3] != 0)
		{
			++power;
			++dbj3;
		}
		else if (dbj3 != 0 && FACT[us3][dbj3] < FACT[us3][dbj3-1]) //same here
		{
			FACT[us3][dbj3] = power;
			++us3;
			dbj3 = 0;
			power = 0;
		}
		else dw3++;
	}	
	uint8_t numdivisors;
	uint16_t dw4;
	uint8_t dbj4;
	for (us4 = 0, dbj4 = 0, numdivisors = 1; dw4 < primeval;) //find number of divisors
	{
		if (FACT[us4][0] < 0)
			++us4;
		else 
		{
			while (FACT[us4][dbj4+1] > 0)
				++dbj4;
			numdivisors *= (FACT[us4][dbj4]+1);
			++us4;
			dbj4 = 0;
		}
	}
	uint32_t *divisors;
	divisors = new uint32_t [numdivisors];
	getdivisors(FACT, divisors, 1, 0, 0, 0);
	uint32_t min, temp;
	uint8_t db5, dbj5, index;
	bool minfound = false;
	for (db5 = 1; db5 < numdivisors - 1; ++db5) //sort divisors
	{
		min = divisors[db5];
		for (dbj5 = db5 + 1; dbj5 < numdivisors - 1; ++dbj5)
		{
			if (divisors[dbj5] < min)
			{
				min = divisors[dbj5];
				index = dbj5;
				minfound = true;
			}
		}
		if (minfound == true)
		{
			temp = divisors[db5];
			divisors[db5] = min;
			divisors[index] = temp;
			minfound = false;
		}
	}
	printf("\n%d is composite and has %hu divisors.\nPRIME FACTORIZATION:", num, numdivisors);
	uint16_t dw6;
	uint8_t dbj6;
	for (us6 = 0, dbj6 = 0; dw6 < primeval;) //write factorization to screen
	{
		if (FACT[us6][0] > 0)
		{
			printf(" %d", FACT[us6][0]);
			while (FACT[us6][dbj6+1] > 0)
				++dbj6;
			printf("^%d", FACT[us6][dbj6]);
			++us6;
			dbj6 = 0;
		}
		else
		{
			++us6;
			dbj6 = 0;
		}
	}
	printf("\nDIVISORS:");
	if (numdivisors < 16) //write divisors
	{
		for (uint8_t db7 = 0; db7 < numdivisors; ++db7)
			printf(" %d", divisors[db7]);
		printf("\n");
	}
	else //better print to see all divisors
	{
		printf(" ");
		uint8_t count = 1;
		for (uint8_t db7 = 0; db7 < numdivisors; ++db7)
		{
			printf("%d ", divisors[db7]);
			if (count%8 == 0)
				printf("\n");
			++count;
		}
	}
	for (uint16_t dw8 = 0; dw8 != primeval; ++us8)
		delete[] FACT[us8];
	delete[] FACT, divisors;
SKIP:
	printf("\nContinue using FACTOR? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto FACTOR;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}
uint8_t getdivisors(uint32_t **FACT, uint32_t *divisors, uint32_t value, uint16_t dw, uint8_t dbj, uint8_t k)
{
	uint32_t powval = 1;
	uint32_t temp = value;
	bool ranfunction = false;
	while (FACT[us][dbj+1] > 0) //get power
		++dbj;
	uint8_t power = 0;
	uint8_t calcpow = 1;
	uint8_t maxpower = FACT[us][dbj];
	dbj = 0;
	while (power <= maxpower)
	{
		if (power == 0)//skip the zero
			++power;	
		else
		{
			while (calcpow <= power) //power funct
			{
				powval *= FACT[us][0];
				++calcpow;
			}
			++power;
		}
		value = temp * powval;
		if (FACT[us+1][0] > 0)	//recursive part and extra zero buffer from above is needed here
		{
			k = getdivisors(FACT, divisors, value, dw+1, 0, k);
			ranfunction = true;
		}
		if (ranfunction == false) //if it went into function, we dont want it to set a val for divisors yet
		{
			divisors[k] = value;
			++k;
		}
	}
	return k;
}



void _1729()
{
_1729:
	printf("\nContinue using 1729? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto _1729;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void ROMAN()
{
	uint8_t NUMERALS[] = "IVXLCDM";
ROMAN:
	printf("\nContinue using ROMAN? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto ROMAN;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}