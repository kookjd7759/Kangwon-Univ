package week2;

import java.util.Scanner;

public class Exercise01_202024029 {
    static final int[] MONTH_DAYS = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    private static int cal(int m, int day) {
        int sum = 0;
        for (int i = 1; i < m; ++i) sum += MONTH_DAYS[i];
        return sum + day;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("시작 날짜를 입력하세요 (월 일): ");
        int month_start = sc.nextInt();
        int day_start   = sc.nextInt();

        System.out.print("목표 날짜를 입력하세요 (월 일): ");
        int month_dest = sc.nextInt();
        int day_dest   = sc.nextInt();

        int startDoY = cal(month_start, day_start);
        int targetDoY = cal(month_dest, day_dest);
        int diff = targetDoY - startDoY;

        if (diff == 0)       System.out.println("D-DAY 입니다.");
        else if (diff > 0)   System.out.println("D-" + diff + "일 입니다.");
        else                 System.out.println("D+" + Math.abs(diff) + "일 입니다.");
        sc.close();
    }
}
