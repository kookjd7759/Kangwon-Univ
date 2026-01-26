package week15;

import java.io.*;
import java.util.*;

public class Exercise02_202024029 {
	private static void split(String inputFile, int size) throws IOException {
        BufferedInputStream in = new BufferedInputStream(new FileInputStream(inputFile));
        byte[] buffer = new byte[10000];
        int idx = 1;
        while (true) {
            int image_byte = 0;
            String name = "part" + idx++ + ".bin";
            BufferedOutputStream out = new BufferedOutputStream(new FileOutputStream(name));
            
            while (image_byte < size) {
                int readed = in.read(buffer);
                if (readed == -1) break;
                out.write(buffer, 0, readed);
                image_byte += readed;
            }

            out.close();
            
            if (image_byte == 0) {
                new File(name).delete();
                break;
            }
            
            System.out.println(name + " 생성 (" + image_byte + " bytes)");
        }
        System.out.println();
        
        in.close();
    }

	private static void merge(String outputFile, int size) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(new FileOutputStream(outputFile));
        byte[] buffer = new byte[10000];
        for (int i = 1; i <= size; i++) {
            String name = "part" + i + ".bin";
            BufferedInputStream in = new BufferedInputStream(new FileInputStream(name));
            int temp;
            while ((temp = in.read(buffer)) != -1) out.write(buffer, 0, temp);
            in.close();
        }
        
        out.close();
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1. 분할 2. 병합 0. 종료");
            System.out.print("선택>> ");
            int selected = sc.nextInt();
            if (selected == 0) {
                System.out.print("프로그램을 종료합니다.");
            	break;
            }

            String file_name;
            int size;
            
            if (selected == 1) {
                System.out.print("원본 파일: "); file_name = sc.next();
                System.out.print("분할 크기(byte): "); size = sc.nextInt();
                try {
                    split(file_name, size);
                } catch (IOException e) {
                    System.out.println("ERROR");
                }
            } 
            else if (selected == 2) {
                System.out.print("복원할 파일명: "); file_name = sc.next();
                System.out.print("분할된 파일의 개수: "); size = sc.nextInt();
                try {
                    merge(file_name, size);
                    System.out.println(file_name + " 복원 완료\n");
                } catch (IOException e) {
                    System.out.println("ERROR");
                }
            }
        }
    }
}
