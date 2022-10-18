import java.awt.*;
import java.awt.datatransfer.StringSelection;

import javax.swing.*;
import javax.swing.filechooser.*;

import javafx.stage.FileChooser;

import java.awt.event.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class TextEditor {

	private JFrame txtEditorFrame;
	private JTextPane textArea;
	boolean openBtnPressed = false, fileEdited = false, ifnewFile = false,allSelected=false;
	JFileChooser chooser = new JFileChooser();
	FileChooser multiChooser = new FileChooser();
	private MyFileStack redoStack = new MyFileStack();
	private MyFileStack undoStack = new MyFileStack();
	private MyFileStack openRecentStack = new MyFileStack();
	private static File selectedFile = null;
	private String cutOrCopiedTextString, completeText = "";
	int i = 0;
	private JMenu editMenu, openRecentMenu, fileMenu;
	private JMenuBar menuBar;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {

		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TextEditor window = new TextEditor();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});

	}

	/**
	 * Create the application.
	 */
	public TextEditor() {
		chooser.removeChoosableFileFilter(chooser.getFileFilter());
		chooser.addChoosableFileFilter(new FileNameExtensionFilter("Txt Files", "txt"));
		chooser.setCurrentDirectory(new File(System.getProperty("user.home") + "/Desktop"));
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		txtEditorFrame = new JFrame();
		txtEditorFrame.setVisible(true);
		txtEditorFrame.setTitle("Text Editor");
		txtEditorFrame.setBounds(100, 100, 848, 612);
		txtEditorFrame.setLocationRelativeTo(null);
		txtEditorFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		txtEditorFrame.setResizable(false);
		txtEditorFrame.getContentPane().setLayout(null);

		textArea = new JTextPane();
		textArea.addKeyListener(new KeyListener() {
			@Override
			public void keyTyped(KeyEvent e) {
				fileEdited = true;
				if (!(txtEditorFrame.getTitle().contains("*")))
					txtEditorFrame.setTitle("*" + txtEditorFrame.getTitle());
				undoStack.push(textArea.getText().substring(0, textArea.getText().length()));
				completeText = textArea.getText();
			}

			@Override
			public void keyReleased(KeyEvent e) {
				
			}
			@Override
			public void keyPressed(KeyEvent e) {
				
			}
		});
		textArea.setFont(new Font("Bahnschrift", Font.PLAIN, 15));

		JScrollPane scrollPane = new JScrollPane(textArea);
		scrollPane.setBounds(0, 0, 834, 545);
		txtEditorFrame.getContentPane().add(scrollPane);

		menuBar = new JMenuBar();
		txtEditorFrame.setJMenuBar(menuBar);

		fileMenu = new JMenu("File");
		menuBar.add(fileMenu);

		JMenuItem openMenuItem = new JMenuItem("Open");
		openMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				openBtnPressed = true;
				chooser.showOpenDialog(null);
				selectedFile = chooser.getSelectedFile();
				if (selectedFile != null) {
					try {

						openRecentBtn(selectedFile);
						txtEditorFrame.repaint();
						openRecentMenu.repaint();
						writeContent(selectedFile);
						textArea.setCaretPosition(0);

						undoStack.pushAtFirst(textArea.getText());
					} catch (Exception e2) {
						JOptionPane.showMessageDialog(null, e2);
					}
				} else {
					JOptionPane.showMessageDialog(null, "PLease select a file!", "Error!", JOptionPane.WARNING_MESSAGE);
				}
			}
		});

		JMenuItem newMenuItem = new JMenuItem("New File");
		newMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				chooser.setCurrentDirectory(new File(System.getProperty("user.home") + "/Desktop"));
				String prevTitle = chooser.getDialogTitle();
				chooser.setDialogTitle("Enter a name to save new file");
				int saved = chooser.showSaveDialog(null);
				chooser.setDialogTitle(prevTitle);
				if (saved == JFileChooser.APPROVE_OPTION) {
					textArea.setText("");
					selectedFile = chooser.getSelectedFile();
					openRecentBtn(selectedFile);
					if (!selectedFile.getName().contains(".txt"))
						txtEditorFrame.setTitle(selectedFile.getName() + ".txt");
					else
						txtEditorFrame.setTitle(selectedFile.getName());
				}
				ifnewFile = true;

			}
		});
		fileMenu.add(newMenuItem);

		JSeparator newSeparator = new JSeparator();
		fileMenu.add(newSeparator);
		fileMenu.add(openMenuItem);

		JMenuItem saveMenuItem = new JMenuItem("Save");
		saveMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					if (fileEdited) {
						String title = txtEditorFrame.getTitle();
						if (title.contains("*"))
							title = title.substring(1);
						txtEditorFrame.setTitle(title);
					}
					if (openBtnPressed) {
						FileWriter writeFile = new FileWriter(selectedFile);
						writeFile.flush();
						String input = textArea.getText();
						int counter = 0;
						while (counter < input.length()) {
							writeFile.write(input.charAt(counter++));
						}
						JOptionPane.showMessageDialog(null,
								selectedFile.getName() + " saved!" + "\nPath: " + selectedFile.getAbsolutePath());
						writeFile.close();
					} else {
						if (fileEdited && !openBtnPressed) {
							chooser.setCurrentDirectory(new File(System.getProperty("user.home") + "/Desktop"));
							int saved;
							if (!ifnewFile) {
								saved = chooser.showSaveDialog(null);
								FileWriter writeFile = new FileWriter(selectedFile + ".txt");
								txtEditorFrame.setTitle(selectedFile.getName() + ".txt");
								Scanner input = new Scanner(textArea.getText());
								while (input.hasNextLine()) {
									writeFile.write(input.nextLine());
									writeFile.write("\n");
								}
								writeFile.close();
							} else {
								saved = JFileChooser.APPROVE_OPTION;
								if (saved == JFileChooser.APPROVE_OPTION) {
									FileWriter writeFile = new FileWriter(chooser.getSelectedFile() + ".txt");
									txtEditorFrame.setTitle(chooser.getSelectedFile().getName() + ".txt");
									Scanner input = new Scanner(textArea.getText());
									while (input.hasNextLine()) {
										writeFile.write(input.nextLine());
										writeFile.write("\n");
									}
									JOptionPane.showMessageDialog(null,
											chooser.getSelectedFile().getName() + ".txt saved!");
									writeFile.close();
								}
							}
						}
					}
				} catch (Exception e2) {

				}
			}
		});

		openRecentMenu = new JMenu("Open Recent");
		fileMenu.add(openRecentMenu);

		JSeparator openSeparator = new JSeparator();
		fileMenu.add(openSeparator);
		fileMenu.add(saveMenuItem);

		editMenu = new JMenu("Edit");
		menuBar.add(editMenu);

		JMenuItem cutMenuItem = new JMenuItem("Cut");
		cutMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				cutOrCopiedTextString = textArea.getSelectedText();
				if (cutOrCopiedTextString != null) {
					Toolkit.getDefaultToolkit().getSystemClipboard()
							.setContents(new StringSelection(cutOrCopiedTextString), null);
					if(allSelected){
						textArea.setCaretPosition(0);
						textArea.setText("");
						return;
					}
					int position = textArea.getCaretPosition();

					String text = textArea.getText().substring(0, textArea.getText().indexOf(cutOrCopiedTextString));
					text += textArea.getText().substring(
							textArea.getText().indexOf(cutOrCopiedTextString) + cutOrCopiedTextString.length());
					textArea.setText(text);
					if (position != 0)
						textArea.setCaretPosition(position - cutOrCopiedTextString.length());
				} else {
					JOptionPane.showMessageDialog(textArea, "Please select some text to cut!");
				}
			}
		});
		editMenu.add(cutMenuItem);

		JSeparator cutSeparator = new JSeparator();
		editMenu.add(cutSeparator);

		JMenuItem copyMenuItem = new JMenuItem("Copy");
		editMenu.add(copyMenuItem);
		copyMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				cutOrCopiedTextString = textArea.getSelectedText();
				if (cutOrCopiedTextString != null) {
					Toolkit.getDefaultToolkit().getSystemClipboard()
							.setContents(new StringSelection(cutOrCopiedTextString), null);
					JOptionPane.showMessageDialog(txtEditorFrame, "Text copied to the clipboard.");
				} else {
					JOptionPane.showMessageDialog(textArea, "Please select some text to copy!");
				}
			}
		});

		JSeparator copySeparator = new JSeparator();
		editMenu.add(copySeparator);

		JMenuItem pasteMenuItem = new JMenuItem("Paste");
		pasteMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				if (cutOrCopiedTextString != null && !cutOrCopiedTextString.equals("")) {
					String text = textArea.getText();
					int position = textArea.getCaretPosition();

					textArea.setText(text.substring(0, position) + cutOrCopiedTextString + text.substring(position));
					textArea.setSelectionStart(position);
					textArea.setSelectionEnd(position + cutOrCopiedTextString.length());

					textArea.requestFocusInWindow();
					textArea.repaint();
				} else
					JOptionPane.showMessageDialog(txtEditorFrame, "Nothing to paste!");

			}
		});
		editMenu.add(pasteMenuItem);
		JMenuItem clearMenuItem = new JMenuItem("Clear");
		clearMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textArea.setText("");
				if (txtEditorFrame.getTitle().contains("*"))
					txtEditorFrame.setTitle(txtEditorFrame.getTitle().substring(1));
			}
		});

		JSeparator pasteSeparator = new JSeparator();
		editMenu.add(pasteSeparator);

		JMenuItem selectAllMItem = new JMenuItem("Select All");
		selectAllMItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				allSelected=true;
				textArea.setSelectionStart(0);
				textArea.setSelectionEnd(textArea.getText().length());
			}
		});
		editMenu.add(selectAllMItem);

		JSeparator selectSeparator = new JSeparator();
		editMenu.add(selectSeparator);
		editMenu.add(clearMenuItem);

		JMenuItem undoMenuItem = new JMenuItem("Undo");
		undoMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String title = txtEditorFrame.getTitle();
				if (!title.contains("*"))
					title = "*" + title;
				txtEditorFrame.setTitle(title);
				try {
					String t=textArea.getText();
					
					if(undoStack.peek().equals(textArea.getText())){
						undoStack.clear();
						return;
					}
					if (i++ == 0) {
						redoStack.pushAtFirst(textArea.getText());
						undoStack.removeAtFirst();
					}
					if (undoStack.peek().equals(""))
						undoStack.pop();
					String text = undoStack.pop();
					redoStack.push(text);
					textArea.setText(text);
					textArea.repaint();
					if(text.equals(t))
						undoStack.clear();
				} catch (Exception e2) {
					JOptionPane.showMessageDialog(null, e2);
				}
			}
		});
		menuBar.add(undoMenuItem);

		JMenuItem redoMenuItem = new JMenuItem("Redo");
		redoMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String title = txtEditorFrame.getTitle();
				if (!title.contains("*"))
					title = "*" + title;
				txtEditorFrame.setTitle(title);
				try {
					String t=textArea.getText();
					if (redoStack.peek().equals(""))
						redoStack.pop();
					else {
						String text = redoStack.pop();
						undoStack.push(text);
						textArea.setText(text);
						if(text.equals(t))
							redoStack.clear();
					}
					textArea.repaint();
				} catch (Exception e2) {
					JOptionPane.showMessageDialog(null, e2);
				}

			}
		});
		menuBar.add(redoMenuItem);

		JMenuItem closeMenuItem = new JMenuItem("Close");
		closeMenuItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int result = JOptionPane.showConfirmDialog(null, "Are you sure");
				if (result == JOptionPane.YES_OPTION)
					System.exit(0);
			}
		});
		menuBar.add(closeMenuItem);

	}

	private void openRecentBtn(File selectedFile) {
		try {
			// if file already added!b
			if (!openRecentStack.push(selectedFile.getAbsolutePath())) {
				return;
			}
			JMenuItem item = new JMenuItem(openRecentStack.peek());
			openRecentMenu.add(item);
			txtEditorFrame.repaint();
			openRecentMenu.repaint();
			menuBar.repaint();
			item.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					TextEditor.selectedFile = new File(item.getText());

					writeContent(TextEditor.selectedFile);
					undoStack.pushAtFirst(textArea.getText());
				}
			});
		} catch (Exception e) {
			JOptionPane.showMessageDialog(txtEditorFrame, e);

		}
	}

	private boolean writeContent(File selectedFile) {
		try {
			String content = new String(Files.readAllBytes(Paths.get(selectedFile.getAbsolutePath())));
			txtEditorFrame.setTitle(selectedFile.getName());
			textArea.setText("");
			textArea.setText(content);
			return true;
		} catch (Exception e) {
			return false;
		}
	}

}
