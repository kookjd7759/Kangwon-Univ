package week5;

public abstract class Employee {
    protected String name;
    protected int employeeId;
    protected int baseSalary;

    public Employee(String name, int employeeId, int baseSalary) {
        this.name = name;
        this.employeeId = employeeId;
        this.baseSalary = baseSalary;
    }

    public abstract double calculateBonus();
    public abstract void doWork();

    public int getSalary() { return (int)((double)baseSalary * (1.0 + calculateBonus())); }
    public void setBaseSalary(int baseSalary) { this.baseSalary = baseSalary; }
    
    // 문제 2번
    public boolean equals(Object obj) {
    	if (obj instanceof Employee) return this.employeeId == ((Employee) obj).employeeId;
    	else return false;
    }
    
    // 문제 3번
    public final void printCompanyCard() { System.out.println(name + " (사원번호: " + employeeId + ") - □□□ 컴퍼니"); }
    public static void showCompanyPolicy() { System.out.println("회사의 정책은 모든 직원을 존중하는 것입니다."); }
}