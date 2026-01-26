package week5;

public class Manager extends Employee {
	private int teamSize;

	public Manager(String name, int employeeId, int baseSalary, int teamSize) {
	    super(name, employeeId, baseSalary);
	    this.teamSize = teamSize;
	}

	public double calculateBonus() { return 0.15 + (teamSize * 0.01); }
	public void doWork() { System.out.println(name + " Manager is managing the team."); }

    // 문제 2번
	public String toString() {
	    return "Manager{name='" + name 
	    		+ "', id='M" + employeeId 
	    		+ "', teamSize=" + teamSize 
	    		+ ", salary=" + getSalary() + "}";
	}
}