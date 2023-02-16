package UI;

import model.Card;

import java.util.ArrayList;
import java.util.List;

public class TextUI {
    private static int bettingPool = 0;
    private static List<Card> cardList = new ArrayList<>();

    private static final int SUIT_AMOUNT = 4;
    private static final int NUMBER_AMOUNT = 13;
    public void start(){
        setCardList();

    }

    private void setCardList() {
        Card card;
        for(short suit = 1; suit <= SUIT_AMOUNT; suit++){
            for(int number = 1; number <= NUMBER_AMOUNT; number++){
                card = new Card(suit, number);
                cardList.add(card);
            }
        }
    }
}
