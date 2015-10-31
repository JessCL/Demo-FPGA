#include "xparameters.h"
#include "vga_ip.h"
#include "lab_gobang_AI_2.h"
#include "VGADraw.h"

extern int board_state[15][15];
extern int status;
//extern int status;

void DrawBoard (void)
{
	int i,j,x_cor,y_cor,type,vga_input;
	for (i=0; i<15; i++) {
		for (j=0; j<15; j++) {
			x_cor=i<<24;
			y_cor=j<<16;
			type=EMPTY;
			vga_input=x_cor+y_cor+type;
		    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
		}
    }
}

void DrawChess (int x_pos, int y_pos, int turn)
{
	int x_cor,y_cor,type,vga_input;
	type=turn;
	x_cor=x_pos<<24;
	y_cor=y_pos<<16;
	vga_input=x_cor+y_cor+type;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
}

void EraseCursor (int x_pos, int y_pos)
{
	if ((board_state[x_pos][y_pos]==0 && (status==PVC || status==PVP))||(board_state[x_pos][y_pos]==1 && (status==CVP )))  {
		DrawChess(x_pos,y_pos,0);
	}
	else if ((board_state[x_pos][y_pos]==1 && (status==PVC || status==PVP))||(board_state[x_pos][y_pos]==0 && (status==CVP ))) {
		DrawChess(x_pos,y_pos,1);
	}
	else {
		DrawChess(x_pos,y_pos,2);
	}
}

void DrawNumber(int number, int x_pos, int y_pos, int turn)
{
	int vga_input;

	switch (number) {
	    case 0: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+turn;
                VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
       	        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
       	        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                break;
	    case 1: vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
                break;
	    case 2: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	    	    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	    	    break;
	    case 3: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 4: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 5: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 6: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 7: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 8: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	    case 9: vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+3)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	           	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+turn;
	           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	            break;
	}

}

void DrawTime(int time, int turn)
{
	int num1, num2;

	num1=time/10;
	num2=time%10;
	DrawNumber(num1, 1, 10, turn);
	DrawNumber(num2, 5, 10, turn);
}

void DrawWinning(int x_pos, int y_pos, int turn)
{
	int vga_input;
	DrawBoard();

	vga_input=((x_pos)<<24)+(y_pos-1<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos)<<24)+(y_pos<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos)<<24)+(y_pos+1<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+1)<<24)+(y_pos+2<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+2)<<24)+(y_pos+1<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+2)<<24)+(y_pos<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+3)<<24)+(y_pos+2<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+4)<<24)+(y_pos+1<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+4)<<24)+(y_pos<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+4)<<24)+(y_pos-1<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+6)<<24)+(y_pos+3<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+7)<<24)+(y_pos+3<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+8)<<24)+(y_pos+3<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+7)<<24)+(y_pos+4<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+7)<<24)+(y_pos+5<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+7)<<24)+(y_pos+6<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+7)<<24)+(y_pos+7<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+8)<<24)+(y_pos+7<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+6)<<24)+(y_pos+7<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+10)<<24)+(y_pos+8<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+10)<<24)+(y_pos+9<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+10)<<24)+(y_pos+10<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+10)<<24)+(y_pos+11<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+10)<<24)+(y_pos+12<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+11)<<24)+(y_pos+9<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+12)<<24)+(y_pos+10<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+13)<<24)+(y_pos+11<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+14)<<24)+(y_pos+12<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+14)<<24)+(y_pos+11<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+14)<<24)+(y_pos+10<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+14)<<24)+(y_pos+9<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
	vga_input=((x_pos+14)<<24)+(y_pos+8<<16)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);


}

void DrawStatus(int x_pos, int y_pos, int turn,int status)
{
	int vga_input;
/*
    vga_input=((x_pos+2)<<24)+((y_pos+5)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+2)<<24)+((y_pos+6)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+3)<<24)+((y_pos+7)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos+6)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    vga_input=((x_pos+4)<<24)+((y_pos+5)<<16)+(1<<8)+3;
    VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
*/
    if (status==PVP) {
        vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

    	vga_input=((x_pos+116)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+117)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+118)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+118)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+117)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+118)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+8+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	DrawNumber(8,4,21,EMPTY);
    }
    else if(status==PVC) {
    	vga_input=((x_pos+0)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	    	vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	    	vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	    	vga_input=((x_pos+0)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	    	vga_input=((x_pos+0)<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	    	vga_input=((x_pos+0)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	    	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	    	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        vga_input=((x_pos+116)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
            VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
           	vga_input=((x_pos+117)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
           	vga_input=((x_pos+118)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
           	vga_input=((x_pos+116)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
           	vga_input=((x_pos+116)<<24)+((y_pos+8+1)<<16)+(1<<8)+turn;
          	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
           	vga_input=((x_pos+116)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
           	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
           	vga_input=((x_pos+117)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
            	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
            	vga_input=((x_pos+118)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
            	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
            	DrawNumber(8,4,21,EMPTY);
           DrawNumber(1,4,21,0);
    }
    else if(status==CVP) {
    	vga_input=((x_pos+0)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+0)<<24)+((y_pos+2)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+0)<<24)+((y_pos+3)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+0)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+1-turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

    	vga_input=((x_pos+116)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+117)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+118)<<24)+((y_pos+5+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+118)<<24)+((y_pos+6+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+117)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+118)<<24)+((y_pos+7+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+8+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    	vga_input=((x_pos+116)<<24)+((y_pos+9+1)<<16)+(1<<8)+turn;
    	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
    		DrawNumber(8,4,21,EMPTY);
    		DrawNumber(2,4,21,0);
    }
    if(turn==EMPTY)
    {
        vga_input=(x_pos<<24)+(y_pos<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+(y_pos<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+(y_pos<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+2)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+2)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+2)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+3)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=(x_pos<<24)+((y_pos+4)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+4)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+2)<<24)+((y_pos+4)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+1)<<24)+((y_pos+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

        vga_input=((x_pos+6)<<24)+((y_pos+5+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+7)<<24)+((y_pos+5+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+8)<<24)+((y_pos+5+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+6)<<24)+((y_pos+6+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+8)<<24)+((y_pos+6+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+6)<<24)+((y_pos+7+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+7)<<24)+((y_pos+7+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+8)<<24)+((y_pos+7+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+6)<<24)+((y_pos+8+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+6)<<24)+((y_pos+9+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+7)<<24)+((y_pos+9+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+8)<<24)+((y_pos+9+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
        vga_input=((x_pos+7)<<24)+((y_pos+6+1)<<16)+(1<<8)+2;
        VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

    }
}


void DrawBack(int x_pos, int y_pos,int turn)
{
	int vga_input;
	vga_input=(x_pos<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+1)<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+2)<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+(y_pos+2<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+1+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+((y_pos+1+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+1)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+2)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+((y_pos+2+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+3+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+2)<<24)+((y_pos+3+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+0)<<24)+((y_pos+4+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);

	vga_input=((x_pos+3)<<24)+((y_pos+4+2)<<16)+(1<<8)+turn;
	VGA_IP_mWriteReg(XPAR_VGA_IP_0_BASEADDR, 0, vga_input);
}


