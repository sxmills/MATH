void SIX()
{
SIX:
	printf("\nContinue using SIX? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto SIX;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void CIRCLE() //circle, ellipse, cone, cylinder, sphere, ellipsoid, torus
{
CIRCLE:
	printf("\nContinue using CIRCLE? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto CIRCLE;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void BASE()
{
	uint8_t INBASE, OUTBASE, INTMAX;
	uint8_t NUMBER[256];
	uint8_t BASES[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
BASE:
	uint8_t CHARMAX = '0';
	printf("Enter a number: ");
CHECKCHAR:
	scanf("%s", NUMBER);
	printf("\n");
	uint8_t PLACE = 0;
	uint8_t ind0 = 0;
	while (NUMBER[ind0] != NULL)
	{
		++PLACE;
		++ind0;
	}
	for (uint8_t db0 = 0; db0 < PLACE; ++db0) //convert all chars to uppercase for easy processing
	{
		if (NUMBER[db0] > 96 && NUMBER[db0] < 123)
			NUMBER[db0] -= 32;
	}
	for (uint8_t db1 = 0; db1 < PLACE;) //error checking for non alphanumeric characters
	{
		
		if ((NUMBER[db1] > 47 && NUMBER[db1] < 58) || (NUMBER[db1] > 64 && NUMBER[db1] < 91) || (NUMBER[db1] > 96 && NUMBER[db1] < 123))
			++db1;
		else
		{
			printf("INVALID CHAR. Use alphanumeric chars only.\n\nEnter a different number: ");
			goto CHECKCHAR;
		}
	}
	for (uint8_t db2 = 0; db2 < PLACE; ++db2) //gets maximum char value
	{
		if (NUMBER[db2] > CHARMAX)
			CHARMAX = NUMBER[db2];
	}
	for (uint8_t db3 = 0; db3 < 36; ++db3) //convert charmax to an int for checkbase
	{
		if (CHARMAX == BASES[db3])
			INTMAX = db3;
	}
	if (INTMAX == 35) //help user choose base
		printf("What base is that number in?\nFor your number, it must be base 36.\n\nEnter input base here: ");
	else printf("What base is that number in?\nFor your number, you can only use bases %hu through 36.\n\nEnter input base here: ", INTMAX+1);
CHECKINBASE:
	scanf("%hu", &INBASE);
	printf("\n");
	if (INBASE < 2 || INBASE > 36)
	{
		printf("INVALID BASE. Base must be between 2 and 36.\n\nEnter a different base: ");
		goto CHECKINBASE;
	}	
	else if (INTMAX >= INBASE) //error checking for impossible bases
	{
		printf("INVALID BASE. Base must be greater than maximum char value.\n\nEnter a different base: ");
		goto CHECKINBASE;
	}
	printf("Enter output base to convert to: ");
CHECKOUTBASE:
	scanf("%hu", &OUTBASE);
	printf("\n");
	if (OUTBASE < 2 || OUTBASE > 36)
	{
		printf("INVALID BASE. Base must be between 2 and 36.\n\nEnter a different base: ");
		goto CHECKOUTBASE;
	}
	uint64_t TOTAL = 0;
	uint8_t VALUE = 0;
	uint8_t POWER = 0;
	for (int8_t db4 = 0; db4 < 36, PLACE > 0; ++db4) //total weight in base 10
	{
		if (NUMBER[PLACE-1] == BASES[db4])
		{
			VALUE = db4;
			TOTAL += VALUE*pow((double)INBASE, POWER);
			--PLACE;
			++POWER;
			db4 = -1;
		}
	}
	uint64_t DIVIDEND = TOTAL;
	uint64_t QUOTIENT;
	uint16_t REMAINDER;
	uint8_t size = log((double)TOTAL)/log((double)OUTBASE)+1; //# of output chars = greatest integer value of(ln(TOTAL)/ln(OUTBASE)+1)
	uint8_t whichchar;
	uint8_t *CHARARRAY;
	CHARARRAY = new uint8_t[size];
	uint8_t db5 = 0;
	while (DIVIDEND > 0) //division algorithm
	{
		QUOTIENT = DIVIDEND/OUTBASE;
		REMAINDER = DIVIDEND%OUTBASE;
		for (uint8_t db6 = 0; db6 < 36; ++db6)
		{
			if (REMAINDER == db6)
				whichchar = BASES[db6];
		}
		CHARARRAY[db5] = whichchar;
		DIVIDEND = QUOTIENT;
		++db5;
	}
	uint8_t *SOLUTION;
	SOLUTION = new uint8_t[size];
	uint8_t solindex = 0; 
	uint8_t CHARARRAYlen = 0;
	uint8_t ind1 = 0;
	while (CHARARRAY[ind1] != NULL)
	{
		++CHARARRAYlen;
		++ind1;
	}
	while (CHARARRAYlen > 0) //write chars from chararray backwars to solution
	{
		SOLUTION[solindex] = CHARARRAY[CHARARRAYlen-1];
		++solindex;
		--CHARARRAYlen;
	}
	printf("%s BASE %hu\n\n", NUMBER, INBASE);
	for (uint8_t ind2 = 0; ind2 < solindex; ++ind2)
	{
		if ((SOLUTION[ind2] > 47 && SOLUTION[ind2] < 58) || (SOLUTION[ind2] > 64 && SOLUTION[ind2] < 91))
			printf("%c", SOLUTION[ind2]);
	}
	printf(" BASE %hu\n", OUTBASE);
	printf("\nContinue using BASE? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto BASE;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void BASE64()
{
	uint8_t INBASE, OUTBASE, INTMAX;
	uint8_t NUMBER[256];
	uint8_t BASES64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz?!";
BASE64:
	uint8_t CHARMAX = '0';
	printf("Enter a number: ");
CHECKCHAR:
	scanf("%s", NUMBER);
	printf("\n");
	uint8_t PLACE = 0;
	uint8_t ind0 = 0;
	while (NUMBER[ind0] != NULL)
	{
		++PLACE;
		++ind0;
	}
	for (uint8_t db1 = 0; db1 < PLACE;) //error checking for non alphanumeric characters
	{
		
		if ((NUMBER[db1] > 47 && NUMBER[db1] < 58) || (NUMBER[db1] > 64 && NUMBER[db1] < 91) || (NUMBER[db1] > 96 && NUMBER[db1] < 123) || NUMBER[db1] == '?' || NUMBER[db1] == '!')
			++db1;
		else
		{
			printf("INVALID CHAR. Use alphanumeric chars, '?', or '!' only.\n\nEnter a different number: ");
			goto CHECKCHAR;
		}
	}
	for (uint8_t db2 = 0; db2 < PLACE; ++db2) //gets maximum char value
	{
		if (NUMBER[db2] == '!')
		{
			CHARMAX = '!';
			goto SKIPCHARMAX;
		}
		else
		{
			if (CHARMAX == '?');
			else
			{
				if (NUMBER[db2] == '?')
					CHARMAX = '?';
				else if (NUMBER[db2] > CHARMAX)
					CHARMAX = NUMBER[db2];
			}
		}
	}
SKIPCHARMAX:
	for (uint8_t db3 = 0; db3 < 64; ++db3) //convert charmax to an int for checkbase
	{
		if (CHARMAX == BASES64[db3])
			INTMAX = db3;
	}
	if (INTMAX == 63) //help user choose base
		printf("What base is that number in?\nFor your number, it must be base 64.\n\nEnter input base here: ");
	else printf("What base is that number in?\nFor your number, you can only use bases %hu through 64.\n\nEnter input base here: ", INTMAX+1);
CHECKINBASE:
	scanf("%hu", &INBASE);
	printf("\n");
	if (INBASE < 2 || INBASE > 64)
	{
		printf("INVALID BASE. Base must be between 2 and 64.\n\nEnter a different base: ");
		goto CHECKINBASE;
	}	
	else if (INTMAX >= INBASE) //error checking for impossible bases
	{
		printf("INVALID BASE. Base must be greater than maximum char value.\n\nEnter a different base: ");
		goto CHECKINBASE;
	}
	printf("Enter output base to convert to: ");
CHECKOUTBASE:
	scanf("%hu", &OUTBASE);
	printf("\n");
	if (OUTBASE < 2 || OUTBASE > 64)
	{
		printf("INVALID BASE. Base must be between 2 and 64.\n\nEnter a different base: ");
		goto CHECKOUTBASE;
	}
	uint64_t TOTAL = 0;
	uint8_t VALUE = 0;
	uint8_t POWER = 0;
	for (int8_t db4 = 0; db4 < 64, PLACE > 0; ++db4) //total weight in base 10
	{
		if (NUMBER[PLACE-1] == BASES64[db4])
		{
			VALUE = db4;
			TOTAL += VALUE*pow((double)INBASE, POWER);
			--PLACE;
			++POWER;
			db4 = -1;
		}
	}
	uint64_t DIVIDEND = TOTAL;
	uint64_t QUOTIENT;
	uint16_t REMAINDER;
	uint8_t size = log((double)TOTAL)/log((double)OUTBASE)+1; //# of output chars = greatest integer value of(ln(TOTAL)/ln(OUTBASE)+1)
	uint8_t whichchar;
	uint8_t *CHARARRAY;
	CHARARRAY = new uint8_t[size];
	uint8_t db5 = 0;
	while (DIVIDEND > 0) //division algorithm
	{
		QUOTIENT = DIVIDEND/OUTBASE;
		REMAINDER = DIVIDEND%OUTBASE;
		for (uint8_t db6 = 0; db6 < 64; ++db6)
		{
			if (REMAINDER == db6)
				whichchar = BASES64[db6];
		}
		CHARARRAY[db5] = whichchar;
		DIVIDEND = QUOTIENT;
		++db5;
	}
	uint8_t *SOLUTION;
	SOLUTION = new uint8_t[size];
	uint8_t solindex = 0; 
	uint8_t CHARARRAYlen = 0;
	uint8_t ind1 = 0;
	while (CHARARRAY[ind1] != NULL)
	{
		++CHARARRAYlen;
		++ind1;
	}
	while (CHARARRAYlen > 0) //write chars from chararray backwars to solution
	{
		SOLUTION[solindex] = CHARARRAY[CHARARRAYlen-1];
		++solindex;
		--CHARARRAYlen;
	}
	printf("%s BASE %hu\n\n", NUMBER, INBASE);
	for (uint8_t ind2 = 0; ind2 < solindex; ++ind2)
	{
		if ((SOLUTION[ind2] > 47 && SOLUTION[ind2] < 58) || (SOLUTION[ind2] > 64 && SOLUTION[ind2] < 91) || (SOLUTION[ind2] > 96 && SOLUTION[ind2] < 123))
			printf("%c", SOLUTION[ind2]);
	}
	printf(" BASE %hu\n", OUTBASE);
	printf("\nContinue using BASE64? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto BASE64;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void MULTIPLY()
{
	uint16_t VALUE;
	uint8_t BASE;
MULTIPLY:
	printf("Enter a base: ");
	scanf("%hu", &BASE);
CHECKINT:
	printf("\n");
	if(BASE < 2 || BASE > 64)
	{
		printf("INVALID BASE. Base must be between 2 and 64.\n\nEnter a different number: ");
		scanf("%hu", &BASE);
		goto CHECKINT;
	}
	uint8_t **MULTI = new uint8_t*[BASE];
	for (uint8_t db0 = 0; db0 < BASE; ++db0)
		MULTI[db0] = new uint8_t[BASE];
	for (uint8_t db1 = 0; db1 < BASE; ++db1)
	{
		for (uint8_t db2 = 0; db2 < BASE;)
		{
			VALUE = db1*db2;
			if (VALUE == 0)
			{
				MULTI[db1][db2] = '0';
				++db2;
			}
			else
			{
				uint8_t BASES64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz?!";
				uint16_t size = log((double)VALUE)/log((double)BASE)+1;
				uint16_t QUOTIENT;
				uint8_t REMAINDER;				
				uint8_t whichchar;
				uint8_t* CHARARRAY;
				CHARARRAY = new uint8_t[size];
				uint8_t index = 0;
				while (VALUE > 0)
				{
					QUOTIENT = VALUE/BASE;
					REMAINDER = VALUE%BASE;
					for (uint8_t db3 = 0; db3 < sizeof(BASES64); ++db3)
					{
						if (REMAINDER == db3)
						{
							whichchar = BASES64[db3];
							goto SKIP;
						}
					}
SKIP:
					CHARARRAY[index] = whichchar;
					VALUE = QUOTIENT;
					++index;
				}				
				MULTI[db1][db2] = CHARARRAY[0];
				++db2;
			}
		}
	}
	for (uint8_t db4 = 0; db4 < BASE; ++db4)
	{
		for(uint8_t db5 = 0; db5 < BASE; ++db5)
		printf("%c", MULTI[db4][db5]);
		printf("\n");
	}
	/*
	uint8_t **MULTILIST = new uint8_t*[BASE];
	for (uint16_t ml = 0; ml < BASE; ++ml)
	{
		MULTILIST[ml] = new uint8_t[ml+1];
	}
	for ()
	*/
	for(uint8_t db7 = 0; db7 != BASE; ++db7)
		delete[] MULTI[db7];
	delete[] MULTI;
	printf("\nContinue using MULTIPLY? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto MULTIPLY;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}

void GCD()
{
	int64_t first, second;
GCD:
	int64_t divisor = 1;
	printf("Enter first number: ");
	scanf("%lld", &first);
	printf("Enter second number: ");
	scanf("%lld", &second);
	if (second > first)
	{
		int64_t *temp;
		temp = new int64_t;
		*temp = first;
		first = second;
		second = *temp;
		delete temp;
	}
	uint8_t numchar = log((double)second)/log(10.0)+1; //Lame's Theorem
	uint8_t maxoper = numchar*5; //Lame's Theorem
	int64_t *r, *q, *s, *t;
	r = new long long[maxoper];
	q = new long long[maxoper];
	s = new long long[maxoper];
	t = new long long[maxoper];
	r[0] = first;
	r[1] = second;
	q[0] = 0;
	s[0] = 1;
	s[1] = 0;
	t[0] = 0;
	t[1] = 1;
	uint8_t j = 0;
	while (r[j+1] != 0 && j != maxoper)
	{
		divisor = r[j]/r[j+1]; //non-float cuts off decimal
		q[j+1] = divisor;
		r[j+2] = r[j]%r[j+1];
		s[j+2] = s[j]-q[j+1]*s[j+1];
		t[j+2] = t[j]-q[j+1]*t[j+1];
		++j;
	}
	printf("\nGCD: %lld\n\nLINEAR: %lld(%lld) + %lld(%lld) = %lld\n", r[j], first, s[j], second, t[j], r[j]);
	delete[] r, s, q, t;
	printf("\nContinue using GCD? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto GCD;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
}