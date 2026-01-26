package Week1;

import java.util.Scanner;

public class Exercise02_202024029 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        final double pi = 3.14;

        System.out.print("원뿔의 반지름을 입력하세요 : ");
        double r = sc.nextDouble();

        System.out.print("원뿔의 높이를 입력하세요 : ");
        double h = sc.nextDouble();

        double volume = (1.0 / 3.0) * pi * r * r * h;

        System.out.printf("원뿔의 부피는 %.2f 입니다.", volume);

        sc.close();
	}
}
