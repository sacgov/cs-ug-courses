/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fact.h"

int *
fact_calc_1_svc(for_factorial *argp, struct svc_req *rqstp)
{
	static int  result =1;

	/*
	 * insert server code here
	 */
	 int i=0;
	 for(i=1;i<=argp->num;i++)
	 	result *=i;
	 printf("%d\n",result );

	return &result;
}