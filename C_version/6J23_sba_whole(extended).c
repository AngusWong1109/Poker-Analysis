#include<stdio.h>
#include<time.h>
#define size1 5 //5 cards
#define size2 4 //4 cards
int computer=1000 /*Computer's money'*/, player=1000 /*Player's money'*/, bettingpool=0 /*Money on betting pool*/;
int playerhand[size1]/*Player's card'*/, computerhand[size1]/*Computer's card*/, card[52]/*All cards*/, pla/*Number, which is the categories of player's card*/, com /*Number, which is the categories of computer's card*/;
void random(int [], int [], int []); /*Function: distribute cards to player and computer randomly*/
void copyarray(int [], int [], int); /*Function: copy the array once again to prevent making any change of the inputting array*/
void printno(int); /*Function: print out the number of the card*/
void printsuit(int); /*Function: print out the suit of the card*/
void printHand(int [], int); /*Function: print out the number of card, which was inputted*/
void sorting(int [], int); /*Bubble sort*/ /*Function: sort the card with the ascending order according to the number representitive*/
void swap (int *, int*); /*Function: swap the card which mainly used in the sorting function*/ /*Pass by reference*/
void sortByNum(int [], int); /*Function: sort the card with ascending order by the card number*/
void ctn(int [], int); //ctn=Change To Number /*Function: change the card to the number, which is used for determining the categories of the cards*/
void cts(int [], int); //Change To Suit /*Function: change the card to suit, which is used for determining the categories of the cards*/
//////////////////////////////
//Card checking for 5 cards
//////////////////////////////
int isStraight(int []); /*Function: check whether the card is a straight or not*/
int isFlush(int []); /*Function: check whehter the card is a flush or not*/
int isPair(int []); /*Function: check whether the card is in the categories of pairs or not*/
int isRoyalFlush(int []); /*Function: check whether the card is royal flush or not*/
int isStraightFlush(int []); /*Function: check whether the card is straight flush or not*/
int isfoak(int []); //foak=four of a kind /*Function: check whether the card is four of a kind or not*/
int isfh(int []); //fh=fullhouse /*Function: check whether the card is fullhouse or not*/
int istoak(int []); //toak=three of a kind /*Function: check whether the card is three of a kind or not*/
int istp(int []); //tp=two pairs /*Function: check whether the card is two pairs or not*/
int isop(int []); //op=one pair /*Function: check whether the card is one pair or not*/
int issfph(int []); //issfph=is straight, is flush, is pair, is high card /*Function: Check the cards is straight or flush or pair or high card */
int carddivision(int []); /*Function: To check which is the categories of the cards*/
int comparation(int); /*Function: compare with the other card when they have got the same categories of cards*/
//////////////////////////////
//Card comparing
//Use when both playerhand and computerhand have got the same category of card
//////////////////////////////
//comfor=compare for
int comforstraightflush(int [], int []); /*compare for straight flush*/
int comforfoak(int [], int []); //foak=four of a kind /*compare for four of a kind*/
int comforfh(int [], int []); //fh=flush /*compare for fullhouse*/
int comforflush(int [], int []); /*compare for flush*/
int comforstraight(int [], int []); /*compare for straight*/
int comfortoak(int [], int []); //toak=three of a kind /*compare for three of a kind*/
int comfortp(int [], int []); //tp=two pairs /*compare for two pairs*/
int comforop(int [], int []); //op=one pair /*compare for one pair*/
int comforhc(int [], int []); //hc=high card /*compare for high card*/
//////////////////////////////
//Card checking for 4 cards
//////////////////////////////
//p1= probabilty 1, p2=probability 2
//////////////////////////////
//Function to check whether the card is royal flush or not
int isRoyalFlush4(int []); /*Function: Check whether the card satisfy isRoyalFlushp1 and isRoyalFlushp2*/
int isRoyalFlush4p1(int []);
int isRoyalFlush4p2(int []);
//////////////////////////////
//Function to check whether the card is straight flush or not
int isStraightFlush4(int []); /*Function: Check whether the card satisfy isStraightFlushp1 and isStraightFlushp2*/
int isStraightFlush4p1(int []);
int isStraightFlush4p2(int []);
//////////////////////////////
//Function to check whether the card is four of a kind or not
//foak=four of a kind
int isfoak4(int []);
//////////////////////////////
//Function to check whether the card is fullhouse or not
//fh=fullhouse
int isfh4(int []); /*Function: Check whether the card satisfy isfhp1 and isfhp2*/
int isfh4p1(int []);
int isfh4p2(int []);
//////////////////////////////
//Function to check whether the card is flush or not
int isFlush4(int []);
//////////////////////////////
//Function to check whether the card is straight or not
int isStraight4(int []); /*Function: Check whether the card satisfy isStraightp1 and isStraightp2*/
int isStraight4p1(int []);
int isStraight4p2(int []);
//////////////////////////////
//toak=three of a kind
//Function to check whether the card is three of a kind or not
int istoak4(int []);
//////////////////////////////
//tp=two pairs
//Function to check whether the card is two pairs or not
int istp4(int []);
//////////////////////////////
//Function to check whether who will be the winner at last
int whoWin(int [], int []); /*Function: To see who has a greater number got in carddivision or comparasion*/
//////////////////////////////
int whoBet(int [], int []); /*To see who has a higher chance to win*/
int carddivision4(int []);
//////////////////////////////
int dependson(int); /*Function: To deciside whether the computer will follow or not when player has a higher chance to win*/
int comparation4(int);
int comforstraightflush4(int [], int []);
int comforfoak4(int [], int []);
int comforfh4(int [], int []);
int comforflush4(int [], int []);
int comforstraight4(int [], int []);
int comfortoak4(int [], int []);
int comfortp4(int [], int []);
int comforop4(int [], int []);
//////////////////////////////
int playerBet(int);
int computerBet(int);
//////////////////////////////
main(){
	int i, a[size2], b[size2], x, y, c=0, ph, ch;;
	copyarray(a, playerhand, size2);
	copyarray(b, computerhand, size2);
	printf("                                                        Game Menu                                              \n");
	for(i=1; i<=26; i++){
		printf("\n");
	}
	printf("                                                        Show Hand                                              \n");
	printf("                                             Press any key to start the game                                   \n");
	system("pause");
	for(i=1; i<=30; i++){
		printf("\n");
	}
	printf("Gameplay:\n");
	printf("Statement denying: In this game, A2345 is not a straight.\n\n");
	printf("This program is a card game\n\n");
	printf("In this game, there are 10 categories for the card, which is royal flush, straight flush, four of a kind, \n\nfullhouse, flush, straight, three of a kind, two pairs, one pair and high card\n\n");
	printf("And the order is: royal flush > straight flush > four of a kind > fullhouse > flush > straight > three of a kind > \n\ntwo pairs > one pair > high card\n\n");
	printf("Rules:\n\n");
	printf("You could only input integer when you enter the bet value\n");
	printf("\nAnd now we will start the game");
	for(i=1; i<=12; i++){
		printf("\n");
	}
	system("pause");
	for(i=1; i<=30; i++){
		printf("\n");
	}
	for(i=0; i<52; i++){
		card[i]=i+1;
	}
	random(card, playerhand, computerhand);
	while(c==0){
		printf("Computer: %d, You: %d, Betting Pool: %d\n", computer, player, bettingpool);
		printf("----------------------First round----------------------\n");
		printf("Computer Hand showing on table:\n?? ");
		printHand(computerhand, 1);
		printf("\nYour Hand showing on table:\n?? ");
		printHand(playerhand, 1);
		printf("\n\nYour Hand (only you know):\n");
		printsuit(playerhand[0]);
		printno(playerhand[0]);
		printsuit(playerhand[4]);
		printno(playerhand[4]);
		if(playerhand[0]>computerhand[0]){
			c=playerBet(0);
		}
		else{
			c=computerBet(0);
		}
		if(c==1){
				break;
		}
		printf("\n----------------------Second round----------------------\n");
		printf("Computer Hand showing on table:\n?? ");
		printHand(computerhand, 2);
		printf("\nYour Hand showing on table:\n?? ");
		printHand(playerhand, 2);
		printf("\n\nYour Hand (only you know):\n");
		printsuit(playerhand[0]);
		printno(playerhand[0]);
		printsuit(playerhand[1]);
		printno(playerhand[1]);
		printsuit(playerhand[4]);
		printno(playerhand[4]);
		int playerhand2[2], computerhand2[2];
		copyarray(playerhand2, playerhand, 2);
		copyarray(computerhand2, computerhand, 2);
		ctn(playerhand2, 2);
		ctn(computerhand2, 2);
		if(playerhand2[1]==playerhand2[0]&&computerhand2[1]==computerhand2[0]){
			if(playerhand2[1]>computerhand2[1]){
				c=playerBet(1);
			}
			else if(computerhand2[1]>playerhand2[1]){
				c=computerBet(1);
			}
			else if(computerhand2[1]==playerhand2[1]){
				if(playerhand[0]>playerhand[1]){
					ph=playerhand[0];
				}
				else if(playerhand[1]>playerhand[0]){
					ph=playerhand[1];
				}
				if(computerhand[0]>computerhand[1]){
					ch=computerhand[0];
				}
				else if(computerhand[1]>computerhand[0]){
					ch=computerhand[1];
				}
				if(ph>ch){
					c=playerBet(1);
				}
				else if(ch>ph){
					c=computerBet(1);
				}
			}
		}
		else if(playerhand[1]>computerhand[1]){
			c=playerBet(1);
		}
		else if(computerhand[1]>playerhand[1]){
			c=computerBet(1);
		}
		if(c==1){
			break;
		}
		printf("\n----------------------Third round----------------------\n");
		printf("Computer Hand showing on table:\n?? ");
		printHand(computerhand, 3);
		printf("\nYour Hand showing on table:\n?? ");
		printHand(playerhand, 3);
		printf("\n\nYour Hand (only you know):\n");
		printsuit(playerhand[0]);
		printno(playerhand[0]);
		printsuit(playerhand[1]);
		printno(playerhand[1]);
		printsuit(playerhand[2]);
		printno(playerhand[2]);
		printsuit(playerhand[4]);
		printno(playerhand[4]);
		int playerhand3[3], computerhand3[3];
		copyarray(playerhand3, playerhand, 3);
		copyarray(computerhand3, computerhand, 3);
		ctn(computerhand3, 3);
		ctn(playerhand3,3);
		sortByNum(playerhand3, 3);
		sortByNum(computerhand3, 3);
		int i, flag1=0, flag2=0, ph1, ch1, j, k;
		for(i=0; i<3; i++){
			if(playerhand3[i]==playerhand3[i+1]){
				flag1++;
				j=i+1;
			}
		}
		if(flag1==2){
			ph=playerhand3[2];
		}
		else if(flag1==1){
			ph1=playerhand3[1];
		}
		for(i=0; i<3; i++){
			if(computerhand3[i]==computerhand3[i+1]){
				flag2++;
				k=i+1;
			}
		}	
		if(flag2==2){
			ch=computerhand3[2];
		}
		else if(flag2==1){
			ch1=computerhand3[1];
		}
		if(flag1==2&&flag2==2){
			if(ph>ch){
				c=playerBet(2);
			}
			else if(ph<ch){
				c=computerBet(2);
			}
		}
		else if(flag1==1&&flag2==1){
			if(ph1>ch1){
				c=playerBet(2);
			}
			else if(ph1<ch1){
				c=computerBet(2);
			}
			else if(ph1==ch1){
				if(playerhand[j]>computerhand[k]){
					c=playerBet(2);
				}
				else{
					c=computerBet(2);
				}
			}
			else{
				if(playerhand[2]>computerhand[2]){
					c=playerBet(2);
				}
				else{
					c=computerBet(2);
				}
			}
			if(c==1){
				break;
			}
		}
		printf("\n----------------------Fourth round----------------------\n");
		printf("Computer Hand showing on table:\n?? ");
		printHand(computerhand, size2);
		printf("\nYour Hand showing on table:\n?? ");
		printHand(playerhand, size2);
		printf("\n\nYour Hand (only you know):\n");
		printHand(playerhand, size1);
		x=whoBet(a, b);
		if(x==1){
			c=playerBet(3);
		}
		else if(x==2){
			c=computerBet(3);
		}
		printf("\nYour card: ");
		sorting(playerhand, size1);
		printHand(playerhand, size1);
		printf("\nComputer card: ");
		sorting(computerhand, size1);
		printHand(computerhand, size1);
		printf("\n");
		if(whoWin(playerhand, computerhand)==1){
			printf("You win");
		}
		else{
			printf("Computer win");
		}
		break;
	}
	printf("\nEnd game.");
	system("pause");
}
void random(int card[], int player[], int computer[]){
	int i, j, p, q;
	srand(time(NULL));
	for(i=1; i<=100; i++){
		do{
			p=rand()%52;
			q=rand()%52;
		}while(p==q);
		swap(&card[p],&card[q]);
	}
	for(j=0; j<size1; j++){
		player[j]=card[j];
		computer[j]=card[5+j];
	}
}
void copyarray(int a[], int b[], int x){ //(copy to, copy from, number of integers)
	int i;
	for(i=0; i<x; i++){
		a[i]=b[i];
	}
}
void printno(int a){
	while(a>13){
		a-=13;
	}
	if(a==13){
		printf("A");
	}
	else if(a==12){
		printf("K");
	}
	else if(a==11){
		printf("Q");
	}
	else if(a==10){
		printf("J");
	}
	else{
		printf("%d", ++a);
	}
}
void printsuit(int a){
	if(a>=1 && a<=13){
		printf("%c", 04);
	}
	else if(a>=14 && a<=26){
		printf("%c", 05);
	}
	else if(a>=27 && a<=39){
		printf("%c", 03);
	}
	else{
		printf("%c", 06);
	}
}
void printHand(int a[], int x){
	int i;
	for(i=0; i<x; i++){
		printsuit(a[i]);
		printno(a[i]);
		printf(" ");
	}
}
void sorting(int a[], int x){
	int i, j;
	for(i=0; i<=x-2; i++){
		for(j=0; j<=x-i-2; j++){
			if(a[j]>a[j+1]){
				swap(&a[j], &a[j+1]);
			}
		}
	}
}
void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sortByNum(int a[], int x){
	int i, j, hand[x];
	copyarray(hand, a, x);
	ctn(hand, x);
	sorting(a, x);
}
void ctn(int a[], int x){
	int i;
	for(i=0; i<x; i++){
		while(a[i]>13){
			a[i]-=13;
		}
	}
}
void cts(int a[], int x){
	int i;
	for(i=0; i<x; i++){
		if(a[i]>=1 && a[i]<=13){
			a[i]=1;
		}
		else if(a[i]>=14 && a[i]<=26){
			a[i]=2;
		}
		else if(a[i]>=27 && a[i]<=39){
			a[i]=3;
		}
		else{
			a[i]=4;
		}
	}
}
int isStraight(int a[]){
	int i, b[size1], flag=0;
	copyarray(b, a, size1);
	sortByNum(b, size1);
	ctn(b, size1);
	for(i=0; i<size1; i++){
		if(b[i]+1==b[i+1]){
			flag++;
		}
	}
	if(flag==4){
		return 1;
	}
	else{
		return 0;
	}
}
int isFlush(int a[]){
	int i, b[size1], flag=0;
	copyarray(b, a, size1);
	cts(b, size1);
	for(i=0; i<size1; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag==4){
		return 1;
	}
	else{
		return 0;
	}
}
int isPair(int a[]){
	int i, b[size1], flag=0;
	copyarray(b, a, size1);
	ctn(b, size1);
	sorting(b, size1);
	for(i=0; i<size1; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag>=1){
		return 1;
	}
	else{
		return 0;
	}
}
int isRoyalFlush(int a[]){
	int i, flag=0;
	sortByNum(a, size1);
	for(i=0; i<size1; i++){
		if(a[i]>=48&&a[i]<=52){
			flag++;
		}
	}
	if(flag==5){
		return 1;
	}
	else{
		return 0;
	}
}
int isStraightFlush(int a[]){
	int b[size1], i, flag=0;
	copyarray(b, a, size1);
	cts(b, size1);
	for(i=0; i<size1; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag==4&&isStraight(a)){
		return 1;
	}
	else{
		return 0;
	}
}
int isfoak(int a[]){
	int b[size1], i=0, x=0, flag=0;
	copyarray(b, a, size1);
	sortByNum(b, size1);
	ctn(b, size1);
	while(i<size1 && x==0){
		if(b[i]==b[i+1]){
			x=b[i];
		}
		i++;
	}
	for(i=0; i<size1; i++){
		if(b[i]==b[i+1]&&b[i]==x){
			flag++;
		}
	}
	if(flag==3){
		return 1;
	}
	else{
		return 0;
	}
}
int isfh(int a[]){
	int b[size1], i=0, x=0, y, flag1=0, flag2=0;
	copyarray(b, a, size1);
	ctn(b, size1);
	sorting(b, size1);
	if((b[0]==b[1]&&b[2]==b[4])||(b[0]==b[2]&&b[3]==b[4])){
		return 1;
	}
	else{
		return 0;
	}
}
int istoak(int a[]){
	int b[size1], i=0, x=0, y, flag=0;
	copyarray(b, a, size1);
	ctn(b, size1);
	sorting(b, size1);
	while(i<size1&&x==0){
		if(b[i]==b[i+1]){
			x=b[i];
		}
		i++;
	}
	for(i=0; i<size1; i++){
		if(b[i]==x){
			flag++;
		}
	}
	if(flag==2){
		return 1;
	}
	else{
		return 0;
	}
}
int istp(int a[]){
	int b[size1], i=0, j, x=0, y=0, flag1=0, flag2=0;
	copyarray(b, a, size1);
	ctn(b, size1);
	sorting(b, size1);
	while(i<size1&&x==0){
		if(b[i]==b[i+1]){
			x=b[i];
			y=i+2;
		}
		i++;
	}
	for(i=0; i<size1; i++){
		if(b[i]==b[i+1]&&b[i]==x){
			flag1++;
		}
		else if(b[i]==b[y]){
			flag2++;
		}
		else if(b[i]==b[y+1]){
			flag2++;
		}
	}
	if(flag1==1&&flag2==2){
		return 1;
	}
	else{
		return 0;
	}
}
int isop(int a[]){
	int b[size1], i, flag=0;
	copyarray(b, a, size1);
	ctn(b, size1);
	sorting(b, size1);
	for(i=0; i<size1; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag==1){
		return 1;
	}
	else{
		return 0;
	}
}
int issfph(int a[]){ //Determine it is Straight, Flush, Pair or High card
	if(isStraight(a)){
		return 4;
	}
	else if(isFlush(a)){
		return 3;
	}
	else if(isPair(a)){
		return 2;
	}
	else{
		return 1;
	}
}
int carddivision(int a[]){ //Divide the card according the categories
	if(issfph(a)==4){
		if(isRoyalFlush(a)){
			return 10;
		}
		else if(isStraightFlush(a)){
			return 9;
		}
		else{
			return 5;
		}
	}
	else if(issfph(a)==3){
		return 6;
	}
	else if(issfph(a)==2){
		if(isfoak(a)){
			return 8;
		}
		else if(isfh(a)){
			return 7;
		}
		else if(istoak(a)){
			return 4;
		}
		else if(istp(a)){
			return 3;
		}
		else if(isop(a)){
			return 2;
		}
	}
	else{
		return 1;
	}
}
int comparation(int x){
	if(x==10){
		printf("Draw");
	}
	else if(x==9){
		return comforstraightflush(playerhand, computerhand);
	}
	else if(x==8){
		return comforfoak(playerhand, computerhand);
	}
	else if(x==7){
		return comforfh(playerhand, computerhand);
	}
	else if(x==6){
		return comforflush(playerhand, computerhand);
	}
	else if(x==5){
		return comforstraight(playerhand, computerhand);
	}
	else if(x==4){
		return comfortoak(playerhand, computerhand);
	}
	else if(x==3){
		return comfortp(playerhand, computerhand);
	}
	else if(x==2){
		return comforop(playerhand, computerhand);
	}
	else{
		return comforhc(playerhand, computerhand);
	}
}
//////////////////////////////
//Comparation between player and computer
//return 1, player win; return 2, computer win
int comforstraightflush(int a[], int b[]){
	int c[size1], d[size1];
	sortByNum(a, size1);
	sortByNum(b, size1);
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	if(c[4]>d[4]){
		return 1;
	}
	else if(c[4]<d[4]){
		return 2;
	}
	else if(a[4]>b[4]){
		return 1;
	}
	else{
		return 2;
	}
}
int comforfoak(int a[], int b[]){
	int c[size1], d[size1], i, x, y;
	sortByNum(a, size1);
	sortByNum(b, size1);
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	for(i=0; i<size1; i++){
		if(c[i]==c[i+1]){
			x=c[i];
		}
		if(d[i]==d[i+1]){
			y=d[i];
		}
	}
	if(x>y){
		return 1;
	}
	else{
		return 2;
	}
}
int comforfh(int a[], int b[]){
	int c[size1], d[size1], i, x, y, flag1=0, flag2=0;
	sortByNum(a, size1);
	sortByNum(b, size1);
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	for(i=0; i<size1; i++){
		if(c[i]==c[0]){
			flag1++;
		}
		if(d[i]==d[0]){
			flag2++;
		}
	}
	if(flag1==2){
		x=c[0];
	}
	else if(flag1!=2){
		x=c[2];
	}
	if(flag2==2){
		y=d[0];
	}
	else if(flag2!=2){
		y=d[2];
	}
	if(x>y){
		return 1;
	}
	else{
		return 2;
	}
}
int comforflush(int a[], int b[]){
	int c[size1], d[size1], e[size1], f[size1], i;
	sortByNum(a, size1);
	sortByNum(b, size1);
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	copyarray(e, a, size1);
	copyarray(f, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	cts(e, size1);
	cts(f, size1);
	for(i=size1-1; i>=0; i--){
		if(c[i]>d[i]){
			return 1;
			break;
		}
		else if(d[i]>c[i]){
			return 2;
			break;
		}
		else if(c[i]==d[i]&&i==0){
			if(e[0]>f[0]){
				return 1;
			}
			else{
				return 2;
			}
		}
	}
}
int comforstraight(int a[], int b[]){
	int c[size1], d[size1];
	sortByNum(a, size1);
	sortByNum(b, size1);
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	if(c[4]>d[4]){
		return 1;
	}
	else if(c[4]<d[4]){
		return 2;
	}
	else if(c[4]==d[4]){
		if(a[4]>b[4]){
			return 1;
		}
		else{
			return 2;
		}
	}
}
int comfortoak(int a[], int b[]){
	int c[size1], d[size1], i, x, y;
	sortByNum(a, size1);
	sortByNum(b, size1);
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	for(i=0; i<size1; i++){
		if(c[i]==c[i+1]){
			x=c[i];
		}
		if(d[i]==d[i+1]){
			y=d[i];
		}
	}
	if(x>y){
		return 1;
	}
	else{
		return 2;
	}
}
int comfortp(int a[], int b[]){
	int c[size1], d[size1], i=size2, x=0, y=0, j, k;
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	sorting(c, size1);
	sorting(d, size1);
	while(i>=0&&x==0){
		if(c[i]==c[i-1]){
			x=c[i];
			j=i;
		}
		i--;
	}
	i=size2;
	while(i>=0&&y==0){
		if(d[i]==d[i-1]){
			y=d[i];
			k=i;
		}
		i--;
	}
	if(x>y){
		return 1;
	}
	else if(x<y){
		return 2;
	}
	else if(x==y){
		if(a[j]>b[k]){
			return 1;
		}
		else{
			return 2;
		}
	}
}
int comforop(int a[], int b[]){
	int c[size1], d[size1], i, j, k, x, y;
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	sorting(c, size1);
	sorting(d, size1);
	for(i=0; i<size1; i++){
		if(c[i]==c[i+1]){
			x=c[i];
			j=i+1;
		}
		if(d[i]==d[i+1]){
			y=d[i];
			k=i+1;
		}
	}
	if(x>y){
		return 1;
	}
	else if(x<y){
		return 2;
	}
	else{
		if(a[j]>b[k]){
			return 1;
		}
		else{
			return 2;
		}
	}
}
int comforhc(int a[], int b[]){
	int c[size1], d[size1], i;
	sortByNum(a, size1);
	sortByNum(b, size1);
	copyarray(c, a, size1);
	copyarray(d, b, size1);
	ctn(c, size1);
	ctn(d, size1);
	for(i=size2; i>=0; i--){
		if(c[i]>d[i]){
			return 1;
			break;
		}
		else if(c[i]<d[i]){
			return 2;
			break;
		}
		else if(c[i]==d[i] && i==0){
			if(a[4]>b[4]){
				return 1;
			}
			else{
				return 2;
			}
		}
	}
}
int isRoyalFlush4(int a[]){
	if(isRoyalFlush4p1(a)||isRoyalFlush4p2(a)){
		return 1;
	}
	else{
		return 0;
	}
}
int isRoyalFlush4p1(int a[]){
	int i, flag=0;
	sortByNum(a, size2);
	for(i=0; i<size2; i++){
		if((a[i]+1==a[i+1])&&(a[i]>=48&&a[i]<=52)){
			flag++;
		}
	}
	if(flag==3){
		return 1;
	}
	else{
		return 0;
	}
}
int isRoyalFlush4p2(int a[]){
	int x=0, i, flag=0;
	sortByNum(a, size2);
	for(i=0; i<size2; i++){
		if((a[i]+1==a[i+1])&&(a[i]>=48&&a[i]<=52)){
			flag++;
		}
		else if(a[i]+2==a[i+1]&&(a[i]>=48&&a[i]<=52)){
			flag++;
			x++;
		}
	}
	if(flag==3&&x==1){
		return 1;
	}
	else{
		return 0;
	}
}
int isStraightFlush4(int a[]){
	if(isStraightFlush4p1(a)||isStraightFlush4p2(a)){
		return 1;
	}
	else{
		return 0;
	}
}
int isStraightFlush4p1(int a[]){
	int b[size2], c[size2], i, flag=0;
	sortByNum(a, size2);
	copyarray(b, a, size2);
	copyarray(c, a, size2);
	ctn(b, size2);
	cts(c, size2);
	for(i=0; i<size2; i++){
		if(b[i]+1==b[i+1]&&c[i]==c[i+1]){
			flag++;
		}
	}
	if(flag==3){
		return 1;
	}
	else{
		return 0;
	}
}
int isStraightFlush4p2(int a[]){
	int i, flag=0, x=0, b[size2], c[size2];
	sortByNum(a, size2);
	copyarray(b, a, size2);
	copyarray(c, a, size2);
	ctn(b, size2);
	cts(c, size2);
	for(i=0; i<size2; i++){
		if(b[i]+1==b[i+1]&&c[i]==c[i+1]){
			flag++;
		}
		else if(b[i]+2==b[i+1]&&c[i]==c[i+1]){
			flag++;
			x++;
		}
	}
	if(flag==3&&x==1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfoak4(int a[]){
	int b[size2], i, flag=0;
	copyarray(b, a, size2);
	ctn(b, size2);
	for(i=0; i<size2; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag>=2){
		return 1;
	}
	else{
		return 0;
	}
}
int isfh4(int a[]){
	if(isfh4p1(a)||isfh4p2(a)){
		return 1;
	}
	else{
		return 0;
	}
}
int isfh4p1(int a[]){
	int b[size2], i, flag=0;
	sortByNum(a, size2);
	copyarray(b, a, size2);
	ctn(b, size2);
	sorting(b, size2);
	for(i=0; i<size2; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag==2){
		return 1;
	}
	else{
		return 0;
	}
}
int isfh4p2(int a[]){
	int b[size2], i=0, j, l, flag1=0, flag2=0, x=0;
	copyarray(b, a, size2);
	ctn(b, size2);
	sortByNum(b, size2);
	while(i<=4&&x==0){
		if(b[i]==b[i+1]){
			flag1++;
			x=b[i];
		}
		i++;
	}
	for(l=i; l<size2; l++){
		if(b[l]==b[l+1]&&b[l]==x){
			flag1++;
		}
		else if(b[l]==b[l+1]){
			flag2++;
		}
	}
	if(flag1==1&&flag2==1){
		return 1;
	}
	else{
		return 0;
	}
}
int isFlush4(int a[]){
	int b[size2], i, flag=0;
	copyarray(b, a, size2);
	cts(b, size2);
	for(i=0; i<size2; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag==3){
		return 1;
	}
	else{
		return 0;
	}
}
int isStraight4(int a[]){
	if(isStraight4p1(a)||isStraight4p2(a)){
		return 1;
	}
	else{
		return 0;
	}
}
int isStraight4p1(int a[]){
	int b[size2], i, flag=0;
	copyarray(b, a, size2);
	ctn(b, size2);
	sortByNum(b, size2);
	for(i=0; i<size2; i++){
		if(b[i]+1==b[i+1]){
			flag++;
		}
	}
	if(flag==3){
		return 1;
	}
	else{
		return 0;
	}
}
int isStraight4p2(int a[]){
	int b[size2], i, x=0, flag=0;
	copyarray(b, a, size2);
	ctn(b, size2);
	sortByNum(b, size2);
	for(i=0; i<size2; i++){
		if(b[i]+1==b[i+1]){
			flag++;
		}
		else if(b[i]+2==b[i+1]){
			flag++;
			x++;
		}
	}
	if(flag==3&&x==1){
		return 1;
	}
	else{
		return 0;
	}
}
int istoak4(int a[]){
	int b[size2], i, flag=0;
	copyarray(b, a, size2);
	ctn(b, size2);
	sortByNum(b, size2);
	for(i=0; i<size2; i++){
		if(b[i]==b[i+1]){
			flag++;
		}
	}
	if(flag>=1&&flag<3){
		return 1;
	}
	else{
		return 0;
	}
}
int istp4(int a[]){
	int b[size2], i=0, flag=0, x=0, y;
	copyarray(b, a, size2);
	ctn(b, size2);
	sortByNum(b, size2);
	while(i==0&&x==0){
		if(b[i]==b[i+1]){
			x=b[i];
			flag++;
			y=++i;
		}
		i++;
	}
	for(i=y; i<size2; i++){
		if(b[i]==b[i+1]&&b[i]==x){
			flag=0;
		}
		if(b[i]==b[i+1]&&b[i]!=x){
			flag++;
		}
	}
	if((b[0]==b[1]&&b[2]==b[3])||flag==1){
		return 1;
	}
	else{
		return 0;
	}
}
int whoWin(int a[], int b[]){
	int x, y;
	x=carddivision(a);
	y=carddivision(b);
	if(x>y){
		return 1;
	}
	else if(x<y){
		return 2;
	}
	else if(x==y){
		return comparation(x);
	}
}
int carddivision4(int a[]){
	if(isRoyalFlush4(a)){
		return 10;
	}
	else if(isStraightFlush4(a)){
		return 9;
	}
	else if(isfoak4(a)){
		return 8;
	}
	else if(isfh4(a)){
		return 7;
	}
	else if(isFlush4(a)){
		return 6;
	}
	else if(isStraight4(a)){
		return 5;
	}
	else if(istoak4(a)){
		return 4;
	}
	else if(istp4(a)){
		return 3;
	}
	else{
		return 2;
	}
}
int whoBet(int a[], int b[]){
	int x, y, i, j;
	pla=carddivision4(a);
	com=carddivision4(b);
	if(pla>com){
		return 1;
	}
	else if(pla<com){
		return 2;
	}
	else{
		return comparation4(pla);
	}
}
int dependson(int x){ //return 1, don't follow. return 2, follow
	if((playerhand[x]-computerhand[x])>=26){
		return 1;
	}
	else{
		return 2;
	}
}
int comforstraightflush4(int a[], int b[]){
	int i, c[size2], d[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	sortByNum(c, size2);
	sortByNum(d, size2);
	ctn(c, size2);
	ctn(d, size2);
	for(i=size2; i>=0; i--){
		if(c[i]==d[i]&&i==0){
			if(a[3]>b[3]){
				return 1;
			}
			else{
				return 2;
			}
		}
		else if(c[3]>d[3]){
			return 1;
		}
		else if(c[3]<d[3]){
			return 2;
		}
	}
}
int comforfoak4(int a[], int b[]){
	int i=0, x=0, y=0, c[size2], d[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	sortByNum(c, size2);
	sortByNum(d, size2);
	ctn(c, size2);
	ctn(d, size2);
	while(i<size2&&x==0){
		if(c[i]==c[i+1]){
			x=c[i];
		}
		i++;
	}
	i=0;
	while(i<size2&&y==0){
		if(d[i]==d[i+1]){
			y=d[i];
		}
		i++;
	}
	if(x>y){
		return 1;
	}
	else{
		return 2;
	}
}
int comforfh4(int a[], int b[]){
	int x, y, c[size2], d[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	ctn(c, size2);
	ctn(d, size2);
	sorting(c, size2);
	sorting(d, size2);
	if(c[0]==c[2]){
		x=c[0];
	}
	else if(c[2]==c[4]){
		x=c[2];
	}
	if(d[0]==d[2]){
		y=d[0];
	}
	else if(d[2]==d[4]){
		y=d[2];
	}
	if(x>y){
		return 1;
	}
	else{
		return 2;
	}
}
int comforflush4(int a[], int b[]){
	int i, c[size2], d[size2], e[size2], f[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	copyarray(e, a, size2);
	copyarray(f, b, size2);
	sortByNum(c, size2);
	sortByNum(d, size2);
	ctn(c, size2);
	ctn(d, size2);
	cts(e, size2);
	cts(f, size2);
	for(i=size2-1; i>=0; i--){
		if(c[i]==d[i]&&i==0){
			if(e[0]>f[0]){
				return 1;
			}
			else{
				return 2;
			}
		}
		else if(c[i]>d[i]){
			return 1;
			break;
		}
		else{
			return 2;
			break;
		}
	}
}
int comforstraight4(int a[], int b[]){
	int i, c[size2], d[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	sortByNum(c, size2);
	sortByNum(d, size2);
	ctn(c, size2);
	ctn(d, size2);
	for(i=size2-1; i>=0; i--){
		if(c[i]==d[i]&&i==0){
			if(a[3]>b[3]){
				return 1;
			}
			else{
				return 2;
			}
		}
		else if(c[i]>d[i]){
			return 1;
		}
		else if(c[i]<d[i]){
			return 2;
		}
	}
}
int comfortoak4(int a[], int b[]){
	int i, x, y, c[size2], d[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	sortByNum(c, size2);
	sortByNum(d, size2);
	ctn(c, size2);
	ctn(d, size2);
	for(i=0; i<size2; i++){
		if(c[i]>c[i+1]){
			x=c[i];
			break;
		}
		if(d[i]==d[i+1]){
			y=d[i];
			break;
		}
	}
	if(x>y){
		return 1;
	}
	else{
		return 2;
	}
}
int comfortp4(int a[], int b[]){
	int i, x, y, c[size2], d[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	sortByNum(c, size2);
	sortByNum(d, size2);
	ctn(c, size2);
	ctn(d, size2);
	for(i=0; i<size2; i++){
		if(c[i]==c[i+1]){
			x=c[i];
		}
		if(d[i]==d[i+1]){
			y=d[i];
		}
	}
	if(x>y){
		return 1;
	}
	else{
		return 2;
	}
}
int comforop4(int a[], int b[]){
	int c[size2], d[size2];
	copyarray(c, a, size2);
	copyarray(d, b, size2);
	sortByNum(c, size2);
	sortByNum(d, size2);
	ctn(c, size2);
	ctn(d, size2);
	if(c[3]>d[3]){
		return 1;
	}
	else if(c[3]==d[3]){
		if(a[3]>b[3]){
			return 1;
		}
		else{
			return 2;
		}
	}
	else{
		return 2;
	}
}
int comparation4(int x){
	int a[size2], b[size2];
	copyarray(a, playerhand, size2);
	copyarray(b, computerhand, size2);
	if(x==10){
		return 1;
	}
	else if(x==9){
		return comforstraightflush4(a, b);
	}
	else if(x==8){
		return comforfoak4(a, b);
	}
	else if(x==7){
		return comforfh4(a, b);
	}
	else if(x==6){
		return comforflush4(a, b);
	}
	else if(x==5){
		return comforstraight4(a, b);
	}
	else if(x==4){
		return comfortoak4(a, b);
	}
	else if(x==3){
		return comfortp4(a, b);
	}
	else{
		return comforop4(a, b);
	}
}
int playerBet(int x){
	int y;
	printf("\nYou have higher chance to win...\n\n");
	printf("How much do you want to bet (should be less than or equal to $%d): ", player);
	scanf("%d", &y);
	while((player-y)<0||(computer-y)<0){
			printf("\nError!!!");
			printf("\nPlease enter once again: ");
			scanf("%d", &y);
	}
	if(dependson(x)==1){
		printf("\nThe computer won't follow.");
		return 1;
	}
	else if(dependson(x)==2){
		printf("\n\nThe computer will follow\n");
	}
	player-=y;
	computer-=y;
	bettingpool=y+y;
	printf("Computer: %d, You: %d, Betting Pool: %d", computer, player, bettingpool);
	return 0;
}
int computerBet(int x){
	char ans;
	int y;
	printf("\nComputer has higher chance to win...\n\n");
	y=(computerhand[x]-playerhand[x])*10;
	while(y>computer&&computer>0){
		y-=10;
	}
	printf("Computer bet $%d", y);
	printf("\n\nDo you want to follow? (Y/N): ");
	scanf("%c", &ans);
	while(ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n'){
		printf("Input Error!!!\n");
		printf("Please enter again (Y/N): ");
		scanf("%c", &ans);	
	}
	if(ans=='Y'||ans=='y'){
		computer-=y;
		player-=y;
		bettingpool=y+y;
		printf("Computer: %d, You: %d, Betting Pool: %d", computer, player, bettingpool);
		return 0;
	}
	else if(ans=='N'||ans=='n'){
		return 1;
	}
}
