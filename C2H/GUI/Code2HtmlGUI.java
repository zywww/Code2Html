package GUI;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowEvent;
import java.awt.event.WindowStateListener;
import java.io.File;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JProgressBar;
import javax.swing.JSplitPane;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.filechooser.FileSystemView;

import ConvertCode.ConverCode2Html;


public class Code2HtmlGUI extends JFrame {
	public  FileSystemView fileSystemView =
	        FileSystemView.getFileSystemView();
	
	private AddressAndSearchBar addressAndSearchBar = new AddressAndSearchBar();//GUI的地址栏和搜索栏
	private DirectoryTreePane directoryTreePane = new DirectoryTreePane();//GUI的目录树面板
	private FolderPane folderPane = new FolderPane();//GUI的文件夹面板
	private OptionPane optionPane = new OptionPane();//GUI的设置选项
	private JLabel bottom = new JLabel("   ");//GUI的底栏

	public static JProgressBar progressbar = new JProgressBar();//底栏进度条
	
	File[] newFiles;
	boolean isSearch = false;
	
	
	
	public Code2HtmlGUI() {
		
		progressbar.setOrientation(JProgressBar.HORIZONTAL);
		
		progressbar.setMinimum(0);

	    progressbar.setMaximum(10000);

	    progressbar.setValue(0);

	    progressbar.setStringPainted(true);
	    
	    progressbar.setPreferredSize(new Dimension(300, 20));
	    
	    progressbar.setBackground(Color.white);

	    progressbar.setForeground(new Color(50, 255, 50));
	    
	   
	    
	    bottom.add(progressbar);
	    progressbar.setBounds(0, 0, 950, 60);
	    progressbar.setVisible(false);
		
		
		JSplitPane jp1 = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, 
			directoryTreePane, folderPane);
		
		directoryTreePane.getTree().addTreeSelectionListener(new TreeSelectionListener() {
			
			@Override
			public void valueChanged(TreeSelectionEvent e) {
				// TODO Auto-generated method stub
				File selectFile = directoryTreePane.getTree().getSelectFile();
				folderPane.setPath(selectFile);

				// TODO 
				try {
				addressAndSearchBar.getJtfAddress().setText(
						selectFile.getAbsolutePath());
				
				optionPane.getJtfConverTo().setText(selectFile.getAbsolutePath() + "     ");}
				catch (NullPointerException e1) {
					
				}
				
				
			}
		});
		
		addressAndSearchBar.getJtfAddress().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String folderPath = addressAndSearchBar.getJtfAddress().getText();

				
				folderPane.setPath(new File(folderPath));
				
				optionPane.getJtfConverTo().setText(folderPath + "     ");
			}
		});
		
		addressAndSearchBar.getJbtGo().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String folderPath = addressAndSearchBar.getJtfAddress().getText();
				
				folderPane.setPath(new File(folderPath));
				
				optionPane.getJtfConverTo().setText(folderPath + "     ");
			}
		});
		
		addressAndSearchBar.getJbtBack().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				
				File folderPath = new File(addressAndSearchBar.getJtfAddress().getText());
				if (folderPath.getParentFile() != null) {	
				
				addressAndSearchBar.getJtfAddress().setText(
						folderPath.getParentFile().getAbsolutePath());
				folderPane.setPath(folderPath.getParentFile());
				optionPane.getJtfConverTo().setText(folderPath.getParentFile().getAbsolutePath() +
						"     ");
				}
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
					
						optionPane.getJtfConverTo().setText(selectiontedFile.getAbsolutePath() + "     ");
						
					}
				}	
			}
		});
		
		folderPane.getFileList().addFocusListener(new FocusListener() {
			
			@Override
			public void focusLost(FocusEvent e) {
				// TODO Auto-generated method stub
				bottom.setText("   ");
			}
			
			@Override
			public void focusGained(FocusEvent e) {
				// TODO Auto-generated method stub
				bottom.setText("配合Ctrl键可选择多个文件进行转换。文件太大时，转换时间会较长。");
			}
		});
		
		
		optionPane.getJbtDefault().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				optionPane.getJtfConverTo().setText(folderPane.getPath().getAbsolutePath() + "     ");
			}
		});
		
		optionPane.getJbtConvert().addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Thread thread = new Thread(new conver());
				thread.start();
				
				
			}
		});
		
		optionPane.getJcbSourceCode().addFocusListener(new FocusListener() {
			@Override
			public void focusLost(FocusEvent e) {
				// TODO Auto-generated method stub
				bottom.setText("   ");
			}
			
			@Override
			public void focusGained(FocusEvent e) {
				// TODO Auto-generated method stub
				bottom.setText("可不选择，程序会自动匹配类型");
			}
		});
		
		bottom.addComponentListener(new ComponentAdapter() {
			@Override
			public void componentResized(ComponentEvent e) {
				// TODO Auto-generated method stub
				progressbar.setBounds(0, 0, bottom.getWidth(), bottom.getHeight());
			}
		});
		
		
		addWindowStateListener(new WindowStateListener() {
			
			@Override
			public void windowStateChanged(WindowEvent e) {
				// TODO Auto-generated method stub
				
				if (e.getNewState() == MAXIMIZED_BOTH) {
					int height = 
						getHeight() - addressAndSearchBar.getHeight() - bottom.getHeight() - 45;
					
					folderPane.getJsp().setPreferredSize(new Dimension(0, height));
				}
				else if (e.getNewState() == NORMAL) {
					int height = 
							getHeight() - addressAndSearchBar.getHeight() - bottom.getHeight() - 45;
						
						folderPane.getJsp().setPreferredSize(new Dimension(0, height));
				}
					
				
			}
		});
		
		add(jp1, BorderLayout.CENTER);
		add(optionPane, BorderLayout.EAST);
		add(addressAndSearchBar, BorderLayout.NORTH);
		add(bottom, BorderLayout.SOUTH);
		
		

		setIconImage(new ImageIcon("logo.png").getImage());

		
	}
	
	private class conver implements Runnable {
		public void run() {
			Thread thread = new Thread(new changeValue());
			thread.start();
			
			int index[] = folderPane.getFileList().getSelectedIndices();
			int successCount = 0;
			
			for (int i = 0; i < index.length; i++) {
				File selectiontedFile = folderPane.getFiles()[index[i]];
				if (selectiontedFile.isFile() && 
					!selectiontedFile.getName().endsWith(".html")) 
					successCount++;
			}
			
			if (successCount != 0) {
				progressbar.setVisible(true);
			}
			
			ConverCode2Html.taskNum = successCount;
			ConverCode2Html.done = 0;

			
			for (int i = 0; i < index.length; i++) {
				File selectiontedFile = folderPane.getFiles()[index[i]];
				if (selectiontedFile.isFile() && 
					!selectiontedFile.getName().endsWith(".html")) {

					ConverCode2Html.convert(optionPane.getColors(),
							optionPane.getFontType(),
							optionPane.getFontSize(),
							selectiontedFile, 
							optionPane.getJtfConverTo().getText().trim());
					
					
					ConverCode2Html.done++;

				}
				
			}
			
			if (successCount != 0) 
				JOptionPane.showMessageDialog(null, successCount + "个文件转换成功！");	
			
			else 
				JOptionPane.showMessageDialog(null, "您选择了无效的文件");
			
			thread = null;
			progressbar.setVisible(false);
			folderPane.repaint();
		}
	}
	
	private class changeValue implements Runnable {
		public void run() {
			while (true) {
				try {
					Thread.sleep(300);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				progressbar.setValue(ConverCode2Html.value);
			}
			
		}
	}

	
	public static void main(String[] args){
		try {//UIManager.getSystemLookAndFeelClassName()
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
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
