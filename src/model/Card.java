package model;

public class Card {
    //1 = diamond (ASCII: 4), 2 = club (ASCII: 5), 3 = heart (ASCII: 3), 4 = spades (ASCII: 6)
    private short suit;
    private int number;

    public Card(short suit, int number){
        this.suit = suit;
        this.number = number;
    }
    public short getSuit() {
        return suit;
    }

    public void setSuit(short suit){
        this.suit = suit;
    }

    public void setNumber(int number){
        this.number = number;
    }
    public int getNumber() {
        return number;
    }


}
