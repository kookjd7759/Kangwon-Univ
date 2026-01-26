package week12;

import javax.swing.*;
import javax.swing.event.*;

import java.awt.*;

public class Exercise01_202024029 extends JFrame {
    private MainPanel panel_main; 
    private JSlider slider_w; 
    private JSlider slider_h;

    public Exercise01_202024029() {
        super("타원 조절기");
        setSize(600, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        panel_main = new MainPanel();
        add(panel_main, BorderLayout.CENTER);

        slider_w = new JSlider(0, 500, 100);
        slider_w.setMajorTickSpacing(100); slider_w.setMinorTickSpacing(20);
        slider_w.setPaintTicks(true); slider_w.setPaintLabels(true);
        
        slider_h = new JSlider(0, 500, 100);
        slider_h.setMajorTickSpacing(100); slider_h.setMinorTickSpacing(20);
        slider_h.setPaintTicks(true); slider_h.setPaintLabels(true);

        SliderFrame sliderFrame = new SliderFrame();
        slider_w.addChangeListener(sliderFrame);
        slider_h.addChangeListener(sliderFrame);

        JPanel panel_ctrl = new JPanel(new GridLayout(2, 1));

        JPanel panel_ctrl_w = new JPanel(new GridLayout(1, 2));
        panel_ctrl_w.add(new JLabel("너비(width)"), BorderLayout.WEST);
        panel_ctrl_w.add(slider_w, BorderLayout.CENTER);

        JPanel panel_ctrl_h = new JPanel(new GridLayout(1, 2));
        panel_ctrl_h.add(new JLabel("높이(height)"), BorderLayout.WEST);
        panel_ctrl_h.add(slider_h, BorderLayout.CENTER);

        panel_ctrl.add(panel_ctrl_w);
        panel_ctrl.add(panel_ctrl_h);

        add(panel_ctrl, BorderLayout.SOUTH);

        setVisible(true);
    }

    class MainPanel extends JPanel {
        private int width = 100;
        private int height = 100;

        public void set_size(int w, int h) { width = w; height = h; repaint(); }

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.BLUE);
            int x_center = (getWidth() - width) / 2;
            int y_center = (getHeight() - height) / 2;
            g.fillOval(x_center, y_center, width, height);
        }
    }

    class SliderFrame implements ChangeListener {
        public void stateChanged(ChangeEvent e) {
            JSlider source = (JSlider) e.getSource();
            if(!source.getValueIsAdjusting()) {
            	panel_main.set_size(slider_w.getValue(), slider_h.getValue());
            }
        }
    }

    public static void main(String[] args) {
    	Exercise01_202024029 window = new Exercise01_202024029();
    }
}
