#include<Windows.h>

#ifndef BOARDTYPE_H_
#define BOARDTYPE_H_

/*ad
ad*/

/*	禁手类型	*/
#define	BAN33	1		/*	三三禁手									*/
#define	BAN44	2		/*	四四禁手									*/
#define	BANLL	3		/*	长连禁手									*/

/*棋型标号	*/
#define L4L4	1		/*												*/
#define L4D4	2		/*												*/
#define L4L3	3		/*												*/
#define D4D4	4		/*												*/
#define	L4		5		/*												*/
#define	BAN5	6		/*	禁手五										*/
#define	D4L3	7		/*												*/
#define	TL4L3	8		/*												*/
#define	TD4L3	9		/*												*/
#define	L3L3	10		/*												*/

/*棋型分值*/
#define	MAXF	1000000	/*	当连成5子时返回无限大值						*/
#define L4L4F	750000	/*	8192 8184(单跳) 8176(双跳)	双活四			*/
#define L4D4F	700000	/*	6144 6140 6136 6132			活四死四		*/
#define L4L3F	650000	/*	4608 4600 4592				活四活三		*/
#define D4D4F	600000	/*	4096 4092 4088								*/
#define	L4F		550000	/*	4096										*/
#define	TL4L3F	500000	/*												*/
#define	D4L3F	450000	/*	2560 2552(跳三) 2556(跳四) 2548(跳三跳四)	*/
#define	TD4L3F	400000	/*												*/
#define	L3L3F	350000	/*	1024 1016(单跳活三) 1008(双跳活三)			*/
#define BASEF	10		/*	得分基数									*/




/*其他*/
#define BORDLEN 1		/*边界扩展宽度									*/


/*文字绘色*/
const int COLOR_RED		=		FOREGROUND_RED;
const int COLOR_BLUE	=		FOREGROUND_BLUE;
const int COLOR_GREEN	=		FOREGROUND_GREEN;


#endif 
