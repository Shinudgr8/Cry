#include<stdio.h>
int main(int * argc,char * argv[])
{
	if(argc < 3)
	{
		printf("\n---Usage---\n\n%s [mode] [filename] [additional info]\n\nModes---\n\n-p\tpassnumber shift cipher, passnumber as additional info\n-dec\tturn all characters to decimal\n-dta\tdecimal to ASCII\n-rl\tcharacter ciphering, one passnumber per line in key file\n-rp\tcharacter ciphering, passnumbers sparated by space\n-d\tcharacter deciphering, key file as additional info\n\n",argv[0]);
		return 0;
	}
	
	/*Shift cipher mode*/
	
	if(strcmp(argv[1],"-p")==0)
	{
		int shift,pos=0;
		char txtin[10000],txto[10000],tmp[100];
		FILE *i,*o;
		i = fopen(argv[2],"r");
		sprintf(tmp,"c_%s",argv[2]);
		o=fopen(tmp,"w");
		shift=atoi(argv[3]);
		while(fgets(txtin,10000,i) != NULL)
		{
			while(pos < strlen(txtin))
			{
				txto[pos]=(int)txtin[pos] + (int)shift;
				pos++;
			}
			fprintf(o,"%s",txto);
			memset(txtin,0,strlen(txtin));
			memset(txto,0,strlen(txto));
			pos=0;
		}
		return 0;
	}
	
	/*New line random cipher mode*/
	
	if(strcmp(argv[1],"-rl")==0)
	{
		long ran=time(NULL);
		int shift,loc=0;
		char txtin[10000],txto[10000],tmp[100];
		srand(time(NULL));
		FILE *i,*o,*s;
		i=fopen(argv[2],"r");
		sprintf(tmp,"c_%s",argv[2]);
		o=fopen(tmp,"w");
		sprintf(tmp,"s_%s",argv[2]);
		s=fopen(tmp,"w");
		while(fgets(txtin,10000,i) != NULL)
		{
			while(loc < strlen(txtin))
			{
				srand(ran);
				shift=rand() % 100;
				txto[loc]=(int)txtin[loc] + (int)shift;
				fprintf(s,"%d\n",shift);
				loc++;
				ran++;
			}
			fprintf(o,"%s",txto);
			memset(txtin,0,strlen(txtin));
			memset(txto,0,strlen(txto));
			loc =0;
		}
		fclose(i);
		fclose(o);
		fclose(s);
		return 0;
	}
	
	/*Space separated random cipher mode*/
	
	if(strcmp(argv[1],"-rp")==0)
	{
		long ran=0;
		int shift,loc=0;
		char txtin[10000],txto[10000],tmp[100];
		srand(time(NULL));
		FILE *i,*o,*s;
		i=fopen(argv[2],"r");
		sprintf(tmp,"c_%s",argv[2]);
		o=fopen(tmp,"w");
		sprintf(tmp,"s_%s",argv[2]);
		s=fopen(tmp,"w");
		while(fgets(txtin,10000,i) != NULL)
		{
			while(loc < strlen(txtin))
			{
				srand(ran);
				shift=rand() % 100;
				txto[loc]=(int)txtin[loc] + (int)shift;
				fprintf(s,"%d ",shift);
				loc++;
				ran++;
			}
			fprintf(o,"%s",txto);
			memset(txtin,0,strlen(txtin));
			memset(txto,0,strlen(txto));
			loc =0;
		}
		fclose(i);
		fclose(o);
		fclose(s);
		return 0;
	}
	
	/*line separated random decipherer*/
	if(strcmp(argv[1],"-d")==0)
	{
		int shift,pos;
		char txtin[10000],txto[10000],tmp[100],num[5];
		FILE *i,*o,*s;
		i= fopen(argv[2],"r");
		sprintf(tmp,"c_%s",argv[2]);
		o=fopen(tmp,"w");
		s=fopen(argv[3],"r");
		while(fgets(txtin,10000,i) != NULL)
		{
			while(pos < strlen(txtin))
			{
				fgets(num,5,s);
				shift=atoi(num);
				memset(num,0,strlen(num));
				txto[pos]=(int)txtin[pos] - (int)shift;
				pos++;
			}
			fprintf(o,"%s",txto);
			memset(txtin,0,strlen(txtin));
			memset(txto,0,strlen(txto));
			pos=0;
		}
		fclose(i);
		fclose(o);
		fclose(s);
		return 0;
	}
	/*Characters to decimal*/
	if(strcmp(argv[1],"-dec")==0)
	{
		int cou=0,ch;
		char txtin[1000],txto[1000],tmp[50];
		FILE *in,*ou;
		in=fopen(argv[2],"r");
		sprintf(tmp,"c_%s",argv[2]);
		ou=fopen(tmp,"w");
		while(fgets(txtin,1000,in) != NULL)
		{
			while(cou < strlen(txtin))
			{
				ch=(int)txtin[cou];
				fprintf(ou,"%d\n",ch);
				cou++;
				ch=0;
			}
		}
		fclose(in);
		fclose(ou);
		return 0;
	}
	/*Decimal to ASCII*/
	if(strcmp(argv[1],"-dta")==0)
	{
		FILE *in,*ou;
		char tmp[50],nu[10];
		in=fopen(argv[2],"r");
		sprintf(tmp,"c_%s",argv[2]);
		ou=fopen(tmp,"w");
		while(fgets(nu,10,in) != NULL)
		{
			fprintf(ou,"%c",atoi(nu));
		}
		fclose(in);
		fclose(ou);
		return 0;
	}
}
