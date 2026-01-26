package week4;

public class MemberTest_202024029 {
    public static void main(String[] args) {
        System.out.println("--- 신규 회원 5명을 등록합니다 ---");
        Member member1 = new Member("홍길동", 7);  System.out.println(member1);
        Member member2 = new Member("김철수", 4);  System.out.println(member2);
        Member member3 = new Member("이영희", 1);  System.out.println(member3);
        Member member4 = new Member("박지성", 11); System.out.println(member4);
        Member member5 = new Member("김연아", 3);  System.out.println(member5);

        System.out.println("\n--------------------------------------");
        System.out.printf("총 회원 수: %d명", Member.getTotalMembers());
    }
}
