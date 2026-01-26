package week13;

public class Exercise01_202024029 {
    public static void main(String[] args) {
    	System.out.println("--- 예외 처리 실습 시작 ---\n");
    	
    	try {
            int x = 1 / 0;
        } catch (ArithmeticException e) {
            System.out.println("[예외] " + e);
            System.out.println("[원인] 0으로 나누는 연산을 수행했습니다.");
        } System.out.println();
        
        try {
            String s = null;
            int len = s.length();
        } catch (NullPointerException e) {
            System.out.println("[예외] " + e);
            System.out.println("[원인] null 객체를 참조했습니다.");
        } System.out.println();
        
        
        try {
            Object obj = new Object();
            String s = (String) obj;
        } catch (ClassCastException e) {
            System.out.println("[예외] " + e);
            System.out.println("[원인] 적절하지 않은 형변환을 수행했습니다.");
        } System.out.println();
        
        try {
            int[] arr = new int[-1];
        } catch (NegativeArraySizeException e) {
            System.out.println("[예외] " + e);
            System.out.println("[원인] 음수 크기의 배열 생성을 시도했습니다.");
        } System.out.println();
        
        try {
            int[] arr = new int[3];
            int x = arr[5];
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("[예외] " + e);
            System.out.println("[원인] 배열의 인덱스 범위를 벗어난 위치에 접근했습니다.");
        } System.out.println();
        
        try {
            int num = Integer.parseInt("ABC");
        } catch (NumberFormatException e) {
            System.out.println("[예외] " + e);
            System.out.println("[원인] 숫자로 변환할 수 없는 문자열을 정수로 변환하려고 했습니다.");
        } System.out.println();

    	System.out.println("--- 모든 예외 테스트 완료 ---\n");
    }
}
