package week10;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Listener_out implements ActionListener {
    private JLabel out;
    Listener_out(JLabel out) { this.out = out; }
    public void actionPerformed(ActionEvent e) {
        out.setText("독립 클래스 방식으로 처리됨");
    }
}

public class Exercise01_202024029 extends JFrame implements ActionListener {
    private JLabel lbl = new JLabel("버튼을 클릭하세요.", JLabel.CENTER);
    private JButton btn_1 = new JButton("1. 독립 클래스");
    private JButton btn_2 = new JButton("2. 내부 클래스");
    private JButton btn_3 = new JButton("3. 프레임 클래스");
    private JButton btn_4 = new JButton("4. 무명 클래스");
    private JButton btn_5 = new JButton("5. 람다식");

    private class Listener_inner implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            lbl.setText("내부 클래스 방식으로 처리됨");
        }
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btn_3) lbl.setText("프레임 클래스 방식으로 처리됨");
    }
    
    public Exercise01_202024029() {
        super("이벤트 처리 방식 비교");
        setSize(750, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel p = new JPanel();
        p.add(btn_1); p.add(btn_2); p.add(btn_3); p.add(btn_4); p.add(btn_5);
        add(p, BorderLayout.NORTH);
        add(lbl, BorderLayout.CENTER);

        btn_1.addActionListener(new Listener_out(lbl));

        btn_2.addActionListener(new Listener_inner());

        btn_3.addActionListener(this);

        btn_4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	lbl.setText("무명 클래스 방식으로 처리됨"); 
            }
        });

        btn_5.addActionListener(e -> lbl.setText("람다식 방식으로 처리됨"));

        setVisible(true);
    }
    
    public static void main(String[] args) {
    	Exercise01_202024029 window = new Exercise01_202024029();
    }
}
