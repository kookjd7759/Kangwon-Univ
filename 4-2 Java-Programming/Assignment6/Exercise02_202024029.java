package week7;

import javax.swing.*;
import java.awt.*;

public class Exercise02_202024029 extends JFrame {
    public Exercise02_202024029() {
        super("햄버거 주문 키오스크");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        add(new JLabel("원하시는 메뉴를 선택하세요", JLabel.CENTER), BorderLayout.NORTH);

        JPanel center = new JPanel(new GridLayout(3, 1));

        JPanel menu_main = new JPanel(new FlowLayout(FlowLayout.LEFT));
        menu_main.add(new JLabel("메인 메뉴:  "));
        menu_main.add(new JRadioButton("불고기버거")); 
        menu_main.add(new JRadioButton("치즈버거")); 
        menu_main.add(new JRadioButton("치킨버거"));

        JPanel menu_side = new JPanel(new FlowLayout(FlowLayout.LEFT));
        menu_side.add(new JLabel("사이드 메뉴:  "));
        menu_side.add(new JCheckBox("감자튀김", true));
        menu_side.add(new JCheckBox("치즈스틱"));
        menu_side.add(new JCheckBox("샐러드", true));

        JPanel menu_drink = new JPanel(new FlowLayout(FlowLayout.LEFT));
        menu_drink.add(new JLabel("음료:  "));
        menu_drink.add(new JCheckBox("콜라"));
        menu_drink.add(new JCheckBox("사이다", true));
        menu_drink.add(new JCheckBox("오렌지주스"));

        center.add(menu_main);
        center.add(menu_side);
        center.add(menu_drink);
        add(center, BorderLayout.CENTER);

        JPanel panel_btn = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panel_btn.add(new JButton("주문"));
        panel_btn.add(new JButton("취소"));
        add(panel_btn, BorderLayout.SOUTH);
        setVisible(true);
    }

    public static void main(String[] args) {
    	Exercise02_202024029 window = new Exercise02_202024029();
    }
}
