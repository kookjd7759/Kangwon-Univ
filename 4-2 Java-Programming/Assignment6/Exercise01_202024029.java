package week7;

import javax.swing.*;
import java.awt.*;

public class Exercise01_202024029 extends JFrame {
    public Exercise01_202024029() {
        super("회원가입");
        setSize(350, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(5, 2));

        add(new JLabel("  이름:"));
        add(new JTextField("국동균"));

        add(new JLabel("  ID:"));
        add(new JTextField("202024029"));

        add(new JLabel("  비밀번호:"));
        add(new JPasswordField("qlalfqjsgh"));

        add(new JLabel("  이메일:"));
        add(new JTextField("kookjd7759@naver.com"));

        add(new JCheckBox("이용약관에 동의합니다.", true));
        add(new JButton("가입하기"));

        setVisible(true);
    }

    public static void main(String[] args) {
    	Exercise01_202024029 window = new Exercise01_202024029();
    }
}
