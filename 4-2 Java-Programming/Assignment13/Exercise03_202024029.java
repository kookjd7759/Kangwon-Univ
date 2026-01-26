package week15;

import java.io.*;
import java.util.*;

public class Exercise03_202024029 {
    private static class TodoItem implements Serializable {
        private String content;
        private Date date;

        public TodoItem(String content) {  this.content = content; this.date = new Date(); }
        public String getContent() { return content; }
        public Date getDate() { return date; }
    }

    private static void saveList(ArrayList<TodoItem> list) {
        ObjectOutputStream out = null;
        try {
            out = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("tasks.dat")));
            out.writeObject(list);
        } 
        catch (IOException e) {
            System.out.println("ERROR");
        } 
        try {
            out.close();
        } 
    	catch (IOException e) {
        }
    }

    private static ArrayList<TodoItem> loadList() {
        ObjectInputStream in = null;
        try {
            in = new ObjectInputStream(new BufferedInputStream(new FileInputStream("tasks.dat")));
            Object obj = in.readObject();
            return (ArrayList<TodoItem>) obj;
        } catch (IOException e) {
            System.out.println("로드 중 오류가 발생했습니다.");
        } catch (ClassNotFoundException e) {
            System.out.println("데이터 형식이 올바르지 않습니다.");
        } finally {
            if (in != null) {
                try {
                    in.close();
                } catch (IOException e) {
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        ArrayList<TodoItem> list = new ArrayList<TodoItem>();
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1. 추가 2. 목록 3. 저장 4. 로드 0. 종료");
            System.out.print("선택>> ");
            int selected = sc.nextInt(); sc.nextLine();
            if (selected == 0) {
                System.out.print("프로그램을 종료합니다.");
            	break;
            }
            
            if (selected == 1) {
                System.out.print("할 일: ");
                String work = sc.nextLine();
                list.add(new TodoItem(work));
            }
            else if (selected == 2) {
            	for (int i = 0; i < list.size(); ++i) {
                    TodoItem item = list.get(i);
                    System.out.println("[" + (i + 1) + ". " + item.getDate() + "] " + item.getContent());
                }
            }
            else if (selected == 3) {
            	saveList(list);
                System.out.println("저장 완료.");
            }
            else if (selected == 4) {
            	list = loadList();
                System.out.println("로드 완료.");
            }

            System.out.println();
        }
    }
}
