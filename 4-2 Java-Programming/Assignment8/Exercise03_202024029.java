package week10;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Exercise03_202024029 extends JFrame implements MouseListener, MouseMotionListener {
    private JLabel lbl_pos = new JLabel("좌표: (0, 0)");
    private JLabel lbl_state = new JLabel("이벤트 대기 중...");
    private JPanel panel = new JPanel();

    public void mousePressed(MouseEvent e) { lbl_state.setText("마우스 눌림"); }
    public void mouseReleased(MouseEvent e) { lbl_state.setText("마우스 떼어짐"); }
    public void mouseClicked(MouseEvent e) { lbl_state.setText("마우스 클릭됨"); }
    public void mouseEntered(MouseEvent e) { lbl_state.setText("마우스 들어옴"); }
    public void mouseMoved(MouseEvent e) { lbl_pos.setText(pos_txt(e, true)); }
    public void mouseDragged(MouseEvent e) {
    	lbl_state.setText("마우스 드래그 중...");
        lbl_pos.setText(pos_txt(e, true));
    }
    public void mouseExited(MouseEvent e) {
    	lbl_state.setText("마우스 나감");
    	lbl_pos.setText(pos_txt(e, false));
    }
    private String pos_txt(MouseEvent e, boolean isValid) {
    	if (!isValid) return "좌표: (---, ---)";
        return String.format("좌표: (%d, %d)", e.getX(), e.getY());
    }
    
    public Exercise03_202024029() {
        super("마우스 이벤트 추적기");
        setSize(600, 350);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        lbl_pos.setHorizontalAlignment(JLabel.CENTER);
        lbl_state.setHorizontalAlignment(JLabel.CENTER);
        add(lbl_pos, BorderLayout.NORTH);
        add(lbl_state, BorderLayout.SOUTH);

        panel.setBackground(Color.YELLOW);
        add(panel, BorderLayout.CENTER);

        panel.addMouseListener(this);
        panel.addMouseMotionListener(this);

        setVisible(true);
    }

	public static void main(String[] args) {
		Exercise03_202024029 window = new Exercise03_202024029();
	}
}
