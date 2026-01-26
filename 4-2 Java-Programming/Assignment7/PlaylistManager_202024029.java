package week9;

import week9_util.*;
import static week9_util.PlaylistUtils.*;

public class PlaylistManager_202024029 {
    public static void main(String[] args) {
        MusicTrack[] playlist = new MusicTrack[MAX_PLAYLIST_SIZE];
        int trackCount = 3;

        playlist[0] = new MusicTrack("Golden", "HUNTR/X");
        playlist[1] = new MusicTrack("Love wins all", "IU");
        playlist[2] = new MusicTrack("LIKE YOU BETTER", "fromis_9");

        System.out.println("--- 제목순 정렬 ---");
        sortByTitle(playlist, trackCount);
        for (int i = 0; i < trackCount; i++) System.out.println(playlist[i]); 

        System.out.println("--- 아티스트순 정렬 ---");
        sortByArtist(playlist, trackCount);
        for (int i = 0; i < trackCount; i++) System.out.println(playlist[i]);

        System.out.println("\n최대 재생목록 크기: " + MAX_PLAYLIST_SIZE);
    }
}
