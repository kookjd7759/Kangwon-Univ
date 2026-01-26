package week15;

import java.io.*;
import java.util.*;

public class Exercise01_202024029 {
	private static String encode(String enc, int offset) {
        StringBuilder encoded = new StringBuilder();
        for (char i : enc.toCharArray()) {
            if (Character.isLetter(i)) {
                if (Character.isUpperCase(i)) {
                    encoded.append((char) ('A' + (i - 'A' + offset) % 26));
                } else {
                    encoded.append((char) ('a' + (i - 'a' + offset) % 26));
                }
            } else {
                encoded.append(i);
            }
        }
        return encoded.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1. 암호화 2. 복호화 0. 종료");
            System.out.print("선택>> ");
            int selected = sc.nextInt();
            if (selected == 0) {
                System.out.print("프로그램을 종료합니다.");
            	break;
            }

            System.out.print("원본 파일명: ");
            String file_name = sc.next();
            System.out.print("키(shift 값): ");
            int key = sc.nextInt();
            key = selected == 1 ? key : 26 - (key % 26);
            String output_name = (selected == 1 ? "encrypted_202024029.txt" : "decrypted_202024029.txt");
            
            BufferedReader reader = null;
            PrintWriter writer = null;
            try {
                reader = new BufferedReader(new FileReader(file_name));
                writer = new PrintWriter(new FileWriter(output_name));
            }
            catch (IOException e) {
                System.out.println("ERROR");
            }
            
            String line;
            try {
				while ((line = reader.readLine()) != null) {
				    writer.println(encode(line, key));
				}
			} catch (IOException e) {
				e.printStackTrace();
			}

            System.out.println("작업 완료: " + output_name + " 생성됨.\n");
            
            try {
				reader.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
            writer.close();
        }
    }
}
