package week14;

import java.util.LinkedList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Exercise03_202024029 {
    public static void main(String[] args) {
        System.out.println("=== 자바 마트 키오스크 ===\n");
        Scanner sc = new Scanner(System.in);

        Map<String, Integer> items = new HashMap<String, Integer>();
        items.put("사과", 1500);
        items.put("바나나", 3000);
        items.put("우유", 2500);
        items.put("빵", 1000);
        items.put("계란", 5000);

        LinkedList<String> cart = new LinkedList<String>();
        Set<String> category = new HashSet<String>();

        while (true) {
            System.out.println("1.상품목록 2.장바구니담기 3.장바구니비우기 4.결제및종료 0.종료");
            System.out.print("메뉴 선택 >> ");

            String line = sc.nextLine();
            int input = Integer.parseInt(line);

            if (input == 0) {
                System.out.println("시스템을 종료합니다.");
                break;
            } 
            else if (input == 1) {
                System.out.println("--- 판매 상품 목록 ---");
                for (Map.Entry<String, Integer> entry : items.entrySet()) {
                    System.out.println(entry.getKey() + " : " + entry.getValue() + "원");
                }
            } 
            else if (input == 2) {
                System.out.print("구매할 상품명 입력: ");
                String name = sc.nextLine();
                
                boolean isIn = false; 
                for (Map.Entry<String, Integer> entry : items.entrySet()) {
                	if (name.equals(entry.getKey())) { 
                		cart.add(name); 
                		category.add(name); 
                		System.out.println(name + "을(를) 장바구니에 담았습니다."); 
                		isIn = true; 
            		}
            	} 
                if (!isIn) System.out.println("없는 상품입니다.");
            } 
            else if (input == 3) {
                if (cart.isEmpty()) {
                    System.out.println("장바구니가 이미 비어있습니다.");
                } else {
                    cart.clear();
                    category.clear();
                    System.out.println("장바구니를 비웠습니다.");
                }
            } 
            else if (input == 4) {
            	System.out.println();
                if (cart.isEmpty()) {
                    System.out.println("장바구니에 상품이 없습니다.");
                } else {
                    System.out.println("=== 영수증 ===");
                    int sum = 0;
                    Iterator<String> iter = cart.iterator();
                    while (iter.hasNext()) {
                        String name = iter.next();
                        Integer price = items.get(name);
                        sum += price;
                        System.out.println("- " + name + "\t" + price + "원");
                    }
                    System.out.println("-------------------");
                    System.out.println("총 결제 금액: " + sum + "원\n");

                    System.out.println("[구매한 상품 종류]");
                    System.out.println(category);
                    System.out.println("이용해 주셔서 감사합니다.");
                    break;
                }
            } else {
                System.out.println("잘못된 입력입니다.");
            }

            System.out.println();
        }

        sc.close();
    }
}
