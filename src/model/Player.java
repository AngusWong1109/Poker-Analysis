package model;

import java.util.ArrayList;
import java.util.List;

public class Player {
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
    public void printHandCard(){
        for(Card card : handCard){
            switch(card.getSuit()){
                case DIAMOND:
                    System.out.printf("%c", 4);
                    break;
                case CLUB:
                    System.out.printf("%c", 5);
                    break;
                case HEART:
                    System.out.printf("%c", 3);
                    break;
                case SPADE:
                    System.out.printf("%c", 6);
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
                    swap(j);
                }
            }
        }
    }

    private void swap(int j) {
        Card currCard = handCard.get(j), nextCard = handCard.get(j + 1);
        Card temp = new Card(currCard.getSuit(), currCard.getNumber());
        currCard.setSuit(nextCard.getSuit());
        currCard.setNumber(nextCard.getNumber());
        nextCard.setSuit(temp.getSuit());
        nextCard.setNumber(temp.getNumber());
    }

    public void sortByNumber(){
        Card currCard, nextCard;
        int size = handCard.size();
        for(int i = 0; i < size - 2; i++){
            for (int j = 0; j <= size - i - 2; j++){
                currCard = handCard.get(j);
                nextCard = handCard.get(j + 1);
                if(currCard.getNumber() > nextCard.getNumber()){
                    swap(j);
                }
            }
        }
    }
}
