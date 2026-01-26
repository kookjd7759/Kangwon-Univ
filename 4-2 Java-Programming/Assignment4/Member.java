package week4;

public class Member {
    private String name;
    private int memberId;
    private int yearsOfMembership;
    private String tier;
    private static int totalMembers = 0;
    private static int nextId = 1001;
    
    public static int SILVER_TIER_YEARS = 3;
    public static int GOLD_TIER_YEARS  = 5;

    public Member(String name, int years) {
        this.name = name;
        this.yearsOfMembership = years;
        this.memberId = nextId++;
        totalMembers++;

        if (this.yearsOfMembership >= GOLD_TIER_YEARS)  		this.tier = "Gold";
        else if (this.yearsOfMembership >= SILVER_TIER_YEARS)	this.tier = "Silver";
        else 													this.tier = "Bronze";
    }

    public String toString() {
        return String.format(
        		"Member(ID=%d, 이름=%s, 가입기간=%d, 등급=%s)",
                memberId, name, yearsOfMembership, tier
                );
    }

    public static int getTotalMembers() {return totalMembers; }
}
