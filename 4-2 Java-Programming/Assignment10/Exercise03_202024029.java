package week12;

import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.*;
import java.io.File;

public class Exercise03_202024029 extends JFrame {
    private JComboBox comboBox_scoreMax =  new JComboBox();
    
    private JTextField text_field_name = new JTextField(10);
    private JTextField text_field_score = new JTextField(4);
    
    private JPasswordField PS_field_password = new JPasswordField(10);
    
    private JTextArea text_area_selfIntro = new JTextArea(5, 20);
    
    private JButton btn_image = new JButton("증명사진 선택...");
    private JButton btn_save = new JButton("저장하기");
    
    private JLabel label_image = new JLabel("[사진 영역]", SwingConstants.CENTER);

    private String photoPath = null;

    public Exercise03_202024029() {
        super("이력서 작성기");
        setSize(630, 520);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel panel_personal = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panel_personal.setBorder(new TitledBorder("인적 사항"));

        JPanel panel_name = new JPanel(new FlowLayout());
        panel_name.add(new JLabel("이름:"));
        panel_name.add(text_field_name);
        panel_name.add(btn_image);

        label_image.setPreferredSize(new Dimension(150, 150));
        label_image.setOpaque(true);
        label_image.setBackground(Color.LIGHT_GRAY);

        panel_personal.add(panel_name, BorderLayout.WEST);
        panel_personal.add(label_image, BorderLayout.CENTER);

        JPanel panel_score = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panel_score.setBorder(new TitledBorder("학력 사항"));
        panel_score.add(new JLabel("학점:"));
        panel_score.add(text_field_score);
        panel_score.add(comboBox_scoreMax);
        comboBox_scoreMax.addItem("4.5 만점");
        comboBox_scoreMax.addItem("4.3 만점");

        JPanel panel_selfIntro = new JPanel(new BorderLayout());
        panel_selfIntro.setBorder(new TitledBorder("자기소개"));
        text_area_selfIntro.setLineWrap(true);
        text_area_selfIntro.setWrapStyleWord(true);
        panel_selfIntro.add(new JScrollPane(text_area_selfIntro), BorderLayout.CENTER);

        JPanel panel_save = new JPanel(new FlowLayout(FlowLayout.CENTER));
        panel_save.setBorder(new TitledBorder("저장"));
        panel_save.add(new JLabel("비밀번호:"));
        panel_save.add(PS_field_password);
        panel_save.add(btn_save);

        JPanel panel_data = new JPanel(new BorderLayout());
        panel_data.add(panel_personal, BorderLayout.NORTH);
        panel_data.add(panel_score, BorderLayout.SOUTH);

        add(panel_data, BorderLayout.NORTH);
        add(panel_selfIntro, BorderLayout.CENTER);
        add(panel_save, BorderLayout.SOUTH);

        btn_image.addActionListener(new imageListener());
        btn_save.addActionListener(new saveListener());

        setVisible(true);
    }

    class imageListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            JFileChooser chooser = new JFileChooser();
            int result = chooser.showOpenDialog(Exercise03_202024029.this);
            if (result == JFileChooser.APPROVE_OPTION) {
                File file = chooser.getSelectedFile();
                photoPath = file.getPath();

                ImageIcon icon = new ImageIcon(photoPath);
                Image scaled = icon.getImage().getScaledInstance(
                		label_image.getWidth(), 
                		label_image.getHeight(),
                        Image.SCALE_SMOOTH
                );
                label_image.setIcon(new ImageIcon(scaled));
                label_image.setText(null);
            }
        }
    }

    class saveListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String name = text_field_name.getText().trim();
            if (name.isEmpty()) {
                JOptionPane.showMessageDialog(
                        Exercise03_202024029.this,
                        "이름을 입력해주세요.",
                        "입력 오류",
                        JOptionPane.WARNING_MESSAGE
                );
                return;
            }
            System.out.println(name + "님, 이력서가 저장되었습니다.");
        }
    }

    public static void main(String[] args) {
    	Exercise03_202024029 window = new Exercise03_202024029();
    }
}
