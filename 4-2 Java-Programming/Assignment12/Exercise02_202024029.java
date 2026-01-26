package week14;

import java.util.HashSet;
import java.util.Arrays;
import java.util.Set;

class SetOperation {
    public static <T> Set<T> union(Set<T> a, Set<T> b) {
        Set<T> set = new HashSet<T>(a);
        set.addAll(b);
        return set;
    }

    public static <T> Set<T> intersection(Set<T> a, Set<T> b) {
        Set<T> set = new HashSet<T>(a);
        set.retainAll(b);
        return set;
    }

    public static <T> Set<T> difference(Set<T> a, Set<T> b) {
        Set<T> set = new HashSet<T>(a);
        set.removeAll(b);
        return set;
    }

    public static <T> boolean isSubset(Set<T> parent, Set<T> child) {
        return parent.containsAll(child);
    }
}

public class Exercise02_202024029 {
    public static void main(String[] args) {
        Set<Integer> intC = new HashSet<Integer>(Arrays.asList(1, 2));

        System.out.println("=== Integer 집합 연산 테스트 ===");
        Set<Integer> setInt_A = new HashSet<Integer>(Arrays.asList(1, 2, 3, 4, 5));
        Set<Integer> setInt_B = new HashSet<Integer>(Arrays.asList(4, 5, 6, 7, 8));
        
        System.out.println("집합 A: " + setInt_A);
        System.out.println("집합 B: " + setInt_B);
        System.out.println("-----------------------------");

        Set<Integer> setInt_AB_sum = SetOperation.union(setInt_A, setInt_B);
        Set<Integer> setInt_AB_inter = SetOperation.intersection(setInt_A, setInt_B);
        Set<Integer> setInt_AB_diff = SetOperation.difference(setInt_A, setInt_B);
        Set<Integer> setInt_C = new HashSet<Integer>(Arrays.asList(1, 2));
        
        System.out.println("합집합 (A U B): " + setInt_AB_sum);
        System.out.println("교집합 (A n B): " + setInt_AB_inter);
        System.out.println("차집합 (A - B): " + setInt_AB_diff);
        System.out.println("집합 C: " + setInt_C);
        System.out.println("C는 A의 부분집합인가? " + SetOperation.isSubset(setInt_A, intC));
        System.out.println("-----------------------------");

        System.out.println("연산 후 원본 집합 A 확인: " + setInt_A);
        System.out.println("연산 후 원본 집합 B 확인: " + setInt_B);
        System.out.println("연산 후 원본 집합 C 확인: " + setInt_C);

        System.out.println();

        System.out.println("=== String 집합 연산 테스트 ===");
        Set<String> setStr_1 = new HashSet<String>(Arrays.asList("Java", "C++", "Python"));
        Set<String> setStr_2 = new HashSet<String>(Arrays.asList("C#", "JavaScript", "Python"));

        System.out.println("집합 1: " + setStr_1);
        System.out.println("집합 2: " + setStr_2);
        System.out.println("-----------------------------");

        Set<String> setStr_12_sum = SetOperation.union(setStr_1, setStr_2);
        Set<String> setStr_12_inter = SetOperation.intersection(setStr_1, setStr_2);
        Set<String> setStr_12_diff = SetOperation.difference(setStr_1, setStr_2);
        Set<String> setStr_3 = new HashSet<String>(Arrays.asList("Ruby"));

        System.out.println("합집합: " + setStr_12_sum);
        System.out.println("교집합: " + setStr_12_inter);
        System.out.println("차집합 (1 - 2): " + setStr_12_diff);
        System.out.println("집합 3: " + setStr_3);
        System.out.println("집합 3은 집합 1의 부분집합인가? " + SetOperation.isSubset(setStr_1, setStr_3));
        System.out.println("-----------------------------");

        System.out.println("연산 후 원본 집합 1 확인: " + setStr_1);
        System.out.println("연산 후 원본 집합 2 확인: " + setStr_2);
        System.out.println("연산 후 원본 집합 3 확인: " + setStr_3);
    }
}
