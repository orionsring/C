/***		fwrite.c
*
*			Synopsis - Accepts input of
*	information about banking transactions and 
*	stores the information in a file.
*
*			Objective - To illustrate the use
*	of fwrite to a block output of a structure.
*
*/
/*	include files */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* constant definitions */
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 80

/* Type Descriptions */
struct trans{
	int t_type;
	char payee_memo[BUF_SIZE];
	
		/*	NOTE1: the structure for a bank transaction is declared.
		The sizeof() this structure is used to call to fwrite()
		when the information is written to a file
		*/

	double amount;
	unsigned tax_deduct: 1;
	unsigned cleared 	: 1;
	};
	

/*Function prototypes*/
int get_type(void);
/*	PRECONDITION: none
	POSTCONDITION: request & accpet input of the transaction type form the keyboard
	returns a check number for a check,
	the ASCIII value of W for withdrawl,
	the ASCIII value of D for deposit,
	the ASCIII value of Q for quit.
*/

void get_trans(struct trans *trans_ptr);
/*	PRECONDITION: The parameter
	trans)ptr contains the address of a 
	struct trans declared by the calling function.
	
	POSTCONDITION: takes input from the 
	terminal to populate the struct trans
	pointed to by the passed parameter.
	
*/

void put_trans(struct trans *trans_ptr, FILE *fp);
/*	PRECONDITION: The parameter trans_ptr contains
	the address of a struct trans declared by the 
	calling function. fp contains the address of FILE*
	
	POSTCONDITION: writes the contents of the structer
	pointed to by trans_ptr to the file associated with
	fp.
	
*/

int main(void)
{
	struct trans transact;
	FILE *fp;
	
/*	NOTE 2:	the call to fopen() opens the file with the 
	mode a+. This would allow both reading the file
	and writing at the end fo the file
	
*/
	if((fp=fopen("transact", "a+"))==NULL)
	{
		printf("Transaction file couldn't be opened.\n");
		exit(1);
	}
	
	/*the next while loop will continue until the user type a 'Q' 
	for the transaction type. Each time the loop executes one transaction
	inputs to the file
	*/
	
	while((transact.t_type=get_type())!='Q')
	{
		get_trans(&transact);
		put_trans(&transact,fp);
	}
	fclose(fp);
	return 0;
}//end main
	
/*			*  			* 		get_type() 		*		* 			*				*/
int get_type(void)
{
	char buffer[BUF_SIZE];
	int correct = FALSE, t_type;
	
	while(!correct)	{
	printf("D=deposit, W=withdrawal, or Check# \n");
	printf("Enter transaction type ('Q' to quit):");
	fgets(buffer, BUF_SIZE, stdin);
		if(isdigit(*buffer)){
		/*	convert string of digits to type int
		*	
		*/
		correct = TRUE;
		t_type = atoi(buffer);
		}//endif
		
		else{
		/* translate any alphabetic character to 
		*	uppercase for testing storage
		*/
		t_type=toupper((int)*buffer);
		if((t_type!='D')&&(t_type!='W')&&(t_type!='Q'))
		printf("Incorrect, try again \n");
		else 
		correct=TRUE;
		}//endelse
	}//end while
	
	return (t_type);
}//end get_type

/*		*		*		* 		get_trans()		*		*		*		*/
void get_trans(struct trans *trans_ptr)
{
	char inbuf[BUF_SIZE];
	printf("Amount:$");
	fgets(inbuf,BUF_SIZE,stdin);
	trans_ptr->amount=atof(inbuf);
	
	switch(trans_ptr->t_type)
	{
		case 'W':
		
		case 'O':
		printf("Memo: ");
		fgets(trans_ptr->payee_memo,BUF_SIZE,stdin);
		break;
		
		default:
		printf("Payee: ");
		fgets(trans_ptr->payee_memo,BUF_SIZE,stdin);
	}
	
	printf("Tax_deductible?(y/n): ");
	fgets(inbuf,BUF_SIZE,stdin);
	if((*inbuf=='y')||(*inbuf=='Y'))
	trans_ptr->tax_deduct=0;
	
	printf("Cleared? (y/n): ");
	fgets(inbuf, BUF_SIZE, stdin);
	if((*inbuf=='y')||(*inbuf=='Y'))
	trans_ptr->cleared=1;
	else
	trans_ptr->cleared=0;
	
}//end get_trans()


/*		*		*		*		pnt_trans()		*		*		*		*/
void put_trans(struct trans *trans_ptr, FILE *fp)
	{
	fwrite(trans_ptr, sizeof(struct trans), 1, fp);
	
	/* NOTE 3: this call to fwrite() will write the 
	*			information about a single transaction to the file.
	*			The first parameter to fwrite() is the address of 
	*			the buffer where the information to be written resides.
	*			In this case, the buffer is the structure itself,
	*			and the address is passed to fwrite() by the pointer
	*			trans_ptr. The next two fields combine (multiply)
	*			to give the total number of bytes to write. In this case
	*			one structure writes, so then the number of bytes is given
	*			by sizeof(struct trans)*1. the final parameter indicates
	*			the file where the output stores itself.
	*/
	}//end put_trans
	
	//eof
	
	
	
	

	