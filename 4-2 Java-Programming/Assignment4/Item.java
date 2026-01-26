package week4;

public class Item {
    public String name;
    public int weight;
    public int cost;
    public final int itemId;

    public static int totalItems = 0;
    private static int nextId = 1;
    
    public Item(String name, int weight, int cost) {
        this.name = name;
        this.weight = weight;
        this.cost = cost;
        this.itemId = nextId++;
        totalItems++;
    }

    public String toString() {
        return String.format(
        		"Item{ID=%d, name=%s, weight=%d, cost=%d}",
                itemId, name, weight, cost
                );
    }
    
    public static int getTotalItems() { return totalItems; }
}
