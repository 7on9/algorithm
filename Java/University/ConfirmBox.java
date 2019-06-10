import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Stack;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class ConfirmBox extends JFrame
{
  private static final long serialVersionUID = 1L;
  JButton btCheck;
  JTextField tfUserInput;
  JTextArea taRandomNumber;
  Character[] ListChar = { Character.valueOf('a'), Character.valueOf('_'), Character.valueOf('y'), Character.valueOf('l'), Character.valueOf('_'), Character.valueOf('l'), Character.valueOf('a'), Character.valueOf('T'), Character.valueOf('_'), Character.valueOf('T'), Character.valueOf('_'), Character.valueOf('T'), Character.valueOf('e'), Character.valueOf('_'), Character.valueOf('y'), Character.valueOf('e'), Character.valueOf('r'), Character.valueOf('_'), Character.valueOf('S'), Character.valueOf('_'), Character.valueOf('_'), Character.valueOf('l'), Character.valueOf('r'), Character.valueOf('T'), Character.valueOf('F'), Character.valueOf('_'), Character.valueOf('Y'), Character.valueOf('_'), Character.valueOf('l'), Character.valueOf('e'), Character.valueOf('T'), Character.valueOf('T'), Character.valueOf('T'), Character.valueOf('a'), Character.valueOf('r'), Character.valueOf('T'), Character.valueOf('u'), Character.valueOf('A'), Character.valueOf('o') };
  int[] ListPos = { 11, 7, 14, 13, 26, 22, 4, 34, 15, 37, 3, 31, 19, 27, 23, 6, 18, 25, 30, 24, 17, 12, 9, 38, 28, 8, 0, 16, 21, 10, 32, 36, 33, 20, 5, 35, 2, 29, 1 };
  Stack<Double> ListRandomNumber;
  
  public ConfirmBox() {
    ListRandomNumber = new Stack();
  }
  public String generateFlag()
  {
    String flag = "";
    Character[] tmpListChar = { Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000'), Character.valueOf('\000') };
    int lenFlag = ListChar.length;
    for (int i = 0; i < lenFlag; i++) {
      tmpListChar[ListPos[i]] = ListChar[i];
    }
    for (int i = 0; i < lenFlag; i++) {
      flag = flag + tmpListChar[i];
    }
    return flag;
  }
  public static void main(String[] args) {
    ConfirmBox f = new ConfirmBox();

    System.out.print(f.generateFlag());
  }
}
  
