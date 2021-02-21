#include<stdio.h>
int setA[50],setB[50],setU[50],bitA[50],bitB[50];
int unAB[50],dfAB[50],intrAB[50];
int sizeA=0,sizeB=0,sizeU=0,bA=0,bB=0;
int getSet(int a[],int b[],int size);
int printSet(int a[],int size,char);
int duplicate(int s[],int set[],int size);
int search(int);
int getBitString(int a[],int b[],int size,char ch);
void uniion(int b1[],int b2[]);
void intersect(int b1[],int b2[]);
void differ(int b1[],int b2[]);
void main()
{
	int op,s[50],i;
	char ch;
	printf("\nEnter size of universal set: ");
	scanf("%d",&sizeU);
	printf("Enter Elements : ");
	for(i=0;i<sizeU;i++){
		
		scanf("%d",&s[i]);
	}
	sizeU=duplicate(s,setU,sizeU);
	do{
	printf("\n1.Read Set A");
	printf("\n2.Read Set B");
	printf("\n3.Print Each Set");
	printf("\n4.Print Each BitString");
	printf("\n5.Union");
	printf("\n6.Intersection");
	printf("\n7.Difference");
	printf("\n8.Exit");
	printf("\nEnter Your Option : ");
	scanf("%d",&op);
	switch(op){
			case 1: read_size_A:
				printf("\nEnter The Size Of Set A : ");
				scanf("%d",&sizeA);
				if(sizeA>sizeU){
					printf("\nEnter A Size Less Than Or Equal To The Size Of Universal Set");
					goto read_size_A;
				}
				sizeA=getSet(setA,bitA,sizeA);
				break;
			case 2: read_size_B:
				printf("\nEnter The Size Of Set B : ");
				scanf("%d",&sizeB);
				if(sizeB>sizeU){
					printf("\nEnter A Size Less Than Or Equal To The Size Of Universal Set");
					goto read_size_B;
				}
				sizeB=getSet(setB,bitB,sizeB);
				break;
			case 3: 
				printf("Select set( U / A / B ) : ");
				scanf(" %c",&ch);
				if(ch=='U'||ch=='u'){
					printSet(setU,sizeU,ch);	
				}
				else if(ch=='A'||ch=='a'){
					if(printSet(setA,sizeA,ch)==0){
						printf("\n No Elements.");
					}	
				}
				else if(ch=='B'||ch=='b'){
					if(printSet(setB,sizeB,ch)==0){
						printf("\n No Elements.");
					}	
				}
				else{
					printf("\nInvalid choice..Select U or A or B\n");
	
				}
				break;
			case 4:
				printf("Select set( A / B ) : ");
				scanf(" %c",&ch);
				if(ch=='A'||ch=='a'){
					if(printSet(setA,sizeA,ch)==0){
						printf("\nNo elements.");
					}
					else{printSet(setU,sizeU,'U');bA=getBitString(setA,bitA,sizeA,ch);}	
				}
				else if(ch=='B'||ch=='b'){
					if(printSet(setB,sizeB,ch)==0){
						printf("\nNo elements.");
					}
					else{printSet(setU,sizeU,'U');bB=getBitString(setB,bitB,sizeB,ch);}	
				}
				else{
					printf("\nInvalid choice..Select A or B\n");
					
				}
				break;
			case 5: if(printSet(setA,sizeA,'A')==0||printSet(setB,sizeB,'B')==0){
					printf("\nEmpty sets...Read 2 Sets");
				}
				else if(bA==0||bB==0){
					printf("\nPlease Generate BitString First.");
				}else{
					printSet(setU,sizeU,'U');uniion(bitA,bitB);
				}
				break;
			case 6: if(printSet(setA,sizeA,'A')==0||printSet(setB,sizeB,'B')==0){
					printf("\nEmpty sets...Read 2 Sets");
				}
				else if(bA==0||bB==0){
					printf("\nPlease Generate BitString First.");
				}else{
					printSet(setU,sizeU,'U');intersect(bitA,bitB);
				}
				break;
			case 7: if(printSet(setA,sizeA,'A')==0||printSet(setB,sizeB,'B')==0){
					printf("\nEmpty sets...Read 2 Sets");
				}
				else if(bA==0||bB==0){
					printf("\nPlease Generate BitString First..");
				}else{
					printSet(setU,sizeU,'U');differ(bitA,bitB);
				}
				break;
			case 8: break;
			default: printf("Invalid Option..");
		}
	}while(op!=8);
}
int duplicate(int s[],int set[],int size){
	int j,i,c=0,f;
	for(i=0;i<size;i++){
		f=0;
		for(j=0;j<c;j++){
			if(s[i]==set[j]){f=1;break;}	
		}
		if(f==0)set[c++]=s[i];
	}return(c);
}

int getSet(int set[],int bit[],int size){
	int i,s[50];char U;
	printf("\nEnter Elements : ");
	for(i=0;i<size;i++){
		read_element:
		
		scanf("%d",&s[i]);
		if(search(s[i])==0){
			printf("\nEnter element in universal set...");
			printSet(setU,sizeU,'U');
			goto read_element;
		}
	}size=duplicate(s,set,size);
	for(i=0;i<sizeU;i++)
	{bit[i]=0;}
	return(size);
}
int search(int v){
	int i;
	for(i=0;i<sizeU;i++){
		if(setU[i]==v)return 1;	
	}
	return 0;
}
int printSet(int set[],int size,char ch){
	int i;
	if(size>0){
		if(ch=='U'||ch=='u')printf("\nUniversal Set : ");
		else if(ch=='A'||ch=='a')printf("\nSet A : ");
		else if(ch=='B'||ch=='b')printf("\nSet B : ");
		printf("{ %d ",set[0]);
		for(i=1;i<size;i++)
		{
			printf(",%d ",set[i]);		
		}
		printf("}");
		return 1;		
	}
	return 0;
}
int getBitString(int set[],int bit[],int size,char ch){
	int i,j,k;
	for(i=0;i<sizeU;i++){
		for(j=0;j<size;j++){
			if(setU[i]==set[j]){bit[i]=1;break;}
		}
	}
	if(ch=='A'||ch=='a'){printf("\nBitString Of Set A ");}
	if(ch=='B'||ch=='b'){printf("\nBitString Of Set B ");}
	printf(": { %d ",bit[0]);
	for(i=1;i<sizeU;i++)
	{
		printf(",%d ",bit[i]);		
	}
	printf("}");	
	return 1;
}
void uniion(int bitA[],int bitB[]){
	int un,j=0;
	printf("\nUnion A u B	   : { ");
	for(int i=0;i<sizeU;i++){
		un=bitA[i]|bitB[i];
		if(un==1){
		 unAB[j++]=setU[i];
		 printf("%d  ",setU[i]);}
	}
	printf("}");	
}
void intersect(int bitA[],int bitB[]){
	int in,j=0;
	printf("\nIntersection A n B : { ");
	for(int i=0;i<sizeU;i++){
		in=bitA[i]&bitB[i];
		if(in==1){
		 intrAB[j++]=setU[i];
		 printf("%d  ",setU[i]);}
	}
	printf("}");	
}
void differ(int bitA[],int bitB[]){
	int df,j=0;
	printf("\nDifference A - B   : { ");
	for(int i=0;i<sizeU;i++){
		df=bitA[i]&(!bitB[i]);
		if(df==1){
		 dfAB[j++]=setU[i];
		 printf("%d  ",setU[i]);}
	}
	printf("}");	
}