package week3;

public class SmartphoneTest_202024029 {
    public static void main(String[] args) {
    	Smartphone smartphone = new Smartphone();
    	smartphone.setBattery(80);
    	smartphone.setBrand("Galaxy");
    	smartphone.setOwner("국동균");
    	smartphone.printInfo();
    	
    	smartphone.charge();
    	smartphone.printInfo();

    	smartphone.charge("초고속");
    	smartphone.printInfo();

    	smartphone.charge("고속");
    	smartphone.printInfo();

    	smartphone.charge("일반");
    	smartphone.printInfo();
    	
    	smartphone.charge(15);
    	smartphone.printInfo();

    }
}
