package model;

import java.util.ArrayList;
import java.util.List;

public class Player {
    private List<Card> handCard = new ArrayList<>();
    private int money;
    public void setMoney(int money){
        this.money = money;
    }
    public int getMoney (){
        return money;
    }
    public void printHandCard(){

    }
    public void sortBySuit(){

    }
    public void sortByNumber(){

    }
}
