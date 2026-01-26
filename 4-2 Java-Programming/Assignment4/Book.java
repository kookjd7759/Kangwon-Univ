package week4;

public class Book {
    private String title;
    private String author;
    private int borrowCount;
    public boolean isAvailable;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.borrowCount = 0;
        this.isAvailable = true;
    }

    public Book(String title, String author, boolean isAvailable) {
        this.title = title;
        this.author = author;
        this.borrowCount = 0;
        this.isAvailable = isAvailable;
    }

    public boolean borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            borrowCount++;
            return true;
        }
        return false;
    }

    public void printInfo() {
        System.out.printf(
        		"%s(%s) - 총 대출 횟수: %d, 대출 가능 여부: %b%n",
                title, author, borrowCount, isAvailable
                );
    }

    public void returnBook() { isAvailable = true; }
}
