#ifndef VGADRAW_H_
#define VGADRAW_H_

void DrawBoard (void);

void DrawChess (int x_pos, int y_pos, int turn);

void EraseCursor (int x_pos, int y_pos);

void DrawNumber(int number, int x_pos, int y_pos, int turn);

void DrawTime(int time, int turn);

void DrawWinning(int x_pos, int y_pos, int turn);

void DrawStatus(int x_pos, int y_pos, int turn,int status);

void DrawBack(int x_pos, int y_pos,int turn);

#endif
