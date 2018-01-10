#include"STC15F2K60S2.h "

#define uint unsigned int
#define uchar unsigned char

sbit Dyellow=P0^0;
sbit Dgreen=P0^1;
sbit Dred=P0^2;
sbit Xyellow=P0^3;
sbit Xgreen=P0^4;
sbit Xred=P2^3;
sbit Nyellow=P1^0;
sbit Ngreen=P1^1;
sbit Nred=P1^2;
sbit Byellow=P1^3;
sbit Bgreen=P1^4;
sbit Bred=P1^5;
sbit Rred=P0^5;
sbit Rgreen=P0^6;

sbit Kid=P0^7;//��ͯ��ʾ��
sbit J=P3^3;//������ť

uint num1,num2, num3,num4;  //    ��   ��    ��   ��
uint w,d,ge1,shi1,ge2,shi2, ge3,shi3, ge4,shi4;
							
/*****************************���������*****************************/
sbit    P_HC595_OE    = P3^7;	//pin 13    OE      out enabled
sbit	P_HC595_SER   = P4^5;	//pin 14	SER		data input
sbit	P_HC595_RCLK  = P4^4;	//pin 12	RCLk	store (latch) clock
sbit	P_HC595_SRCLK = P4^2;	//pin 11	SRCLK	Shift data clock


unsigned char code tableduan[]={
// 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
	0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71   
};	  // ����
unsigned char code tablewei[]={
	//1    2    3    4    5    6   7    8  
	0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f                                        
};	   //λ��

/*****************************������������****************/
void delay(uint z)	  //��ʱ	  ԭ��delay(8000)������1s
{
	uint x,y;
	for(x=z;x>0;x--)
		//for(y=110;y>0;y--);
		for(y=800;y>0;y--);
}
void Send_595(unsigned char dat);
void DisplayScan(unsigned char num,wei);
void xianshi();		  //��ʾ
void zhengchang();	  //����
/***************************������******************************/
/*void main()
{
	while(1)
	{
		uchar i	; 
		 num1=88;num2=77;num3=66;num4=55;
		for(i=38;i>0;i--){
		ge1=num1%10;shi1=num1/10;ge2=num2%10;shi2=num2/10;
         ge3=num3%10;shi3=num3/10;ge4=num4%10;shi4=num4/10;
		 xianshi();	
		 num1--;num2--; num3--;num4--;
		 }
	}
	
} */
void main()
{
	while(1)
	{
		if(J==0){
			Nred=0;Dred=0; Bred=0; Xred=0; Kid=0;delay(10000);}
	    else{
			zhengchang();}
	}
}

/************************* ��ʾ���� ***************************/
//void DisplayScan(unsigned char num,unsigned char place)
void DisplayScan(uint num,uint place)
{	
	Send_595(tablewei[place-1]);			//���λ�� 
	Send_595(tableduan[num]);	        //�������

	P_HC595_RCLK = 1;					//�����������
	P_HC595_RCLK = 0;	
//	delay(3);
	
//	Send_595(0);				//���λ�� ���0��8λȫ��ѡ��
//	Send_595(0x00);		
//	P_HC595_RCLK = 1;					//�����������
//	P_HC595_RCLK = 0;				
} 
void xianshi()
     {
	   uint i=125;
	   while(i--)
       {
		   w=1;d=shi1;DisplayScan(d,w);delay(1);
           w=2;d=ge1;DisplayScan(d,w);delay(1);
           w=3;d=shi2;DisplayScan(d,w);delay(1);
           w=4;d=ge2;DisplayScan(d,w);delay(1);
           w=5;d=shi3;DisplayScan(d,w);delay(1);
           w=6;d=ge3;DisplayScan(d,w);delay(1);
           w=7;d=shi4;DisplayScan(d,w);delay(1);
           w=8;d=ge4;DisplayScan(d,w);delay(1); 
	   }
     } 

void zhengchang()
{
	num1=63;num2=51 ;num3=27;num4=27;
	while(num3){
		if(J==0){
			Nred=0;Dred=0;Ngreen=1;Dyellow=1;Nyellow=1;Dgreen=1; 
			Bred=0; Xred=0; Bgreen=1; Xyellow=1; Byellow=1; 
			Xgreen=1;Kid=0;Rred=1;Rgreen=0;delay(10000);}
	    else{
			Nyellow=1;Nred=1;Ngreen=0;Dyellow=1;Dred=0;Dgreen=1; 
			Byellow=1; Bred=1; Bgreen=0; Xyellow=1; Xred=0; 
			Xgreen=1;Kid=1;Rred=0;Rgreen=1;
	         ge1=num1%10;shi1=num1/10;ge2=num2%10;shi2=num2/10;
	         ge3=num3%10;shi3=num3/10;ge4=num4%10;shi4=num4/10;
	         xianshi();num1--;num2--; 	num3--;num4--;	
       }
     } //״̬1

	num1=36;num2=24 ;num3=3;num4=3;
	while(num3)
	     {if(J==0)
		   {Nred=0;Dred=0;Ngreen=1;Dyellow=1;Nyellow=1;Dgreen=1; 
	  		Bred=0; Xred=0; Bgreen=1; Xyellow=1; Byellow=1; 
			Xgreen=1;Kid=0;Rred=1;Rgreen=0;delay(10000);}
		  else
		   {Nyellow=0;Nred=1;Ngreen=1;Dyellow=1;Dred=0;Dgreen=1; 
			Byellow=0; Bred=1; Bgreen=1; Xyellow=1; Xred=0; 
			Xgreen=1;Kid=1;Rred=0;Rgreen=1;
	         ge1=num1%10;shi1=num1/10;ge2=num2%10;shi2=num2/10;
	         ge3=num3%10;shi3=num3/10;ge4=num4%10;shi4=num4/10;
	         xianshi();num1--;num2--; 	num3--;num4--;	
	       }
	     } //״̬2

	num1=33;num2=21 ;num3=89;num4=89;
	 while(num2)
	     {if(J==0)
		   {Nred=0;Dred=0;Ngreen=1;Dyellow=1;Nyellow=1;Dgreen=1; 
			Bred=0; Xred=0; Bgreen=1; Xyellow=1; Byellow=1; 
			Xgreen=1;Kid=0;Rred=1;Rgreen=0;delay(10000);}
		  else
		   {Nyellow=1;Nred=0;Ngreen=1;Dyellow=1;Dred=0;Dgreen=1; 
			Byellow=1; Bred=0; Bgreen=1; Xyellow=1; Xred=0; 
			Xgreen=1;Kid=1;Rred=1;Rgreen=0;
	         ge1=num1%10;shi1=num1/10;ge2=num2%10;shi2=num2/10;
	         ge3=num3%10;shi3=num3/10;ge4=num4%10;shi4=num4/10;
	         xianshi();num1--;num2--; 	num3--;num4--;	
	       }
	     } //״̬3

	num1=12;num2=65 ;num3=68;num4=68;
	while(num1)
	     {if(J==0)
		   {Nred=0;Dred=0;Ngreen=1;Dyellow=1;Nyellow=1;Dgreen=1; 
			Bred=0; Xred=0; Bgreen=1; Xyellow=1; Byellow=1; 
			Xgreen=1;Kid=0;Rred=1;Rgreen=0;delay(10000);}
		  else
		   {Nyellow=1;Nred=0;Ngreen=1;Dyellow=1;Dred=0;Dgreen=1; 
			Byellow=1; Bred=0; Bgreen=1; Xyellow=1; Xred=1; 
			Xgreen=0;Kid=1;Rred=0;Rgreen=1;
	         ge1=num1%10;shi1=num1/10;ge2=num2%10;shi2=num2/10;
	         ge3=num3%10;shi3=num3/10;ge4=num4%10;shi4=num4/10;
	         xianshi();num1--;num2--; 	num3--;num4--;	
	       }
	     } //״̬4

	num1=53;num2=53 ;num3=56;num4=56;
	while(num1)
	     {if(J==0)
		   {Nred=0;Dred=0;Ngreen=1;Dyellow=1;Nyellow=1;Dgreen=1; 
			Bred=0; Xred=0; Bgreen=1; Xyellow=1; Byellow=1; 
			Xgreen=1;Kid=0;Rred=1;Rgreen=0;delay(10000);}
		  else
		   {Nyellow=1;Nred=0;Ngreen=1;Dyellow=1;Dred=1;Dgreen=0; 
			Byellow=1; Bred=0; Bgreen=1; Xyellow=1; Xred=1; 
			Xgreen=0;Kid=1;Rred=0;Rgreen=1;
	         ge1=num1%10;shi1=num1/10;ge2=num2%10;shi2=num2/10;
	         ge3=num3%10;shi3=num3/10;ge4=num4%10;shi4=num4/10;
	         xianshi();num1--;num2--; 	num3--;num4--;	
	       }
	     } //״̬5
	num1=3;num2=3 ;num3=3;num4=3;
	while(num1)
	     {if(J==0)
		   {Nred=0;Dred=0;Ngreen=1;Dyellow=1;Nyellow=1;Dgreen=1; 
			Bred=0; Xred=0; Bgreen=1; Xyellow=1; Byellow=1; 
			Xgreen=1;Kid=0;Rred=1;Rgreen=0;delay(10000);}
		  else
		   {Nyellow=1;Nred=0;Ngreen=1;Dyellow=0;Dred=1;Dgreen=1; 
			Byellow=1; Bred=0; Bgreen=1; Xyellow=0; Xred=1; 
			Xgreen=1;Kid=1;Rred=0;Rgreen=1;
	         ge1=num1%10;shi1=num1/10;ge2=num2%10;shi2=num2/10;
	         ge3=num3%10;shi3=num3/10;ge4=num4%10;shi4=num4/10;
	         xianshi();num1--;num2--; 	num3--;num4--;	
			 }
	     } //״̬6
}
	
 /************ ��HC595����һ���ֽں��� **************/
void Send_595(unsigned char dat)
{		
	unsigned char	i;
	P_HC595_OE = 0;           //hc595���ʹ��
	for(i=0; i<8; i++)
	{
		if(dat & 0x80)
		{
			P_HC595_SER   = 1;
		}
		else
		{
			P_HC595_SER   = 0;
		}		
		P_HC595_SRCLK = 1;
		P_HC595_SRCLK = 0;
		dat <<= 1;
		
	}
}
