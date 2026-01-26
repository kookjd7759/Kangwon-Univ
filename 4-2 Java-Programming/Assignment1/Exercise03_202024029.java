package Week1;

import java.util.Scanner;

public class Exercise03_202024029 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("정수(int) 입력: ");
        int intValue = sc.nextInt();
        byte int_to_byte = (byte) intValue;
        float int_to_float = intValue;

        System.out.print("실수(double) 입력: ");
        double doubleValue = sc.nextDouble();
        int double_to_int = (int) doubleValue;
        float double_to_float = (float) doubleValue;

        System.out.print("문자(char) 입력: ");
        char charValue = sc.next().charAt(0);
        int char_to_int = charValue;

        System.out.println("\n====== 형변환 결과 ======");

        System.out.println("입력 int: " + intValue);
        System.out.println(" -> byte 변환: " + int_to_byte);
        System.out.println(" -> float 변환: " + int_to_float);

        System.out.println("\n입력 double: " + doubleValue);
        System.out.println(" -> int 변환: " + double_to_int);
        System.out.println(" -> float 변환: " + double_to_float);

        System.out.println("\n입력 char: " + charValue);
        System.out.println(" -> int 변환: " + char_to_int);
	}
}
