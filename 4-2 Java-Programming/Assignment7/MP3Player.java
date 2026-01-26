package week9;

class MP3Player {
	private MusicTrack[] playlist;
	private int trackCount;
	private int currentTrackIndex;
	private TrackSelector trackSelector;
	
	public MP3Player() {
	    playlist = new MusicTrack[10];
	    trackCount = 0;
	    currentTrackIndex = -1;
	    trackSelector = (idx, count) -> { return (idx + 1) % count; };
	}

	public void addTrack(MusicTrack track) {
	    if (trackCount < playlist.length) {
	        playlist[trackCount] = track;
	        trackCount++;
	    }
	}

	public void setPlayMode(TrackSelector selector) {
	    trackSelector = selector;
	    System.out.println("재생 모드를 변경합니다.");
	}

	public void playNext() {
	    if (trackCount == 0) System.out.println("플레이리스트가 비어있습니다."); 
	    else {
		    currentTrackIndex = trackSelector.nextTrack(currentTrackIndex, trackCount);
		    System.out.println("재생 중: " + playlist[currentTrackIndex]);
	    }
	}

}