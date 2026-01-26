package week9;

public class MusicTest_202024029 {
    public static void main(String[] args) {
        Recordable mini_recorder = new Recordable() {
            private int currentVolume = 50;

            public void play() { System.out.println("미니 녹음기 재생 시작!"); }
            public void stop() { System.out.println("미니 녹음기 재생 중지!"); }
            public void setVolume(int volume) {
                if (volume < 0) {
                	volume = 0;
                	System.out.print("최소 볼륨 도달. ");
                }
                if (volume > MAX_VOLUME) {
                	volume = MAX_VOLUME;
                	System.out.print("최대 볼륨 도달. ");
                }
                currentVolume = volume;
                System.out.println("볼륨을 " + currentVolume + "으로 설정합니다.");
            }
            
            public void record() { System.out.println("녹음을 시작합니다."); }
            public void save() { System.out.println("파일을 저장합니다."); }

        };

        mini_recorder.play();
        mini_recorder.setVolume(120);
        mini_recorder.setVolume(-10);
        mini_recorder.setVolume(70);
        mini_recorder.record();
        mini_recorder.save();
        mini_recorder.stop();
    }
}