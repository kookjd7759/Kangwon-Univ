package week7;

import javax.swing.*;
import java.awt.*;

public class Exercise03_202024029 extends JFrame {
    public Exercise03_202024029() {
        super("데이터 기반 좌석 배치");
        setSize(850, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        add(new JLabel("S C R E E N", JLabel.CENTER), BorderLayout.NORTH);

        JPanel center = new JPanel(null);
        add(center, BorderLayout.CENTER);

        String[][] seats = {
                {"B","B","B","B","-","-","B","B","B","B"},
                {"A","A","A","A","-","-","A","A","A","A"},
                {"A","A","S","S","-","-","S","S","A","A"},
                {"S","S","S","S","X","X","S","S","S","S"}
        };

        int w = 65, h = 40;
        for (int i = 0; i < seats.length; i++) {
            for (int j = 0; j < seats[i].length; j++) {
                String type = seats[i][j];
                if (type.equals("-")) continue;
                
                String name = String.valueOf((char)('A' + i)) + (j + 1);
                JButton seat = new JButton(name);

                int x = 40 + j * (w + 10);
                int y = 40 + i * (h + 10);
                seat.setBounds(x, y, w, h);

                if (type.equals("S")) 		seat.setBackground(Color.ORANGE);
                else if (type.equals("A")) 	seat.setBackground(Color.LIGHT_GRAY);
                else if (type.equals("B")) 	seat.setBackground(Color.CYAN);
                if (type.equals("X")) 		seat.setEnabled(false);

                center.add(seat);
            }
        }

        setVisible(true);
    }

    public static void main(String[] args) {
    	Exercise03_202024029 window = new Exercise03_202024029();
    }
}
