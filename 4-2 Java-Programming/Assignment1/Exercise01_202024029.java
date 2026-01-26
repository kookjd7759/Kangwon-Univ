package Week1;

import java.util.Scanner;

public class Exercise01_202024029 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("이름을 입력해주세요 : ");
        String name = sc.nextLine();

        System.out.print("학번을 입력해주세요 : ");
        String id = sc.nextLine();

        System.out.println("자바프로그래밍2\n" + name + "(" + id + ") 학생 환영합니다.");

        sc.close();
	}
}
