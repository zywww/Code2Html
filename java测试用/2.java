package GUI;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.filechooser.FileSystemView;

public class AddressAndSearchBar extends JPanel {
	public FileSystemView fileSystemView =
	        FileSystemView.getFileSystemView();
	
	//File path;
	
	JFileTree tree;
	
	JTextField jtfAddress = new JTextField(60);
	JTextField jtfSearch = new JTextField(15);
	JButton jbtGo = new JButton("=>");
	JButton jbtBack = new JButton("后退");
	JButton jbtForward = new JButton("前进");
	JButton jbtSearch = new JButton("搜索");
	
	public AddressAndSearchBar() {
		Box box = Box.createHorizontalBox();
		
		JLabel jlbAddress = new JLabel("地址：");
		
		
		
		
		
		
		
		box.add(Box.createHorizontalStrut(30));
		
		box.add(jbtBack);
		box.add(Box.createHorizontalStrut(10));
		box.add(jbtForward);
		
		box.add(Box.createHorizontalStrut(10));
		box.add(jlbAddress);
		box.add(Box.createHorizontalStrut(10));
		box.add(jtfAddress);
		box.add(jbtGo);
		
		box.add(Box.createHorizontalStrut(70));
		//box.add(Box.createGlue());
		
		box.add(jtfSearch);
		box.add(Box.createHorizontalStrut(10));
		box.add(jbtSearch);
		
		//jtfAddress.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY));
		jtfAddress.setText(fileSystemView.getRoots()[0].getAbsolutePath());
		/*jtfAddress.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				File folderPath = new File(jtfAddress.getText());
				
				if(folderPath.isDirectory()) {
					path = folderPath;
				}
				
			}
		});*/
		//jtfSearch.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY));
		
		add(box);
		
		/*JPanel jp1 = new JPanel();
		jp1.add(jbtBack);
		jp1.add(jbtForward);
		
		JPanel jp2 = new JPanel();
		jp2.add(jlbAddress);
		jp2.add(jtaAddress);
		
		JPanel jp3 = new JPanel();
		jp3.add(jtaSearch);
		jp3.add(jbtSearch);
		
		setLayout(new BorderLayout());
		add(jp1, BorderLayout.WEST);
		add(jp2, BorderLayout.CENTER);
		add(jp3, BorderLayout.EAST);*/
		
		setBorder(BorderFactory.createLineBorder(Color.lightGray));
		
	}
	
	/*public void setTree(JFileTree tree) {
		this.tree = tree;
	}
	
	public void setPath(File path) {
		this.path = path;
	}*/
	
	public JTextField getJtfAddress() {
		return jtfAddress;
	}
	
	public JButton getJbtGo() {
		return jbtGo;
	}
	
	public JButton getJbtBack() {
		return jbtBack;
	}
	
	public JButton getJbtForward() {
		return jbtForward;
	}
	
	public JTextField getJtfSearch() {
		return jtfSearch;
	}
	
	public JButton getJbtSearch() {
		return jbtSearch;
	}
}
