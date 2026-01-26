package week9;

@FunctionalInterface
interface TrackSelector {
	int nextTrack(int currentIndex, int trackCount);
}
