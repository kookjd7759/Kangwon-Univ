package week9;

public class MusicTrack {
    private String title;
    private String artist;
    
    public MusicTrack(String title, String artist) {
        this.title = title;
        this.artist = artist;
    }

    public String getTitle() { return title; }
    public String getArtist() { return artist; }
    public String toString() { return title + " - " + artist; }
}
