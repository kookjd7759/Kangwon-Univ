package week4;

public class BookTest_202024029 {
    public static void main(String[] args) {
    	Book book1 = new Book("홍길동전", "허균");
    	System.out.println("--- 테스트 1 ---");
    	System.out.print("초기 상태: "); book1.printInfo();
    	book1.borrowBook(); System.out.print("대출 후: "); book1.printInfo();
    	book1.borrowBook(); System.out.print("추가 대출 시도 후: "); book1.printInfo();
    	book1.returnBook(); System.out.print("반납 후: "); book1.printInfo();

    	System.out.println();
    	
    	Book book2 = new Book("구운몽", "김만중", false);
    	System.out.println("--- 테스트 2 ---");
    	System.out.print("초기 상태: "); book2.printInfo();
    	book2.borrowBook(); System.out.print("대출 시도 후: "); book2.printInfo();
    	book2.returnBook(); System.out.print("반납 후: "); book2.printInfo();
    }
}
