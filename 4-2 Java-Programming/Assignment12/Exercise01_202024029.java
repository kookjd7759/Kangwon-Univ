package week14;

class NonGenericBox {
    private Object content;

    public Object getContent() { return content; }
    public void setContent(Object content) { this.content = content; }
}

class GenericBox<T> {
    private T content;

    public T getContent() { return content; }
    public void setContent(T content) { this.content = content; }
}

public class Exercise01_202024029 {
    public static void main(String[] args) {
        System.out.println("=== 1. 비제네릭(Legacy) 방식 테스트 ===");
        NonGenericBox nonGeneric_1 = new NonGenericBox();
        NonGenericBox nonGeneric_2 = new NonGenericBox();

        nonGeneric_1.setContent("홍길동");
        nonGeneric_2.setContent(2024001);

        String  content_1 = (String) nonGeneric_1.getContent();
        Integer content_2 = (Integer)nonGeneric_2.getContent();

        System.out.println("NonGenericBox1 내용: " + content_1);
        System.out.println("  -> 문자열 길이: " + content_1.length());
        System.out.println("NonGenericBox2 내용: " + content_2);
        System.out.println("  -> 정수값 + 100: " + (content_2 + 100));
        
        System.out.println();
        
        System.out.println("=== 2. 제네릭(Generic) 방식 테스트 ===");
        GenericBox<String>  generic_1 = new GenericBox<String>();
        GenericBox<Integer> generic_2 = new GenericBox<Integer>();

        generic_1.setContent("홍길동");
        generic_2.setContent(2024001);

        content_1 = generic_1.getContent();
        content_2 = generic_2.getContent();

        System.out.println("GenericBox1 내용: " + content_1);
        System.out.println("  -> 타입: " + content_1.getClass().getName());
        System.out.println("  -> 문자열 길이: " + content_1.length());
        System.out.println("GenericBox2 내용: " + content_2);
        System.out.println("  -> 타입: " + content_2.getClass().getName());
        System.out.println("  -> 정수값 + 100: " + (content_2 + 100));
    }
}
