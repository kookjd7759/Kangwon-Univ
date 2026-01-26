package week13;

import java.io.IOException;
import java.util.logging.*;

public class Exercise03_202024029 {
    private static final Logger logger = Logger.getLogger("exercise03_202024029_app");

    public static void main(String[] args) {
        Handler handler = null;

        try {
            handler = new FileHandler("exercise03_202024029_app.log");
            logger.addHandler(handler);
            logger.setLevel(Level.FINEST);

            logger.info("반복 작업 시작");

            for (int i = 0; i <= 4; ++i) {
                logger.fine("현재 인덱스 : " + i);
                logger.finest("계산 결과(" + i + " * " + i + "): " + (i * i));
            }

            logger.info("작업 완료");

        } catch (IOException e) {
            e.printStackTrace();

        } finally {
            if (handler != null) {
                handler.flush();
                handler.close();
                System.out.println("로그가 'exercise03_202024029_app.log' 파일에 저장되었습니다.");
            }
        }

        
    }
}
