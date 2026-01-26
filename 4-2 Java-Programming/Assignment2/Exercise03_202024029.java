package week2;

import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;

public class Exercise03_202024029 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("배열의 크기 n x n 을 입력하세요 (n): ");
        int n = sc.nextInt();

        int[][] arr = new int[n][n];
        Random rand = new Random(42);
        for (int i = 0; i < n; ++i)  for (int j = 0; j < n; ++j)
        	arr[i][j] = rand.nextInt(256);

        int[] rowMax = new int[n]; Arrays.fill(rowMax, Integer.MIN_VALUE);
        int[] colMax = new int[n]; Arrays.fill(colMax, Integer.MIN_VALUE);
        for (int i = 0; i < n; ++i)  for (int j = 0; j < n; ++j) {
            rowMax[i] = Math.max(rowMax[i], arr[i][j]);
            colMax[j] = Math.max(colMax[j], arr[i][j]);
        }
        
		System.out.println("--- 원본 배열 ---");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
            	System.out.printf("%4d", arr[i][j]);
            System.out.println();
        }
        System.out.println();
        

		System.out.println("--- 특별한 위치 ---");
		for (int i = 0; i < n; ++i) {
		    for (int j = 0; j < n; ++j) {
		        System.out.printf(
		            (arr[i][j] == rowMax[i] && arr[i][j] == colMax[j] ? "   *" : "   -")
		        );
		    }
		    System.out.println();
		}
        
        sc.close();
    }
}
