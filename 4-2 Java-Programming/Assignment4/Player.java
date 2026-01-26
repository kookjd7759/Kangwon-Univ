package week4;

public class Player {
    private String name;
    private int level;
    private Item[] inventory;
    private int playerId;
    private int itemCount;
    
    public static int totalPlayers = 0;
    private static int nextId = 1001;
    
    public Player(String name) {
        this.name = name;
        this.level = 1;
        this.inventory = new Item[10];
        this.itemCount = 0;
        this.playerId = nextId++;
        totalPlayers++;
    }
    public Player() { this("Guest"); }
    
    public void equipItem(Item item) {
    	int weightSum = 0;
    	for (int i = 0; i < this.itemCount; ++i) weightSum += this.inventory[i].weight;
    	if (weightSum + item.weight <= 100) {
    		this.inventory[itemCount++] = item;
            System.out.println("-> " + this.name + "님이 " + item.name + " 아이템을 장착했습니다.");
    	}
    	else System.out.println("-> 무게 제한(100)을 초과하여 " + item.name + "을(를) 추가할 수 없습니다.");
    }
    
    public Item unequipItem() {
    	if (itemCount == 0){
            System.out.println("-> 인벤토리가 비었습니다.");
            return null;
    	}
    	Item item = this.inventory[--itemCount];
        System.out.println("-> " + this.name + "님이 " + item.name + " 아이템을 해제했습니다.");
    	return item;
    }

    public void printInventory() {
        System.out.println("--- " + this.name + "님의 인벤토리 ---");
    	String st = "";
    	for (int i = 0; i < itemCount; ++i) st += (this.inventory[i] + "\n");
    	if (st == "") st = "없음";
        System.out.println(st);
    }
    
    public String getPlayerInfo() {
        String info = "ID: " + playerId + ", 이름: " + name + " (Lv. " + level + "), 인벤토리: ";
        if (itemCount == 0) {
            return info + "없음";
        }
        String items = "[";
        for (int i = 0; i < itemCount; i++) {
            items += inventory[i].name;
            if (i < itemCount - 1) items += ", ";
        }
        items += "]";
        return info + items;
    }
    
    public static int getTotalPlayers() { return totalPlayers; }
}
