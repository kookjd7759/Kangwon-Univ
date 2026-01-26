package week9;

interface Playable {
    int MAX_VOLUME = 100;
    void play();
    void stop();
    void setVolume(int volume);
}