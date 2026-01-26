package week3;

class Bus {
    int currentPassengers;
    int totalPassengers;

    public void board(int passengers) {
        int spare = 48 - currentPassengers;
        int in = Math.min(passengers, spare);
        currentPassengers += in;
        totalPassengers += in;
    }

    public void alight(int passengers) {
        currentPassengers -= passengers;
        if (currentPassengers < 0) currentPassengers = 0;
    }

    public int getTotalRevenue() {  return totalPassengers * 1550; }
    
    public Bus() {
        this.currentPassengers = 0;
        this.totalPassengers = 0;
    }
}
