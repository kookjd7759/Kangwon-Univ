package week2;

import java.util.Scanner;

public class Exercise02_202024029 {
	public static void printArr(int[][] arr, String name) {
		System.out.println("--- Matrix " + name + " ---");
		
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) 
            	System.out.printf("%4d", arr[i][j]);
            System.out.println();
        }
        System.out.println();
    }
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int a[][] = new int[4][2];
        int b[][] = new int[2][3];
        int c[][] = new int[4][3];

		System.out.print("4x2 행렬 A의 값을 입력하세요:\n");
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 2; ++j)
        	a[i][j] = sc.nextInt();

		System.out.print("\n2x3 행렬 B의 값을 입력하세요:\n");
        for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j)
        	b[i][j] = sc.nextInt();
        
        for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 2; k++) 
        	c[i][j] += a[i][k] * b[k][j];

        System.out.println();
        printArr(a, "A (4x2)");
        printArr(b, "B (2x3)");
        printArr(c, "C (4x3)");
	}
}
