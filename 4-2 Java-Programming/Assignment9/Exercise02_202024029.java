package week11;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.util.ArrayList;

public class Exercise02_202024029 extends JFrame {
	private MyPanel drawPanel = new MyPanel();
    private JButton btn_circle = new JButton("원");
    private JButton btn_rect = new JButton("사각형");

    public Exercise02_202024029() {
        super("마우스로 도형 그리기");
        setSize(600, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.add(btn_circle); panel.add(btn_rect);

        btn_circle.addActionListener(e -> drawPanel.setMode(0));
        btn_rect.addActionListener(e -> drawPanel.setMode(1));

        add(drawPanel, BorderLayout.CENTER);
        add(panel, BorderLayout.SOUTH);
        
        setVisible(true);
    }

    static class Info {
        int x, y, size;
        Color color;
        int type;
        Info(int x, int y, int size, Color color, int type) {
            this.x = x; this.y = y; this.size = size;
            this.color = color; this.type = type;
        }
    }

    static class MyPanel extends JPanel implements MouseListener {
        private ArrayList<Info> array = new ArrayList<>();
        private int type = 0, size = 50, colorIdx = 0;
        private Color[] color_order = {
                Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, 
                Color.BLUE, Color.MAGENTA, Color.CYAN
        };

        MyPanel() { addMouseListener(this); }

        void setMode(int type) { this.type = type; this.size = 50; }
        
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D) g.create();
            g2.setStroke(new BasicStroke(2f));

            for (Info n : array) {
                g2.setColor(n.color);
                int half = n.size / 2;
                int x = n.x - half;
                int y = n.y - half;

                if (n.type == 0) g2.drawOval(x, y, n.size, n.size);
                else 			 g2.drawRect(x, y, n.size, n.size);
            }
        }

        public void mousePressed(MouseEvent e) {
            array.add(new Info(e.getX(), e.getY(), size, color_order[colorIdx], type));

            size += 10;
            
            ++colorIdx;
            if (colorIdx >= color_order.length) colorIdx = 0;

            repaint();
        }
        public void mouseReleased(MouseEvent e) {}
        public void mouseClicked(MouseEvent e) {}
        public void mouseEntered(MouseEvent e) {}
        public void mouseExited(MouseEvent e) {}
    }

    public static void main(String[] args) {
    	Exercise02_202024029 window = new Exercise02_202024029();
    }
}
