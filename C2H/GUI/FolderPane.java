package GUI;


import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;

import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
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
	
	
	private DefaultListModel listModel = new DefaultListModel();
	
	private JList fileList = new JList(listModel);
	
	JScrollPane jsp = new JScrollPane(fileList);

	private ListCellRenderer renderer = new C2HListCellRenderer();
	
	public FolderPane() {
		
		files = path.listFiles(new ExtensionFilter(new String[]{".java", ".c", ".cpp", ".h", ".html",
				".htm", ".js"}));
		

		for (int i = 0; i < files.length; i++) {		
			listModel.addElement(new Object[]{(ImageIcon)fileSystemView.getSystemIcon(files[i]),
				files[i].getName()});
		}
		
		fileList.setCellRenderer(renderer);
		
		
		setLayout(new BorderLayout());
		
		jsp.setPreferredSize(new Dimension(0, 559));
		add(jsp, BorderLayout.NORTH);
		
		addComponentListener(new ComponentAdapter() {
			@Override
			public void componentResized(ComponentEvent e) {
				// TODO Auto-generated method stub
				jsp.setPreferredSize(new Dimension(0, getBounds().height - 1));
			}
			
			
		});
	}
	
	public void setPath(File newPath) {
		if (path != newPath) {
			path = newPath;
			repaint();
		}
	}
	
	public File getPath() {
		return path;
	}
	
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		listModel.removeAllElements();
		
		files = path.listFiles(new ExtensionFilter(new String[]{".java", ".c", ".cpp", ".h", ".html",
				".htm", "js"}));
		
		if (files != null){
			for (int i = 0; i < files.length; i++) {		
				listModel.addElement(new Object[]{(ImageIcon)fileSystemView.getSystemIcon(files[i]),
					files[i].getName()});
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
	
	public JScrollPane getJsp() {
		return jsp;
	}
	
}
