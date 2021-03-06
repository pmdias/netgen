/*** netgen.h
 *** Prototype code for inclusion into network generation routines
 ***/
#ifndef NETGEN_H
#define NETGEN_H 1

#include "index.h"
#include "random.h"

/*** Constant definitions */

#ifndef NULL
#define NULL 0
#endif /* NULL */

#define BAD_SEED  -1			/* error indicators */
#define TOO_BIG   -2
#define BAD_PARMS -3
#define ALLOCATION_FAILURE -4

#define PROBLEM_PARMS	15				/* aliases for generation parameters           */
#define NODES	    	parms[0]		/* number of nodes                             */
#define SOURCES     	parms[1]		/* number of sources (including transshipment) */
#define SINKS	    	parms[2]		/* number of sinks (including transshipment)   */
#define DENSITY     	parms[3]		/* number of (requested) arcs                  */
#define MINCOST     	parms[4]		/* minimum cost of arcs                        */
#define MAXCOST     	parms[5]		/* maximum cost of arcs                        */
#define MINCOST2		parms[6]		
#define MAXCOST2		parms[7]
#define SUPPLY	    	parms[8]		/* total supply                                */
#define TSOURCES    	parms[9]		/* transshipment sources                       */
#define TSINKS	    	parms[10]		/* transshipment sinks                         */
#define HICOST	    	parms[11]		/* percent of skeleton arcs given maximum cost */
#define CAPACITATED 	parms[12]		/* percent of arcs to be capacitated           */
#define MINCAP	    	parms[13]		/* minimum capacity for capacitated arcs       */
#define MAXCAP	    	parms[14]		/* maximum capacity for capacitated arcs       */

/*** Type definitions */

typedef unsigned long NODE;		/* node number */
typedef unsigned long ARC;		/* arc number */
typedef long CAPACITY;			/* arc capacity */
typedef long COST;				/* arc cost */


/*** Function prototypes */

#ifdef __STDC__

#include <stdlib.h>
#include <string.h>

ARC netgen(long, long*);	    				/* C external interface       */

void create_supply(NODE, CAPACITY); 		/* create supply nodes                       */
void create_assignment(long *);				/* create assignment problem                 */
void sort_skeleton(int);					/* sorts skeleton chains                     */
void pick_head(long *, int, NODE); 			/* choose destination nodes for rubbish arcs */
void error_exit(long);						/* print error message and exit              */

#else

void *malloc();				/* some standard header should define this */
void *realloc();			/* ditto */
void free();				/* ditto */
void *memset();				/* ditto */
void exit();				/* ditto */

ARC netgen();		    	/* C external interface       */

void create_supply();		/* create supply nodes                        */
void create_assignment();	/* create assignment problem                  */
void sort_skeleton();		/* sorts skeleton chains                      */
void pick_head();			/* chooses destination nodes for rubbish arcs */
void error_exit();			/* print error message and exit               */

#endif /* __STDC__ */

#define MAXNODES 17000	    		/* maximum problem sizes */
#define MAXARCS 150000

#define FROM arrays_	    		/* aliases for network storage */
#define TO   arraye_
#define U    arrayu_
#define C1   arrayc1_
#define C2	 arrayc2_
#define B    arrayb_

/*** Externally visible variables ***/

extern NODE     FROM[MAXARCS];	/* origin of each arc */
extern NODE     TO  [MAXARCS];	/* destination */
extern CAPACITY U   [MAXARCS];	/* capacity */
extern COST     C1  [MAXARCS];	/* cost set 1 */
extern COST		C2	[MAXARCS];	/* cost set 2 */
extern CAPACITY B   [MAXNODES];	/* supply (demand) at each node */

#endif /* NETGEN_H */
