package week4;

public class GameTest_202024029 {
    public static void main(String[] args) {
    	Player player1 = new Player("홍길동");
    	Player player2 = new Player();
    	
    	Item sword = new Item("목검", 30, 100);
    	Item shield = new Item("방패", 40, 80);
    	Item armor = new Item("갑옷", 80, 200);
    	Item potion = new Item("포션", 2, 10);

        System.out.println("--- 1. 객체 생성 ---");
        System.out.println(player1.getPlayerInfo());
        System.out.println(player2.getPlayerInfo());

        System.out.println("\n--- 2. 아이템 장착 ---");
        player1.equipItem(sword);
        player1.equipItem(shield);
        player1.equipItem(potion);
        System.out.println(player1.getPlayerInfo());

        System.out.println("\n--- 2-2 무게 제한 확인 ---");
        player1.equipItem(armor);
        System.out.println(player1.getPlayerInfo());
        
        System.out.println("\n--- 3. 아이템 해제 ---");
        Item returnItem = player1.unequipItem();
        System.out.println("반환된 아이템: " + returnItem);
        System.out.println(player1.getPlayerInfo());
        
        System.out.println("\n--- 3-2. 빈 인벤토리 해제 ---");
        player2.unequipItem();

        System.out.println("\n--- 4. 상세 인벤토리 출력 ---");
        player1.printInventory();
        player2.printInventory();

        System.out.println("\n--- 5. 최종 집계 ---");
        System.out.println("생성된 아이템 수: " + Item.totalItems);
        System.out.println("생성된 총 플레이어 수: " + Player.totalPlayers);
    }
}
