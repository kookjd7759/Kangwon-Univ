package week3;

import java.util.Scanner;

public class Exercise03_202024029 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("문자열을 입력하세요: ");
        String line = sc.nextLine();
        line += ' '; // 마지막 단어를 감지하기 위한거

        String best = "", cur = "";
        for (int i = 0; i < line.length(); ++i) {
            if (line.charAt(i) == ' ') { // 단어 하나 본거
                if (cur.length() > 0) {
                    if (best.length() < cur.length()) {
                        best = cur;
                    } else if (best.length() == cur.length()) {
                        if (best.compareTo(cur) > 0) best = cur; // 순서 비교
                    }
                    cur = "";
                }
            } else
                cur += line.charAt(i);
        }

        System.out.println("가장 긴 단어: " + best);
        sc.close();
    }
}
