package GUI;


import java.awt.BorderLayout;
import java.awt.Dimension;
import java.io.File;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.filechooser.FileSystemView;

public class DirectoryTreePane extends JPanel {
	private JFileTree tree = new JFileTree();
	
	public  FileSystemView fileSystemView =
	        FileSystemView.getFileSystemView();
	
	JScrollPane jsp = new JScrollPane(tree);
	
	public DirectoryTreePane() {
		
		try{
            tree.setSelectFile(fileSystemView.getRoots()[0]);
        } catch(Exception ex){
            ex.printStackTrace();
        }
		
		setLayout(new BorderLayout());

		add(jsp, BorderLayout.CENTER);
		
		setPreferredSize(new Dimension(230, 0));
		
	}
	
	public File getSelectFile(){
		return tree.getSelectFile();
	}
	
	public JFileTree getTree() {
		return tree;
	}
	
	public JScrollPane getJsp() {
		return jsp;
	}
	
	public void setSelectFolder(File path) {
		try {
			tree.setSelectFile(path);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
