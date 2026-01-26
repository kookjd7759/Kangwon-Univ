package week12;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Exercise02_202024029 extends JFrame {
    private JTextField text_field_cm = new JTextField();
    private JTextField text_field_kg = new JTextField();

    private JRadioButton radio_btn_male = new JRadioButton("남성", true);
    private JRadioButton radio_btn_female = new JRadioButton("여성");

    private JCheckBox check_box = new JCheckBox("중대한 질병이 있습니다.");

    private JButton btnResult = new JButton("검사 결과");

    private JTextArea text_field_info = new JTextArea();
    private JTextArea text_field_result = new JTextArea();

    public Exercise02_202024029() {
        super("판정 등급 계산기");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLayout(new BorderLayout());

        JPanel panel_input = new JPanel(new GridLayout(4, 2));

        panel_input.add(new JLabel("키(cm)"), BorderLayout.WEST);
        panel_input.add(text_field_cm, BorderLayout.CENTER);

        panel_input.add(new JLabel("몸무게(kg)"), BorderLayout.WEST);
        panel_input.add(text_field_kg, BorderLayout.CENTER);

        ButtonGroup bg = new ButtonGroup();
        panel_input.add(radio_btn_male); bg.add(radio_btn_male);
        panel_input.add(radio_btn_female); bg.add(radio_btn_female);
        
        panel_input.add(check_box);
        
        add(panel_input, BorderLayout.NORTH);


        JScrollPane scrollpane_info = new JScrollPane(text_field_info);
        JScrollPane scrollpane_result = new JScrollPane(text_field_result);

        JPanel panel_output = new JPanel(new GridLayout(1, 2, 10, 0));
        panel_output.add(scrollpane_info); panel_output.add(scrollpane_result);

        text_field_info.setText("--- 입력 정보 요약 ---");
        text_field_info.setEditable(false);
        text_field_result.setText("--- 판정 결과 ---");
        text_field_result.setEditable(false);

        add(panel_output, BorderLayout.CENTER);

        JPanel panel_btn = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panel_btn.add(btnResult);
        add(panel_btn, BorderLayout.SOUTH);

        btnResult.addActionListener(new btnListener());

        setVisible(true);
    }

    private int get_score(double height, double bmi, boolean has) {
        if (has) return 5;

        if (height <= 140.0)	  return 6;
        else if (height < 146.0)  return 5;
        else if (height < 159.0)  return 4;
        else if (height >= 204.0) return 4;

        if (bmi >= 20.0 && bmi <= 24.9) 
        	return 1;
        else if ((bmi >= 18.5 && bmi < 20.0) || (bmi >= 25.0 && bmi <= 29.9))
            return 2;
        else if ((bmi >= 15.0 && bmi < 18.5) || (bmi >= 30.0 && bmi <= 34.9))
            return 4;
        else if (bmi < 15.0 || bmi >= 35.0)
            return 5;
        else
            return 3;
    }

    class btnListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            double w = Double.parseDouble(text_field_kg.getText().trim());
            double h = Double.parseDouble(text_field_cm.getText().trim());

            boolean isMale = radio_btn_male.isSelected();
            boolean has = check_box.isSelected();

            double heightMeter = h / 100.0;
            double bmi = w / (heightMeter * heightMeter);

            int score = get_score(h, bmi, has);

            StringBuilder info = new StringBuilder();
            info.append("-- 입력 정보 ---\n");
            info.append("성별: ").append(isMale ? "남성" : "여성").append("\n");
            info.append("키: ").append(String.format("%.1f", h)).append(" cm\n");
            info.append("몸무게: ").append(String.format("%.1f", w)).append(" kg\n");
            info.append("질병 유무: ").append(has ? "있음" : "없음").append("\n");
            text_field_info.setText(info.toString());

            StringBuilder result = new StringBuilder();
            result.append("--- 판정 결과 ---\n");
            result.append("BMI: ").append(String.format("%.2f", bmi)).append("\n");
            
            result.append("신체 등급: ").append(score).append("급");
            if (has) result.append(" (질병)");
            else result.append("\n");

            text_field_result.setText(result.toString());
        }
    }

    public static void main(String[] args) {
    	Exercise02_202024029 window = new Exercise02_202024029();
    }
}
