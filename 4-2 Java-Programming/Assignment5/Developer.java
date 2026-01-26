package week5;

public class Developer extends Employee {
	private String mainLanguage;
	
	public Developer(String name, int employeeId, int baseSalary, String mainLanguage) {
    	super(name, employeeId, baseSalary);
    	this.mainLanguage = mainLanguage;
    }

	public String getMainLanguage() { return mainLanguage; }
	public double calculateBonus()  { return (mainLanguage.equals("Java") ? 0.2 : 0.1); }
	public void doWork() { System.out.println(name + " Developer is writing code in " + mainLanguage + "."); }
	
    // 문제 2번
	public String toString() {
	    return "Developer{name='" + name
	    		+ "', id='D" + employeeId 
	    		+ "', language='" + mainLanguage 
	    		+ "', salary=" + getSalary() + "}";
	}
}
