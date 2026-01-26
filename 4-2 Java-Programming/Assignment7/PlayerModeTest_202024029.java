package week9;

import java.util.Random;

public class PlayerModeTest_202024029 {
    public static void main(String[] args) {
    	MP3Player player = new MP3Player();
    	player.addTrack(new MusicTrack("Golden", "HUNTR/X"));
    	player.addTrack(new MusicTrack("Love wins all", "IU"));
    	player.addTrack(new MusicTrack("LIKE YOU BETTER", "fromis_9"));
    	
    	System.out.println("--- 순차 재생 ---");
    	player.playNext();
    	player.playNext();
    	player.playNext();
    	
    	player.setPlayMode((idx, count) -> { return (int)(Math.random() * count); });
    	
    	System.out.println("--- 랜덤 재생 ---");
    	player.playNext();
    	player.playNext();
    	player.playNext();
    }
}
