package GUI;

import java.awt.Component;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListCellRenderer;

import java.awt.*;

import javax.swing.*;

public class C2HListCellRenderer implements ListCellRenderer {
	private JLabel jlbCell = new JLabel(" ", JLabel.LEFT);
	
	public Component getListCellRendererComponent
    (JList list, Object value, int index, boolean isSelected,
     boolean cellHasFocus) {
		Object[] pair = (Object[])value;
		jlbCell.setOpaque(true);
		jlbCell.setIcon((ImageIcon)pair[0]);
		jlbCell.setText(pair[1].toString());

		if (isSelected) {
			jlbCell.setForeground(list.getSelectionForeground());
			jlbCell.setBackground(list.getSelectionBackground());
		}
		else {
			jlbCell.setForeground(list.getForeground());
			jlbCell.setBackground(list.getBackground());
		}


		return jlbCell;
	}
}
