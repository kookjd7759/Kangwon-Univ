package week5;

public class CompanySystemTest_202024029 {
    public static void main(String[] args) {
        Employee[] staff = {
            new Manager("홍길동", 1001, 6000000, 5),
            new Developer("김철수", 2002, 4000000, "Java"),
            new Developer("이영희", 2002, 4200000, "Python")
        };
        System.out.println("--- 초기 직원 정보 ---");
        for (int i = 0; i < 3; ++i) 
            System.out.println(staff[i]);

        System.out.println();
        
        System.out.println("--- 연봉 인상 진행 ---");
        HRManager HRmanager = new HRManager();
        for (int i = 0; i < 3; ++i)
        	HRmanager.promoteEmployee(staff[i]);
        
    }
}
