package GUI;

import java.awt.Color;
import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.filechooser.FileSystemView;

public class AddressAndSearchBar extends JPanel {
	public FileSystemView fileSystemView =
	        FileSystemView.getFileSystemView();
	

	
	JFileTree tree;
	
	JTextField jtfAddress = new JTextField(60);
	JTextField jtfSearch = new JTextField(15);
	JButton jbtGo = new JButton("=>");
	JButton jbtBack = new JButton("…œ“ª≤„");

	JButton jbtSearch = new JButton("À—À˜");
	
	public AddressAndSearchBar() {
		Box box = Box.createHorizontalBox();
		
		JLabel jlbAddress = new JLabel("µÿ÷∑£∫");
	
		box.add(Box.createHorizontalStrut(30));
		
		box.add(jbtBack);

		
		box.add(Box.createHorizontalStrut(10));
		box.add(jlbAddress);
		box.add(Box.createHorizontalStrut(10));
		box.add(jtfAddress);
		box.add(jbtGo);
		
		box.add(Box.createHorizontalStrut(70));

		
		box.add(jtfSearch);
		box.add(Box.createHorizontalStrut(10));
		box.add(jbtSearch);
		

		jtfAddress.setText(fileSystemView.getRoots()[0].getAbsolutePath());
		
		
		add(box);
		

		setBorder(BorderFactory.createLineBorder(Color.lightGray));
		
	}
	
	public JTextField getJtfAddress() {
		return jtfAddress;
	}
	
	public JButton getJbtGo() {
		return jbtGo;
	}
	
	public JButton getJbtBack() {
		return jbtBack;
	}
	
	public JTextField getJtfSearch() {
		return jtfSearch;
	}
	
	public JButton getJbtSearch() {
		return jbtSearch;
	}
}
