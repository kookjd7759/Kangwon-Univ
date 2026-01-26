package week3;

class Smartphone {
    int battery;
    String brand;
    String owner;
    char condition;

    public void setBattery(int pct) { this.battery = pct; }
    public void setBrand(String name) { this.brand = name; }
    public void setOwner(String name) { this.owner = name; }
    public void printInfo() { System.out.println(owner + "의 " + brand + " 스마트폰, 배터리 잔량 " + battery + "%"); }
    
    public void battery_safe() {
    	if (battery >= 100) battery = 100;
    	if (battery <= 0) battery = 0;
    }
    public void charge() {
    	battery += 1;
    	battery_safe();
    }
    public void charge(int pct) {
    	battery += pct;
    	battery_safe();
    }
    public void charge(String type) {
    	battery += 
    		type == "초고속" ? 5 
    		: type == "고속" ? 3
    		: type == "일반" ? 1
    		: 0;
    	battery_safe();
    }
    
    public Smartphone() {
        this.battery = 0;
        this.brand = "";
        this.owner = "";
        this.condition = ' ';
    }
}
