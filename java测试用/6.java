package GUI;


import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.io.File;

import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ListCellRenderer;
import javax.swing.filechooser.FileSystemView;

import Tools.ExtensionFilter;

public class FolderPane extends JPanel {
	public  FileSystemView fileSystemView =
		FileSystemView.getFileSystemView();
	
	private File path = fileSystemView.getRoots()[0];
	
	private File[] files;
	
	//private ImageIcon[] icons;
	
	//private String[] strName;
	
	private DefaultListModel listModel = new DefaultListModel();
	
	private JList fileList = new JList(listModel);
	
	private ListCellRenderer renderer = new C2HListCellRenderer();
	
	public FolderPane() {
		
		files = path.listFiles(new ExtensionFilter(new String[]{".java", ".c", ".cpp", ".h"}));
		
		/*icons = new ImageIcon[files.length];
		
		for (int i = 0; i < files.length; i++) {
			icons[i] = new ImageIcon();
		}
		
		strName = new String[files.length];
		
		for (int i = 0; i < files.length; i++) {
			strName[i] = new String();
		}*/

		for (int i = 0; i < files.length; i++) {		
			listModel.addElement(new Object[]{(ImageIcon)fileSystemView.getSystemIcon(files[i]),
				files[i].getName()});
		}
		
		fileList.setCellRenderer(renderer);
		
		
		JScrollPane jsp = new JScrollPane(fileList);
		jsp.setPreferredSize(new Dimension(464, 555));
		//setBorder(BorderFactory.createLineBorder(Color.black));
		add(jsp);
		
		
		
	}
	
	public void setPath(File newPath) {
		if (path != newPath) {
			path = newPath;
			repaint();
			//System.out.println("repaint");
		}
	}
	
	public File getPath() {
		return path;
	}
	
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		listModel.removeAllElements();
		
		files = path.listFiles(new ExtensionFilter(new String[]{".java", ".c", ".cpp", ".h"}));
		
		if (files != null){
			for (int i = 0; i < files.length; i++) {		
				listModel.addElement(new Object[]{(ImageIcon)fileSystemView.getSystemIcon(files[i]),
					files[i].getName()});
				/*icons[i] = (ImageIcon)fileSystemView.getSystemIcon(files[i]);
				strName[i] = files[i].getName();
				listModel.addElement(new Object[]{icons[i], strName[i]});*/
			}
		}
	}
	
	public File[] getFiles() {
		return files;
	}
	
	public void setFiles(File[] files) {
		this.files = files;
	}
	
	public DefaultListModel getListModel() {
		return listModel;
	}
	
	public JList getFileList() {
		return fileList;
	}
	
}
