package week10;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Exercise02_202024029 extends JFrame implements ActionListener, KeyListener {
	private JTextField lbl = new JTextField("음이름이 표시됩니다.");
	private JButton btn_a = new JButton("도(A)");
	private JButton btn_s = new JButton("레(S)");
	private JButton btn_d = new JButton("미(D)");
	private JButton btn_f = new JButton("파(F)");
	private JButton btn_g = new JButton("솔(G)");
	private JButton btn_h = new JButton("라(H)");
	private JButton btn_j = new JButton("시(J)");

	public Exercise02_202024029() {
		super("미니 피아노");
		setSize(520, 250);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new BorderLayout());
	
		lbl.setEditable(false);
		lbl.setHorizontalAlignment(JLabel.CENTER);
		add(lbl, BorderLayout.NORTH);
	
		JPanel p = new JPanel(new FlowLayout(FlowLayout.CENTER));
		p.add(btn_a); p.add(btn_s); p.add(btn_d); p.add(btn_f); 
		p.add(btn_g); p.add(btn_h); p.add(btn_j);
		add(p);
	
		btn_a.addActionListener(this);
		btn_s.addActionListener(this);
		btn_d.addActionListener(this);
		btn_f.addActionListener(this);
		btn_g.addActionListener(this);
		btn_h.addActionListener(this);
		btn_j.addActionListener(this);
	
		addKeyListener(this);
		
		setFocusable(true);
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e) {
		Object src = e.getSource();
		if (src == btn_a)      lbl.setText("도(A)");
		else if (src == btn_s) lbl.setText("레(S)");
		else if (src == btn_d) lbl.setText("미(D)");
		else if (src == btn_f) lbl.setText("파(F)");
		else if (src == btn_g) lbl.setText("솔(G)");
		else if (src == btn_h) lbl.setText("라(H)");
		else if (src == btn_j) lbl.setText("시(J)");
	}
	
	public void keyPressed(KeyEvent e) {
		switch (e.getKeyCode()) {
			case KeyEvent.VK_A: lbl.setText("도(A)"); break;
			case KeyEvent.VK_S: lbl.setText("레(S)"); break;
			case KeyEvent.VK_D: lbl.setText("미(D)"); break;
			case KeyEvent.VK_F: lbl.setText("파(F)"); break;
			case KeyEvent.VK_G: lbl.setText("솔(G)"); break;
			case KeyEvent.VK_H: lbl.setText("라(H)"); break;
			case KeyEvent.VK_J: lbl.setText("시(J)"); break;
		}
	}
	public void keyReleased(KeyEvent e) {}
	public void keyTyped(KeyEvent e) {}

	public static void main(String[] args) {
		Exercise02_202024029 window = new Exercise02_202024029();
	}
}
