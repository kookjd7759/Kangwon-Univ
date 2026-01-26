package week11;

import java.awt.*;
import javax.swing.*;

public class Exercise03_202024029 extends JFrame {
    private MyPanel drawPanel = new MyPanel();
    private JButton btn_mode = new JButton("조각 보기로");
    private JButton btn_next = new JButton("다음 조각 (현재 #1)");

    public Exercise03_202024029() {
        super("이미지 뷰어 (전체/조각)");
        setSize(600, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.add(btn_mode); panel.add(btn_next);
        btn_next.setEnabled(false);

        btn_mode.addActionListener(e -> {
        	drawPanel.change_mode();
            if (drawPanel.isAllmode()) {
            	btn_mode.setText("조각 보기로");
                btn_next.setText("다음 조각 (현재 #1)");
                btn_next.setEnabled(false);
            } else {
            	btn_mode.setText("전체 보기로");
                btn_next.setText("다음 조각 (현재 #" + drawPanel.getPieceIndex() + ")");
                btn_next.setEnabled(true);
            }
        });
        btn_next.addActionListener(e -> {
        	drawPanel.nextPiece();
        	btn_next.setText("다음 조각 (현재 #" + drawPanel.getPieceIndex() + ")");
        });

        add(drawPanel, BorderLayout.CENTER);
        add(panel, BorderLayout.SOUTH);

        setVisible(true);
    }

    static class MyPanel extends JPanel {
        private Image image;
        private int width;
        private int height;

        private boolean isAll = true;
        private int pieceIndex = 1;

        MyPanel() {
            setBackground(Color.WHITE);
            ImageIcon icon = new ImageIcon("lena.png");
            image = icon.getImage();
            width = icon.getIconWidth();
            height = icon.getIconHeight();
        }

        boolean isAllmode() { return isAll; }
        int getPieceIndex() { return pieceIndex; }

        void change_mode() {
        	isAll = !isAll;
            if (isAll) pieceIndex = 1;
            repaint();
        }

        void nextPiece() {
            ++pieceIndex;
            if (pieceIndex > 9) pieceIndex = 1;
            repaint();
        }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D) g.create();

            int pw = getWidth();
            int ph = getHeight();

            if (isAll) {
                g2.drawImage(image, 0, 0, pw, ph, 0, 0, width, height, this);
                g2.setColor(Color.WHITE);
                g2.setFont(new Font("Serif", Font.ITALIC, 20));
                g2.drawString("전체 보기 모드", 12, 22);
            } else {
                int sw = width / 3;
                int sh = height / 3;
                int sx1 = (pieceIndex - 1) % 3 * sw;
                int sy1 = (pieceIndex - 1) / 3 * sh;
                int sx2 = sx1 + sw;
                int sy2 = sy1 + sh;

                g2.drawImage(image, 0, 0, pw, ph, sx1, sy1, sx2, sy2, this);

                g2.setColor(Color.WHITE);
                g2.setFont(new Font("Serif", Font.ITALIC, 20));
                g2.drawString("조각#" + pieceIndex, 12, 22);
            }
        }
    }

    public static void main(String[] args) {
    	Exercise03_202024029 window = new Exercise03_202024029();
    }
}
