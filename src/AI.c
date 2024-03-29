#include "lab_gobang_AI_2.h"

extern int maxMoveX;
extern int maxMoveY;

void CopyBoard(int newboard[][15], int board[][15])
{
	int i, j;
	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			newboard[i][j]=board[i][j];
		}
	}
}

void GetRange(int board[][15], int *minRangeX, int *maxRangeX, int *minRangeY, int *maxRangeY)
{
	int i, j;
	int maxX=0, minX=15, maxY=0, minY=15;
	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			if (board[i][j]!=EMPTY) {
				if (i<minX)
					minX=i;
				if (i>maxX)
					maxX=i;
				if (j<minY)
					minY=j;
				if (j>maxY)
					maxY=j;
			}
		}
	}
	if (maxX+2>14)
		*maxRangeX=14;
	else
		*maxRangeX=maxX+2;
	if (minX-2<0)
		*minRangeX=0;
	else
		*minRangeX=minX-2;
	if (maxY+2>14)
		*maxRangeY=14;
	else
		*maxRangeY=maxY+2;
	if (minY-2<0)
		*minRangeY=0;
	else
		*minRangeY=minY-2;
}

int ValueTable(int count, int flag1, int flag2)
{
	if (count==5)
		return 1000000;
	else if (count==4) {
		if (flag1==LIVE && flag2==LIVE)
			return 300000;
		else if ((flag1==LIVE && flag2==DEAD) || (flag1==DEAD && flag2==LIVE))
			return 2500;
		else
			return 100;
	}
	else if (count==3) {
		if (flag1==LIVE && flag2==LIVE)
			return 3000;
		else if ((flag1==LIVE && flag2==DEAD) || (flag1==DEAD && flag2==LIVE))
			return 500;
		else
			return 50;
	}
	else if (count==2) {
		if (flag1==LIVE && flag2==LIVE)
			return 700;
		else if ((flag1==LIVE && flag2==DEAD) || (flag1==DEAD && flag2==LIVE))
			return 100;
		else
			return 0;
	}
	else {
		if (flag1==LIVE && flag2==LIVE)
			return 200;
		else if ((flag1==LIVE && flag2==DEAD) || (flag1==DEAD && flag2==LIVE))
			return 50;
		else
			return 0;
	}
}

int CalculateValue(int board[][15], int turn, int x_pos, int y_pos)
{
	int i, j, count;
	int flag1, flag2;
	int value[4];

	flag1=DEAD;
	flag2=DEAD;
	count=1;
	for (i=x_pos+1, j=y_pos; i<15; i++) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag1=LIVE;
			break;
		}
		else {
			flag1=DEAD;
			break;
		}
	}
	for (i=x_pos-1, j=y_pos; i>=0; i--) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag2=LIVE;
			break;
		}
		else {
			flag2=DEAD;
			break;
		}
	}
	value[0]=ValueTable(count, flag1, flag2);

	flag1=DEAD;
	flag2=DEAD;
	count=1;
	for (i=x_pos, j=y_pos+1; j<15; j++) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag1=LIVE;
			break;
		}
		else {
			flag1=DEAD;
			break;
		}
	}
	for (i=x_pos, j=y_pos-1; j>=0; j--) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag2=LIVE;
			break;
		}
		else {
			flag2=DEAD;
			break;
		}
	}
	value[1]=ValueTable(count, flag1, flag2);

	flag1=DEAD;
	flag2=DEAD;
	count=1;
	for (i=x_pos+1, j=y_pos+1; i<15 && j<15; i++, j++) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag1=LIVE;
			break;
		}
		else {
			flag1=DEAD;
			break;
		}
	}
	for (i=x_pos-1, j=y_pos-1; i>=0 && j>=0; i--, j--) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag2=LIVE;
			break;
		}
		else {
			flag2=DEAD;
			break;
		}
	}
	value[2]=ValueTable(count, flag1, flag2);

	flag1=DEAD;
	flag2=DEAD;
	count=1;
	for (i=x_pos+1, j=y_pos-1; i<15 && j>=0; i++, j--) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag1=LIVE;
			break;
		}
		else {
			flag1=DEAD;
			break;
		}
	}
	for (i=x_pos-1, j=y_pos+1; i>=0 && j<15; i--, j++) {
		if (board[i][j]==turn)
			count++;
		else if (board[i][j]==EMPTY) {
			flag2=LIVE;
			break;
		}
		else {
			flag2=DEAD;
			break;
		}
	}
	value[3]=ValueTable(count, flag1, flag2);

	if (turn==COMPUTER_PLAYER)
		return value[0]+value[1]+value[2]+value[3];
	else
		return -(value[0]+value[1]+value[2]+value[3]);
}

int EvaluateHumanMove(int board[][15], int depth, int alpha, int beta, int newmoveX, int newmoveY)
{
	int i, j, value_human, value_computer;
	//int newboard[15][15];
	int min=MAX_INFINITY+1;
	int minRangeX, maxRangeX, minRangeY, maxRangeY;

	int EvaluateComputerMove(int board[][15], int, int, int, int, int);

	if (depth>=MAX_DEPTH) {
		value_computer=CalculateValue(board, COMPUTER_PLAYER, newmoveX, newmoveY);
		return value_computer;
	}
	else {
		if (depth==0)
			value_computer=0;
		else
			value_computer=CalculateValue(board, COMPUTER_PLAYER, newmoveX, newmoveY);
		GetRange(board, &minRangeX, &maxRangeX, &minRangeY, &maxRangeY);
	    for (i=minRangeX; i<=maxRangeX; i++) {
		    for (j=minRangeY; j<=maxRangeY; j++) {
				if (board[i][j]==EMPTY) {
					//CopyBoard(newboard, board);
					board[i][j]=HUMAN_PLAYER;//newboard[i][j]=HUMAN_PLAYER;
				    value_human=EvaluateComputerMove(board, depth+1, alpha, beta, i ,j);
				    board[i][j]=EMPTY;
				    value_human+=value_computer;
				    if (value_human<min) {
						min=value_human;
					}
				    if (value_human<beta)
					    beta=value_human;
				    if (alpha>=beta)
					   return beta;
				}
			}
		}
	    return min;
	}
}

int EvaluateComputerMove(int board[][15], int depth, int alpha, int beta, int newmoveX, int newmoveY)
{
	int i, j, value_human, value_computer,tx,ty;
	//int newboard[15][15];
	int max=MIN_INFINITY-1;
	int minRangeX, maxRangeX, minRangeY, maxRangeY;

	int EvaluateHumanMove(int board[][15], int, int, int, int, int);

	if (depth>=MAX_DEPTH) {
		value_human=CalculateValue(board, HUMAN_PLAYER, newmoveX, newmoveY);
		return value_human;
	}
	else {
		if (depth==0)
			value_human=0;
		else
			value_human=CalculateValue(board, HUMAN_PLAYER, newmoveX, newmoveY);
		GetRange(board, &minRangeX, &maxRangeX, &minRangeY, &maxRangeY);
		for (i=minRangeX; i<=maxRangeX; i++) {
		    for (j=minRangeY; j<=maxRangeY; j++) {
			    if (board[i][j]==EMPTY) {
                    //CopyBoard(newboard, board);
			    	board[i][j]=COMPUTER_PLAYER;//newboard[i][j]=COMPUTER_PLAYER;
					value_computer=EvaluateHumanMove(board, depth+1, alpha, beta, i, j);
					board[i][j]=EMPTY;
				    value_computer+=value_human;
					if (value_computer>max) {
					    max=value_computer;
						tx=i;//maxMoveX=i;
						ty=j;//maxMoveY=j;
					}
				    if (value_computer>alpha)
					    alpha=value_computer;
				    if (alpha>=beta){maxMoveX=tx;maxMoveY=ty;
					    return alpha;}
				}
			}
		}
		maxMoveX=tx;maxMoveY=ty;
		return max;
	}
}
