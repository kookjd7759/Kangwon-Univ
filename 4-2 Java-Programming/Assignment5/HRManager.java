package week5;

public class HRManager {
    public void promoteEmployee(Employee emp) {
        if (emp instanceof Manager) {
            emp.setBaseSalary((int)((double)emp.baseSalary * 1.1));
            System.out.println("[" + emp.name + "] Manager의 연봉이 인상되었습니다.");
        } else if (emp instanceof Developer) {
            double rate = ((Developer)emp).getMainLanguage().equals("Java") ? 1.15 : 1.05;
            emp.setBaseSalary((int)((double)emp.baseSalary * rate));
            System.out.println("[" + emp.name + "] Developer의 연봉이 인상되었습니다.");
        }
        System.out.println(emp.toString());
    }
}
