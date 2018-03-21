#include "0.h"
#include "012345.h"
#include "6789AB.h"
#include "CDEFGH.h"
#include "IJKLMN.h"
#include "OPQRST.h"
#include "UVWXYZ.h"

int main(int argc, char** argv)
{
	//cout.precision(16);
	uint8_t choice;
	printf("MATH:\n\n");
MATH:
	printf("Which program would you like to run?\n\n0. ADDTOTAL  6. SIX       C. FACTOR    I. ?         O. ?         U. ?         \n1. NUMBAT    7. CIRCLE    D. 1729      J. ?         P. ?         V. ?         \n2. NUMBO     8. BASE      E. ROMAN     K. ?         Q. ?         W. ?         \n3. THREE     9. BASE64    F. ?         L. ?         R. ?         X. ?         \n4. FOUR      A. MULTIPLY  G. ?         M. ?         S. ?         Y. ?         \n5. FIVE      B. GCD       H. ?         N. ?         T. ?         Z. ?         \n\nEnter choice here: ");
DEFAULT:
	scanf(" %c", &choice);
	if (choice > 96 && choice < 123)
	choice -= 32;
	printf("\n");
	switch (choice)
	{
		case '0':
		{
			printf("ADDTOTAL:\n\n");
			ADDTOTAL();
			break;
		}
		case '1':
		{
			printf("NUMBAT:\n\n");
			NUMBAT();
			break;
		}
		case '2':
		{
			printf("NUMBO:\n\n");
			NUMBO();
			break;
		}
		case '3':
		{
			printf("THREE:\n\n");
			THREE();
			break;
		}
		case '4':
		{
			printf("FOUR:\n\n");
			FOUR();
			break;
		}
		case '5':
		{
			printf("FIVE:\n\n");
			FIVE();
			break;
		}
		case '6':
		{
			printf("SIX:\n\n");
			SIX();
			break;
		}
		case '7':
		{
			printf("CIRCLE:\n\n");
			CIRCLE();
			break;
		}
		case '8':
		{
			printf("BASE:\n\n");
			printf("Welcome to BASE\nThis program converts numbers (values) from one base to another.\nUser may use alphanumeric chars 0-9 and A-Z, and specify input and output bases ranging from 2 to 36.\nLet's get started!\n\n");
			BASE();
			break;
		}
		case '9':
		{
			printf("BASE64:\n\n");
			BASE64();
			break;
		}
		case 'A':
		{
			printf("MULTIPLY:\n\n");
			MULTIPLY();
			break;
		}
		case 'B':
		{
			printf("GCD:\n\n");
			GCD();
			break;
		}
		case 'C':
		{
			printf("FACTOR:\n\n");
			FACTOR();
			break;
		}
		case 'D':
		{
			printf("1729:\n\n");
			_1729();
			break;
		}
		case 'E':
		{
			printf("ROMAN:\n\n");
			ROMAN();
			break;
		}
		case 'F':
		{
			printf("F:\n\n");
			break;
		}
		case 'G':
		{
			printf("G:\n\n");
			break;
		}
		case 'H':
		{
			printf("H:\n\n");
			break;
		}
		case 'I':
		{
			printf("I:\n\n");
			break;
		}
		case 'J':
		{
			printf("J:\n\n");
			break;
		}
		case 'K':
		{
			printf("K:\n\n");
			break;
		}
		case 'L':
		{
			printf("L:\n\n");
			break;
		}
		case 'M':
		{
			printf("M:\n\n");
			break;
		}
		case 'N':
		{
			printf("N:\n\n");
			break;
		}
		case 'O':
		{
			printf("O:\n\n");
			break;
		}
		case 'P':
		{
			printf("P:\n\n");
			break;
		}
		case 'Q':
		{
			printf("Q:\n\n");
			break;
		}
		case 'R':
		{
			printf("R:\n\n");
			break;
		}
		case 'S':
		{
			printf("S:\n\n");
			break;
		}
		case 'T':
		{
			printf("T:\n\n");
			break;
		}
		case 'U':
		{
			printf("U:\n\n");
			break;
		}
		case 'V':
		{
			printf("V:\n\n");
			break;
		}
		case 'W':
		{
			printf("W:\n\n");
			break;
		}
		case 'X':
		{
			printf("X:\n\n");
			break;
		}
		case 'Y':
		{
			printf("Y:\n\n");
			break;
		}
		case 'Z':
		{
			printf("Z:\n\n");
			break;
		}
		default:
		{
			printf("INVALID CHOICE. Use alphanumeric chars only.\n\nEnter another choice: ");
			goto DEFAULT;
			break;
		}
	}
	printf("\nContinue using MATH? Enter Y or N: ");
	uint8_t conti;
CONTINUE:
	scanf(" %c", &conti);
	if (conti > 96 && conti < 123)
		conti -= 32;
	if (conti == 'Y')
	{
		printf("\n");
		goto MATH;
	}
	else if (conti == 'N');
	else
	{
		printf("INVALID ANSWER. Enter Y or N: ");
		goto CONTINUE;
	}
	return 0;
}