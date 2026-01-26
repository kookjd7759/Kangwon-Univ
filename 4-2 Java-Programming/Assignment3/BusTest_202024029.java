package week3;

public class BusTest_202024029 {
    public static void main(String[] args) {
    	Bus bus = new Bus();
    	
    	bus.board(20);
    	bus.board(20);
    	bus.board(10);
    	
    	bus.alight(30);
    	
    	bus.board(5);
    	
    	System.out.println("--- 최종 상태 ---");
    	System.out.println("현재 승객 수: " + bus.currentPassengers);
    	System.out.println("총 누적 승객 수: " + bus.totalPassengers);
    	System.out.println("총 수입: " + bus.getTotalRevenue() + "원");
    }
}
