/*Foak= four of a kind, Fh= fullhouse, toak = three of a kind, tp = two pairs, op = one pair
  hc = high card*/
#include <iostream>
#include <time.h>
#define size 5
#define size2 4
using namespace std;
class Card{
private:
    short suit; //1=diamond, 2=club, 3=heart, 4=spades //ASCII: 4, 5, 3, 6
    int num;
public:
    Card();
    void setSuit(short);
    void setNum(int);
    short getSuit();
    int getNum();
    void printHand(int);
    void sorting(int);
    void sortByNum(int);
    //Card checking for 5 cards//
//    bool isPair();
    bool isRoyalFlush();
    bool isStraightFlush();
    bool isfoak();
    bool isfh();
    bool isFlush();
    bool isStraight();
    bool istoak();
    bool istp();
    bool isop();
    int cardDivision();
    //Card checking for 4 cards//
    bool isRoyalFlush4();
    bool isStraightFlush4();
    bool isFoak4();
    bool isFh4();
    bool isFlush4();
    bool isStraight4();
    bool isToak4();
    bool isTp4();
    int cardDivision4();
    //assign operator
    Card& operator = (const Card& temp);
};
//
void random(Card[], Card[], Card[]);
void swap (Card*, Card*);
//Card comparing//
int compare(int);
int compare4(int);
//Compare for 5 cards//
//comFor = compare for
int comForStraightFlushOrHc(Card[], Card[]);
int comForFFT(Card[], Card[]); //FFT = Foak, Fh or Toak
//int comForFh(Card[]
int comForFlushOrStraight(Card[], Card[]);
//int comForStraight(Card[], Card[]);
//int comForToak(Card[], Card[]);
int comForTpOrOp(Card[], Card[]);
//int comForOp(Card[], Card[]);
//int comForHc(Card[], Card[]);
//Compare for 4 cards//
int comForStraightFlush4(Card[], Card[]);
int comForFoak4(Card[], Card[]);
int comForFh4(Card[], Card[]);
int comForFlush4(Card[], Card[]);
int comForStraight4(Card[], Card[]);
int comForToak4(Card[], Card[]);
int comForTOH4(Card[], Card[]);
//int comForOp4(Card[], Card[]);
//int comForHc4(Card[], Card[]);
//
int whoWin(Card[], Card[]);
int whoBet(Card[], Card[]);
int follow(int, int);
//
Card playerHand[size], computerHand[size], totalCard[52];
int playerMoney = 1000, computerMoney = 1000;

Card::Card(){
    suit = 1;
    num = 2;
}
void Card::setSuit(short x){
    suit = x;
}
void Card::setNum(int x){
    num = x;
}
short Card::getSuit(){
    return this->suit;
}
int Card::getNum(){
    return this->num;
}
void Card::printHand(int x){
    for(int i=0; i<x; i++){
        switch(this->suit){
            case 1:
                cout << (char)4;
                break;
            case 2:
                cout << (char)5;
                break;
            case 3:
                cout << (char)3;
                break;
            case 4:
                cout << (char)6;
                break;
            default:
                break;
        }
        switch(this->num){
            case 13:
                cout << "A";
                break;
            case 12:
                cout << "K";
                break;
            case 11:
                cout << "Q";
                break;
            case 10:
                cout << "J";
                break;
            default:
                cout << this->num+1;
        }
    }
    cout << endl;
}
void Card::sorting(int x){
    for(int i=0; i<x-2; i++){
        for(int j=0; j<=x-i-2; j++){
            if(this[j].suit*this[j].num > this[j+1].suit*this[j+1].num){
                swap(&this[j], &this[j+1]);
            }
        }
    }
}
void Card::sortByNum(int x){
    for(int i=0; i<x-2; i++){
        for(int j=0; j<x-i-2; j++){
            if(this[j].num > this[j+1].num){
                swap(&this[j], &this[j+1]);
            }
        }
    }
}
bool Card::isStraight(){
    this->sortByNum(size);
    int count = 0;
    for(int i=0; i<=size-1; i++){
        if(this[i+1].num == this[i].num + 1){
            count++;
        }
    }
    if(count==4){
        return true;
    }
    return false;
}
bool Card::isFlush(){
    int count=0;
    for(int i=0; i<=size-1; i++){
        if(this[i].suit == this[i+1].suit){
            count++;
        }
    }
    if(count==4){
        return true;
    }
    return false;
}
//bool Card::isPair(){
//    this->sortByNum(size);
//    int count=0;
//    for(int i=0; i<=size-1; i++){
//        if(this[i].num == this[i+1].num){
//            count++;
//        }
//    }
//    if(count>0){
//        return true;
//    }
//    return false;
//}
bool Card::isRoyalFlush(){
    this->sortByNum(size);
    int count=0;
    for(int i=0; i<=size-1; i++){
        if(this[i].suit == this[i+1].suit && this[i].num == i+9){
            count++;
        }
    }
    if(count==4){
        return true;
    }
    return false;
}
bool Card::isStraightFlush(){
    this->sortByNum(size);
    int count=0;
    for(int i=0; i<=size-1; i++){
        if(this[i].suit == this[i+1].suit && this[i].num == this[i].num+1){
            count ++;
        }
    }
    if(count == 4){
        return true;
    }
    return false;
}
bool Card::isfoak(){
    this->sortByNum(size);
    int count=0;
    for(int i=0; i<=size-1; i++){
        if(this[i].num == this[i+1].num){
            count++;
        }
    }
    if(count==3){
        return true;
    }
    return false;
}
bool Card::isfh(){
    this->sortByNum(size);
    if((this[0].num == this[2].num && this[3].num == this[4].num)
       || (this[0].num == this[1].num && this[2].num == this[4].num)){
        return true;
    }
    return false;
}
bool Card::istoak(){
    this->sortByNum(size);
    if(this[0].num == this[2].num && this[3].num != this[4].num)
        return true;
    
    else if(this[1].num == this[3].num)
        return true;
    
    else if(this[2].num == this[4].num && this[0].num != this[1].num)
        return true;
    
    else return false;
}
bool Card::istp(){
    this->sortByNum(size);
    if(this[0].num == this[1].num){
        if(this[2].num == this[3].num){
            return true;
        }
        else if(this[3].num == this[4].num){
            return true;
        }
        else return false;
    }
    else if(this[1].num == this[2].num){
        if(this[3].num == this[4].num){
            return true;
        }
        else return false;
    }
    return false;
}
bool Card::isop(){
    this->sortByNum(size);
    int count=0;
    for(int i=0; i<size-1; i++){
        if(this[i].num == this[i+1].num){
            count++;
        }
    }
    if(count == 1){
        return true;
    }
    return false;
}
int Card::cardDivision(){
    if(this->isRoyalFlush()){
        return 10;
    }
    else if(this->isStraightFlush()){
        return 9;
    }
    else if(this->isfoak()){
        return 8;
    }
    else if(this->isfh()){
        return 7;
    }
    else if(this->isFlush()){
        return 6;
    }
    else if(this->isStraight()){
        return 5;
    }
    else if(this->istoak()){
        return 4;
    }
    else if(this->istp()){
        return 3;
    }
    else if(this->isop()){
        return 2;
    }
    else return 1;
}
bool Card::isRoyalFlush4(){
    this->sorting(size2);
    int flag1=0, flag2=0;
    for(int i=0; i<size2-1; i++){
        if(this[i].suit == 4 && this[i+1].suit == 4){
            if(this[i].num >= 9 && this[i+1].num >= 9){
                if(this[i].num+1 == this[i+1].num){
                    flag1++;
                }
                else if(this[i].num+2 == this[i+1].num){
                    flag2++;
                }
            }
        }
    }
    if(flag1 == 3){
        return true;
    }
    else if(flag1 == 2 && flag2 == 1){
        return true;
    }
    return false;
}
bool Card::isStraightFlush4(){
    this->sortByNum(size2);
    int flag1=0, flag2=0;
    int tempSuit = this[0].getSuit();
    for(int i=0; i<size2-1; i++){
        if(this[i].suit == tempSuit && this[i+1].suit == tempSuit){
            if(this[i].num+1 == this[i+1].num){
                flag1++;
            }
            else if(this[i].num+2 == this[i+1].num){
                flag2++;
            }
        }
    }
    if(flag1 == 3){
        return true;
    }
    else if(flag1 ==2 && flag2==1){
        return true;
    }
    return false;
}
bool Card::isFoak4(){
    this->sortByNum(size2);
    if(this[0].num == this[3].num){
        return true;
    }
    else if(this[0].num == this[2].num || this[1].num == this[3].num){
        return true;
    }
    return false;
}
bool Card::isFh4(){
    int count=0;
    this->sortByNum(size2);
    for(int i=0; i<size2-1; i++){
        if(this[i].num == this[i+1].num){
            count++;
        }
    }
    if(this[0].num == this[1].num && this[2].num == this[3].num){
        return true;
    }
    else if(count == 3){
        return true;
    }
    return false;
}
bool Card::isFlush4(){
    int count=0;
    for(int i=0; i<size2-1; i++){
        if(this[i].suit == this[i+1].suit){
            count++;
        }
    }
    if(count == 3){
        return true;
    }
    return false;
}
bool Card::isStraight4(){
    this->sortByNum(size2);
    int flag1=0, flag2=0;
    for(int i=0; i<size2-1; i++){
        if(this[i].num+1 == this[i+1].num){
            flag1++;
        }
        else if(this[i].num+2 == this[i+1].num){
            flag2++;
        }
    }
    if(flag1 == 3){
        return true;
    }
    else if(flag1 ==2 && flag2 == 1){
        return true;
    }
    return false;
}
bool Card::isToak4(){
    this->sortByNum(size2);
    if((this[0].num == this[1].num && this[1].num == this[2].num) || (this[1].num == this[2].num && this[2].num == this[3].num)){
        return true;
    }
    else if(this[0].num == this[1].num && this[2].num != this[3].num){
        return true;
    }
    else if(this[1].num == this[2].num){
        return true;
    }
    return false;
}
bool Card::isTp4(){
    this->sortByNum(size2);
    if(this[0].num == this[1].num && this[2].num == this[3].num){
        return true;
    }
    else if(this[1].num == this[2].num && this[2].num != this[3].num){
        return true;
    }
    return false;
}
int Card::cardDivision4(){
    if(this->isRoyalFlush4()){
        return 10;
    }
    else if(this->isStraightFlush4()){
        return 9;
    }
    else if(this->isFoak4()){
        return 8;
    }
    else if(this->isFh4()){
        return 7;
    }
    else if(this->isFlush4()){
        return 6;
    }
    else if(this->isStraight4()){
        return 5;
    }
    else if(this->isToak4()){
        return 4;
    }
    else if(this->isTp4()){
        return 3;
    }
    else return 2;
}
Card& Card::operator=(const Card& temp){
    this->suit = temp.suit;
    this->num = temp.num;
    return *this;
}
//
//
int main() {
    for(int i=1; i<=4; i++){
        for(int j=1; j<=13; j++){
            totalCard[i*j-1].setSuit(i);
            totalCard[i*j-1].setNum(j);
        }
    }
    random(totalCard, playerHand, computerHand);
    cout << "//////////////////////////////////" << endl;
    cout << "First round" << endl;
    cout << "You got: $" << playerMoney << "computer got: $" << computerMoney << endl;
    
    return 0;
}
//
//
void random(Card totalCard[], Card player[], Card computer[]){
    int i, j, p, q;
    srand(time(NULL));
    for(i=1; i<=100; i++){
        do{
            p=rand()%52;
            q=rand()%52;
        }while(p==q);
        swap(&totalCard[p],&totalCard[q]);
    }
    for(j=0; j<size; j++){
        player[j]=totalCard[j];
        computer[j]=totalCard[5+j];
    }
}
void swap (Card* a, Card* b){
    Card temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int compare (int x){
    switch(x){
        case 10:
            return 2;
            break;
        case 9:
            return comForStraightFlushOrHc(playerHand, computerHand);
            break;
        case 8:
            return comForFFT(playerHand, computerHand);
            break;
        case 7:
            return comForFFT(playerHand, computerHand);
            break;
        case 6:
            return comForFlushOrStraight(playerHand, computerHand);
            break;
        case 5:
            return comForFlushOrStraight(playerHand, computerHand);
            break;
        case 4:
            return comForFFT(playerHand, computerHand);
            break;
        case 3:
            return comForTpOrOp(playerHand, computerHand);
            break;
        case 2:
            return comForTpOrOp(playerHand, computerHand);
            break;
        default:
            return comForStraightFlushOrHc(playerHand, computerHand);
    }
}
int compare4 (int x){
    switch(x){
        case 10:
            return 2;
            break;
        case 9:
            return comForStraightFlush4(playerHand, computerHand);
            break;
        case 8:
            return comForFoak4(playerHand, computerHand);
            break;
        case 7:
            return comForFh4(playerHand, computerHand);
            break;
        case 6:
            return comForFlush4(playerHand, computerHand);
            break;
        case 5:
            return comForStraight4(playerHand, computerHand);
            break;
        case 4:
            return comForToak4(playerHand, computerHand);
            break;
        case 3:
            return comForTOH4(playerHand, computerHand);
            break;
        default:
            return comForTOH4(playerHand, computerHand);
            break;
    }
}
//Compare//
//return 0 if player wins, return 1 if computer wins
int comForStraightFlushOrHc(Card player[], Card computer[]){
    player->sortByNum(size);
    computer->sortByNum(size);
    if(player[4].getNum() > computer[4].getNum()){
        return 0;
    }
    else if(player[4].getNum() < computer[4].getNum()){
        return 1;
    }
    else{
        if(player[4].getSuit() > computer[4].getSuit()){
            return 0;
        }
        else{
            return 1;
        }
    }
}
int comForFFT(Card player[], Card computer[]){
    player->sortByNum(size);
    computer->sortByNum(size);
    if(player[2].getNum() > computer[2].getNum()){
        return 0;
    }
    else{
        return 1;
    }
}
int comForFlushOrStraight(Card player[], Card computer[]){
    player->sorting(size);
    computer->sorting(size);
    player->sortByNum(size);
    computer->sortByNum(size);
    if(player[4].getNum() > computer[4].getNum()){
        return 0;
    }
    else if(player[4].getNum() < computer[4].getNum()){
        return 1;
    }
    else{
        if(player[4].getSuit() > computer[4].getSuit()){
            return 0;
        }
        else{
            return 1;
        }
    }
}
int comForTpOrOp(Card player[], Card computer[]){
    int flag1=0, flag2=0;
    player->sorting(size);
    computer->sorting(size);
    player->sortByNum(size);
    computer->sortByNum(size);
    for(int i=0; i<size-1; i++){
        if(player[i].getNum() == player[i+1].getNum()){
            flag1=i;
        }
        if(computer[i].getNum() == computer[i+1].getNum()){
            flag2=i;
        }
    }
    if(player[flag1].getNum() > computer[flag2].getNum()){
        return 0;
    }
    else if(player[flag1].getNum() < computer[flag2].getNum()){
        return 1;
    }
    else{
        if(player[flag1+1].getSuit() > computer[flag2+1].getSuit()){
            return 0;
        }
        else{
            return 1;
        }
    }
}
int comForStraightFlush4(Card player[], Card computer[]){
    player->sortByNum(size2);
    computer->sortByNum(size2);
    if(player[3].getNum() > computer[3].getNum()){
        return 0;
    }
    else if(player[3].getNum() < computer[3].getNum()){
        return 1;
    }
    else if(player[3].getNum() == computer[3].getNum()){
        if(player[3].getSuit() > computer[3].getSuit()){
            return 0;
        }
        else{
            return 1;
        }
    }
    return 1;
}
int comForFoak4(Card player[], Card computer[]){
    player->sortByNum(size2);
    computer->sortByNum(size2);
    if(player[2].getNum() > computer[2].getNum()){
        return 0;
    }
    else{
        return 1;
    }
}
int comForFh4(Card player[], Card computer[]){
    player->sortByNum(size2);
    computer->sortByNum(size2);
    int x=0, y=0;
    if(player[0].getNum() == player[2].getNum()){
        x=2;
    }
    else if(player[1].getNum() == player[3].getNum()){
        x=3;
    }
    else if((player[0].getNum()==player[1].getNum() && player[1].getNum()!=player[2].getNum() && player[2].getNum() == player[3].getNum())){
        x=3;
    }
    if(computer[0].getNum() == computer[2].getNum()){
        y=2;
    }
    else if(computer[1].getNum() == computer[3].getNum()){
        y=3;
    }
    else if((computer[0].getNum()==computer[1].getNum() && computer[1].getNum()!=computer[2].getNum() && computer[2].getNum() == computer[3].getNum())){
        y=3;
    }
    if(player[x].getNum() > computer[y].getNum()){
        return 0;
    }
    else return 1;
}
int comForFlush4(Card player[], Card computer[]){
    player->sortByNum(size2);
    computer->sortByNum(size2);
    if(player[3].getNum() > computer[3].getNum()){
        return 0;
    }
    else if(player[3].getNum() < computer[3].getNum()){
        return 1;
    }
    else{
        if(player[3].getSuit() > computer[3].getSuit()){
            return 0;
        }
        else{
            return 1;
        }
    }
}
int comForStraight4(Card player[], Card computer[]){
    player->sortByNum(size2);
    computer->sortByNum(size2);
    if(player[3].getNum() > computer[3].getNum()){
        return 0;
    }
    else if(player[3].getNum() < computer[3].getNum()){
        return 1;
    }
    else if(player[3].getNum() == computer[3].getNum()){
        if(player[3].getSuit() > computer[3].getSuit()){
            return 0;
        }
        else{
            return 1;
        }
    }
    return 1;
}
int comForToak4(Card player[], Card computer[]){
    player->sortByNum(size2);
    computer->sortByNum(size2);
    int flag1=0, flag2=0;
    for(int i=0; i<size2-1; i++){
        if(player[i].getNum() == player[i+1].getNum()){
            flag1 = i;
        }
        if(computer[i].getNum() == computer[i+1].getNum()){
            flag2 = i;
        }
    }
    if(player[flag1+1].getNum() > computer[flag2+1].getNum()){
        return 0;
    }
    else{
        return 1;
    }
}
int comForTOH4(Card player[], Card computer[]){
    player->sortByNum(size2);
    computer->sortByNum(size2);
    if(player[3].getNum() > computer[3].getNum()){
        return 0;
    }
    else if(player[3].getNum() < computer[3].getNum()){
        return 1;
    }
    else{
        if(player[3].getSuit() > computer[3].getSuit()){
            return 0;
        }
        else{
            return 1;
        }
    }
}
int whoWin(Card player[], Card computer[]){
    int x, y;
    x=player->cardDivision();
    y=computer->cardDivision();
    if(x > y){
        return 0;
    }
    else if(x<y){
        return 1;
    }
    else{
        return compare(x);
    }
}
int whoBet(Card player[], Card computer[]){
    int x, y;
    x=player->cardDivision4();
    y= computer->cardDivision4();
    if(x > y){
        return 0;
    }
    else if(x<y){
        return 1;
    }
    else{
        return compare4(x);
    }
}
int follow(int x, int y){
    if(x-y >=5){
        return 0;
    }
    else{
        return 1;
    }
}
