package week9_util;

import java.util.Arrays;
import week9.MusicTrack;

public class PlaylistUtils {
	public static final int MAX_PLAYLIST_SIZE = 100;
	
	public static void sortByTitle(MusicTrack[] playlist, int trackCount) {
	    Arrays.sort(playlist, 0, trackCount, (a, b) -> a.getTitle().compareTo(b.getTitle()));
	}
	public static void sortByArtist(MusicTrack[] playlist, int trackCount) {
	    Arrays.sort(playlist, 0, trackCount, (a, b) -> a.getArtist().compareTo(b.getArtist()));
	}

}