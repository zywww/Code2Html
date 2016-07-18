package GUI;

import ConvertCode.*;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JSplitPane;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.filechooser.FileSystemView;


public class Code2HtmlGUI extends JFrame {
	public  FileSystemView fileSystemView =
	        FileSystemView.getFileSystemView();
	
	private AddressAndSearchBar addressAndSearchBar = new AddressAndSearchBar();//GUI的地址栏和搜索栏
	private DirectoryTreePane directoryTreePane = new DirectoryTreePane();//GUI的目录树面板
	private FolderPane folderPane = new FolderPane();//GUI的文件夹面板
	private OptionPane optionPane = new OptionPane();//GUI的设置选项
	private JLabel bottom = new JLabel("底部");
	
	File[] newFiles;
	boolean isSearch = false;
	
	public Code2HtmlGUI() {
		
		//JPanel jp1 = new JPanel();
		JSplitPane jp1 = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, 
			directoryTreePane, folderPane);
		
		//JSplitPane jp2 = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
		//	jp1, optionPane);
		//jp1.setLayout(new BorderLayout());
		//jp1.add(directoryTreePane, BorderLayout.WEST);
		//jp1.add(folderPane);
		//jp1.add(optionPane, BorderLayout.EAST);
		
		directoryTreePane.getTree().addTreeSelectionListener(new TreeSelectionListener() {
			
			@Override
			public void valueChanged(TreeSelectionEvent e) {
				// TODO Auto-generated method stub
				File selectFile = directoryTreePane.getTree().getSelectFile();
				folderPane.setPath(selectFile);
				
				
				addressAndSearchBar.getJtfAddress().setText(
						selectFile.getAbsolutePath());
				
				optionPane.getJtfConverTo().setText(selectFile.getAbsolutePath());
				
				
			}
		});
		
		addressAndSearchBar.getJtfAddress().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String folderPath = addressAndSearchBar.getJtfAddress().getText();
				
				directoryTreePane.setSelectFolder(new File(folderPath));
				
				optionPane.getJtfConverTo().setText(folderPath);
			}
		});
		
		addressAndSearchBar.getJbtGo().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String folderPath = addressAndSearchBar.getJtfAddress().getText();
				
				directoryTreePane.setSelectFolder(new File(folderPath));
				
				optionPane.getJtfConverTo().setText(folderPath);
			}
		});
		
		addressAndSearchBar.getJbtBack().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String folderPath = addressAndSearchBar.getJtfAddress().getText();
				
				try {
					directoryTreePane.getTree().setSelectFile(new File(folderPath).getParentFile());
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				
				optionPane.getJtfConverTo().setText(folderPath);
				
			}
		});
		
		addressAndSearchBar.getJtfSearch().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				String search = addressAndSearchBar.getJtfSearch().getText();
				
				File[] files = folderPane.getFiles();
				newFiles = new File[files.length];
				
				int newFilesCount = 0;
				
				folderPane.getListModel().removeAllElements();
				for (int i = 0; i < files.length; i++) {
					if (files[i].getName().toLowerCase().contains(search.toLowerCase())) {
						newFiles[newFilesCount] = files[i];
						newFilesCount++;
						
						folderPane.getListModel().addElement(
								new Object[]{(ImageIcon)fileSystemView.getSystemIcon(files[i]),
								files[i].getName()});
					}
				}
				
				//folderPane.setFiles(newFiles);

			}
		});
		
		addressAndSearchBar.getJbtSearch().addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				String search = addressAndSearchBar.getJtfSearch().getText();

				File[] files = folderPane.getFiles();
				newFiles = new File[files.length];
				
				int newFilesCount = 0;
				
				folderPane.getListModel().removeAllElements();
				for (int i = 0; i < files.length; i++) {
					if (files[i].getName().toLowerCase().contains(search.toLowerCase())) {
						newFiles[newFilesCount] = files[i];
						newFilesCount++;
						
						folderPane.getListModel().addElement(
								new Object[]{(ImageIcon)fileSystemView.getSystemIcon(files[i]),
								files[i].getName()});
					}
				}
				
				//isSearch = true;
				folderPane.setFiles(newFiles);

			}
		});
		
		folderPane.getFileList().addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				if (e.getClickCount() == 2) { 
					int index = ((JList)e.getComponent()).getSelectedIndex();
					File selectiontedFile = folderPane.getFiles()[index];
					if (selectiontedFile.isDirectory()) {
						folderPane.setPath(selectiontedFile);
						addressAndSearchBar.getJtfAddress().setText(selectiontedFile.getAbsolutePath());
					
						optionPane.getJtfConverTo().setText(selectiontedFile.getAbsolutePath());
					}
				}
				
			}
		});
		
		optionPane.getJbtDefault().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				optionPane.getJtfConverTo().setText(folderPane.getPath().getAbsolutePath());
			}
		});
		
		optionPane.getJbtConvert().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int index[] = folderPane.getFileList().getSelectedIndices();
				
				for (int i = 0; i < index.length; i++) {
					File selectiontedFile = folderPane.getFiles()[index[i]];
					ConverCode2Html.convert(optionPane.getColors(),
							optionPane.getFontType(),
							optionPane.getFontSize(),
							selectiontedFile, 
							optionPane.getJtfConverTo().getText());
				}
				//System.out.println("yes");
				
			}
		});
		
		add(jp1, BorderLayout.CENTER);
		add(optionPane, BorderLayout.EAST);
		add(addressAndSearchBar, BorderLayout.NORTH);
		add(bottom, BorderLayout.SOUTH);
		
		//System.out.println(directoryTreePane.getTree().getModel().);
	}
	
	public static void main(String[] args){
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
		Code2HtmlGUI gui = new Code2HtmlGUI();
		gui.setTitle("Code2Html");
		gui.setSize(950, 650);
		gui.setLocationRelativeTo(null);
		gui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		gui.setVisible(true);
		
	}
}
