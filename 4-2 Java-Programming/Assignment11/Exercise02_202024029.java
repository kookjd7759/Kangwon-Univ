package week13;

import java.util.Scanner;

public class Exercise02_202024029 {
    public static int calculatePrice(int price, double discountRate) {
        assert 0 <= price
        	: "가격은 음수일 수 없습니다: " + price;
        
        assert 0.0 <= discountRate
        	: "할인율은 0.0보다 낮을 수 없습니다: " + discountRate;

        assert discountRate <= 1.0
        	: "할인율은 1.0보다 클 수 없습니다: " + discountRate;
        
        int result = (int)(price * (1.0 - discountRate));
        
        assert result < price
        	: "할인가(" + result + ")가 원가(" + price + ") 이상일 수 없습니다.";
        
        return result;
    }

    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
        System.out.print("--- 가격 계산기 ---\n");

        System.out.print("원가 입력: ");
        int price = sc.nextInt();

        System.out.print("할인율 입력 (0.0 ~ 1.0): ");
        double discountRate = sc.nextDouble();

        int result = calculatePrice(price, discountRate);
        System.out.println("최종 가격: " + result);

        sc.close();
    }
}
