package model;

import java.util.List;

public class CardValidator {
    public static boolean isStraight(Player player){
        int count = 0;
        player.sortByNumber();
        for(int i = 0; i < player.getHandCardSize(); i++){
            if(player.getIndex(i).getNumber() + 1 == player.getIndex(i+1).getNumber()){
                count++;
            }
        }
        if(count == 4){
            return true;
        }
        return false;
    }
    public static boolean isFlush(Player player){
        int count = 0;
        for(int i = 0; i < player.getHandCardSize(); i++){
            if(player.getIndex(i).getSuit() == player.getIndex(i+1).getSuit()){
                count++;
            }
        }
        if(count == 4){
            return true;
        }
        return false;
    }
    public static boolean isPair(Player player){
        player.sortByNumber();
        for(int i = 0; i < player.getHandCardSize(); i++){
            if(player.getIndex(i).getNumber() == player.getIndex(i+1).getNumber()){
                return true;
            }
        }
        return false;
    }
    public static boolean isRoyalFlush(Player player){
        int count = 0;
        player.sortByNumber();
        for(int i = 0; i < player.getHandCardSize(); i++){
            if(player.getIndex(i).getNumber() + 1 == player.getIndex(i+1).getNumber()){
                count++;
            }
        }
        return false;
    }
    public static boolean isStraightFlush(Player player){
        return false;
    }
    public static boolean isFourOfAKind(Player player){
        return false;
    }
    public static boolean isFullHouse(Player player){
        return false;
    }
    public static boolean isThreeOfAKind(Player player){
        return false;
    }
    public static boolean isTwoPair(Player player){
        return false;
    }
    public static boolean isOnePair(Player player){
        return false;
    }

}
