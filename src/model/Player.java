package model;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Player {
    private static final int CARD_UPPERBOUND = 52;
    private List<Card> handCard = new ArrayList<>();
    private int money;

    private static final int DIAMOND = 1;
    private static final int CLUB = 2;
    private static final int HEART = 3;
    private static final int SPADE = 4;
    private static final int ACE = 13;
    private static final int KING = 12;
    private static final int QUEEN = 11;
    private static final int JACK = 10;

    public void setMoney(int money){
        this.money = money;
    }
    public int getMoney (){
        return money;
    }
    public void addCard(Card card){
        handCard.add(card);
    }
    public int getHandCardSize(){
        return handCard.size();
    }
    public Card getIndex(int index){
        return handCard.get(index);
    }
    public void printHandCard(){
        for(Card card : handCard){
            switch(card.getSuit()){
                case DIAMOND:
                    System.out.print("\u2666");
                    break;
                case CLUB:
                    System.out.print("\u2663");
                    break;
                case HEART:
                    System.out.print("\u2665");
                    break;
                case SPADE:
                    System.out.print("\u2660");
                    break;
            }
            switch(card.getNumber()){
                case ACE:
                    System.out.printf("%c", 'A');
                    break;
                case KING:
                    System.out.printf("%c", 'K');
                    break;
                case QUEEN:
                    System.out.printf("%c", 'Q');
                    break;
                case JACK:
                    System.out.printf("%c", 'J');
                    break;
                default:
                    System.out.printf("%d", card.getNumber()+1);
            }
            System.out.println();


        }
    }
    public void sortBySuit(){
        int size = handCard.size();
        Card currCard, nextCard;
        for(int i = 0; i < size - 2; i++){
            for(int j = 0; j <= size - i - 2; j++){
                currCard = handCard.get(j);
                nextCard = handCard.get(j + 1);
                if(currCard.getSuit() * currCard.getNumber() < nextCard.getSuit() * nextCard.getNumber()){
                    swap(currCard, nextCard);
                }
            }
        }
    }

    private void swap(Card i, Card j) {
        Card temp = new Card(i.getSuit(), i.getNumber());
        i.setSuit(j.getSuit());
        i.setNumber(j.getNumber());
        j.setSuit(temp.getSuit());
        j.setNumber(temp.getNumber());
    }

    public void sortByNumber(){
        Card currCard, nextCard;
        int size = handCard.size();
        for(int i = 0; i < size - 2; i++){
            for (int j = 0; j <= size - i - 2; j++){
                currCard = handCard.get(j);
                nextCard = handCard.get(j + 1);
                if(currCard.getNumber() > nextCard.getNumber()){
                    swap(currCard, nextCard);
                }
            }
        }
    }

    public void cardRandomize(){
        int p, q;
        Random random = new Random();
        for(int i = 1; i <= 100; i++){
            do {
                p = random.nextInt(CARD_UPPERBOUND);
                q = random.nextInt(CARD_UPPERBOUND);
            }while(p == q);
            swap(handCard.get(p), handCard.get(q));
        }
    }
}
