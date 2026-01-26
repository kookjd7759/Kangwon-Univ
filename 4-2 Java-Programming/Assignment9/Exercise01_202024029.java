package week11;

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Ellipse2D;
import javax.swing.*;

public class Exercise01_202024029 extends JFrame {
    private MyPanel drawPanel = new MyPanel();
    private JButton btn_outline = new JButton("외곽선 변경");
    private JButton btn_fill = new JButton("채우기 변경");
    private JButton btn_anti = new JButton("안티에일리어싱 토글");

    public Exercise01_202024029() {
        super("Java 2D 스타일 편집기");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.add(btn_outline); panel.add(btn_fill); panel.add(btn_anti);

        btn_outline.addActionListener(e -> { drawPanel.func_outline(); });
        btn_fill.addActionListener(e -> { drawPanel.func_fill(); });
        btn_anti.addActionListener(e -> { drawPanel.func_anti(); });

        add(drawPanel, BorderLayout.CENTER);
        add(panel, BorderLayout.SOUTH);
        
        setVisible(true);
    }

    public class MyPanel extends JPanel {
        private boolean isFill = false;
        private boolean isAnti = false;
        private float line_w = 1f;

        private final Color color1 = new Color(0, 255, 255);
        private final Color color2 = new Color(128, 0, 255);

        void func_outline() { line_w = ((line_w == 1f) ? 8f : 1f); repaint(); }
        void func_fill() { isFill = !isFill; repaint(); }
        void func_anti() { isAnti = !isAnti; repaint(); }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D) g.create();
            
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, 
            		isAnti ? RenderingHints.VALUE_ANTIALIAS_ON : RenderingHints.VALUE_ANTIALIAS_OFF);

            int space = 40;
            int w = Math.max(10, getWidth() - space * 2);
            int h = Math.max(10, getHeight() - space * 2);

            Ellipse2D.Float ellipse = new Ellipse2D.Float(space, space, w, h);

            if (isFill) {
                Paint gp = new GradientPaint(space, space, color1, space + w, space + h, color2, true);
                g2.setPaint(gp);
            } else {
                g2.setPaint(color1);
            }
            g2.fill(ellipse);

            g2.setStroke(new BasicStroke(line_w));
            g2.setColor(Color.BLACK);
            g2.draw(ellipse);

            g2.setFont(new Font("Serif", Font.ITALIC, 20));
            String text = "Anti-Aliasing: " + (isAnti ? "ON" : "OFF");
            g2.drawString(text, 12, 22);
        }
    }

    public static void main(String[] args) {
    	Exercise01_202024029 window = new Exercise01_202024029();
    }
}
