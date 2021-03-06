package btt.screens;

import btt.dao.ToDoDAO;
import btt.db.Macros;
import btt.db.MySqlDbConnection;
import btt.model.ToDo;
import btt.util.PopupFactory;
import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.Date;
import java.sql.SQLException;
import java.sql.Time;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.TreeSet;
import javax.imageio.ImageIO;


public class TodoForm extends javax.swing.JFrame {

    private Connection conn;
    private ToDo todo;
    private UserScreen parent;
    

    public TodoForm(TreeSet<String> categoryList, ToDo td, UserScreen parent) {
        initComponents();
        this.parent = parent;

        // Set the icon for this frame
        try {
            this.setIconImage(ImageIO.read(new File("images/icon.png")));
        } catch(IOException e) {
            System.out.println("Icon not found");
            e.printStackTrace();
        }

        for (String s : categoryList) {
            // Add available categories into the combobox
            CategoryCombobox.insertItemAt(s, 0);
        }

        this.conn = MySqlDbConnection.getConnection();

        if (conn == null) {
            PopupFactory.showError(this, "Internal Error");
            this.dispose();
        }

        // If this is an update form, ToDo will be a valid instance
        // Otherwise it is just a new ToDo form
        this.todo = td;
        if (todo != null) {
            AcceptButton.setText("Update ToDo");

            // Set current fields
            TitleInput.setText(todo.title);
            DescriptionInput.setText(todo.description);
            DateInput.setText(ToDo.normalizeStupidDate(todo.due));
            CategoryCombobox.setSelectedItem(todo.category);
        } else {
            // Default date
            DateInput.setText(new SimpleDateFormat("dd/MM/yyyy").format(new Time(System.currentTimeMillis())));
        }
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        TitleInput = new javax.swing.JTextField();
        CategoryCombobox = new javax.swing.JComboBox<>();
        jLabel1 = new javax.swing.JLabel();
        DescriptionInput = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        AcceptButton = new javax.swing.JButton();
        DateInput = new javax.swing.JFormattedTextField();
        jLabel5 = new javax.swing.JLabel();
        CancelButton = new javax.swing.JToggleButton();

        setTitle("BTT - To-Do Form");
        setMaximumSize(new java.awt.Dimension(600, 300));
        setMinimumSize(new java.awt.Dimension(600, 300));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        jPanel1.setBackground(new java.awt.Color(13, 71, 161));
        jPanel1.setMaximumSize(new java.awt.Dimension(600, 300));
        jPanel1.setMinimumSize(new java.awt.Dimension(600, 300));

        CategoryCombobox.setToolTipText("");

        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("Title");

        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("Description");

        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setText("Select Category");

        jLabel4.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        jLabel4.setForeground(new java.awt.Color(255, 255, 255));
        jLabel4.setText("Create New To-Do");

        AcceptButton.setBackground(new java.awt.Color(0, 77, 64));
        AcceptButton.setForeground(new java.awt.Color(255, 255, 255));
        AcceptButton.setText("Accept");
        AcceptButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AcceptButtonActionPerformed(evt);
            }
        });

        DateInput.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.DateFormatter()));

        jLabel5.setForeground(new java.awt.Color(255, 255, 255));
        jLabel5.setText("Due Date (dd/MM/yyyy)");

        CancelButton.setBackground(new java.awt.Color(198, 40, 40));
        CancelButton.setForeground(new java.awt.Color(255, 255, 255));
        CancelButton.setText("Cancel");
        CancelButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CancelButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(TitleInput, javax.swing.GroupLayout.PREFERRED_SIZE, 240, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(DateInput, javax.swing.GroupLayout.PREFERRED_SIZE, 240, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 12, Short.MAX_VALUE)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                        .addComponent(CancelButton, javax.swing.GroupLayout.PREFERRED_SIZE, 140, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(18, 18, 18)
                                        .addComponent(AcceptButton, javax.swing.GroupLayout.PREFERRED_SIZE, 140, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(CategoryCombobox, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE))))
                            .addComponent(DescriptionInput))
                        .addGap(20, 20, 20))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel4)
                            .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 240, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addComponent(jLabel4)
                .addGap(29, 29, 29)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(TitleInput, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(CategoryCombobox, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(30, 30, 30)
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(DescriptionInput, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 24, Short.MAX_VALUE)
                .addComponent(jLabel5)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(AcceptButton, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(CancelButton, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(DateInput, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(23, 23, 23))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void AcceptButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AcceptButtonActionPerformed
        String title = TitleInput.getText();
        String desc = DescriptionInput.getText();
        int selected = CategoryCombobox.getSelectedIndex();

        if (selected == -1) {
            PopupFactory.showError(this, "Please select a category");
        } else {
            // Category is selected
            String category = CategoryCombobox.getItemAt(selected);

            // Treat the database maximum length
            String error = "";
            if (title.length() > Macros.MaxLenToDoTitle) {
                error = error + "<p>Title must have at most " + Macros.MaxLenToDoTitle + " letters</p>";
            }
            if (desc.length() > Macros.MaxLenToDoDesc) {
                error = error + "<p>Description must have at most " + Macros.MaxLenToDoDesc + " letters</p>";
            }
            if (!error.equals("")) {
                PopupFactory.showError(this, "<html> " + error);
            } else {

                // Try parse date
                Date date = null;
                try {
                    date = new Date(new SimpleDateFormat("dd/MM/yyyy").parse(DateInput.getText()).getTime());
                } catch (ParseException e) {
                    PopupFactory.showError(this, "Invalid date format.");
                    e.printStackTrace();
                }

                // Now all parameters are checked

                // Now check if this is an update form or a new to-do form
                if (todo == null) {
                    // Add new to-do
                    try {
                        ToDoDAO.add(conn, title, desc, category, date);
                        this.conn.close();
                        parent.reloadToDoList();
                    } catch(SQLException e) {
                        PopupFactory.showError(this, "Internal Error");
                        e.printStackTrace();
                    } finally {
                        this.dispose();
                    }
                } else {
                    // Update current to-do
                    try {
                        ToDoDAO.update(conn, todo.id, title, desc, category, date);
                        this.conn.close();
                        parent.reloadToDoList();
                    } catch (SQLException e) {
                        PopupFactory.showError(this, "Internal Error");
                        e.printStackTrace();
                    } finally {
                        this.dispose();
                    }
                }
            }
        }
    }//GEN-LAST:event_AcceptButtonActionPerformed

    private void CancelButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CancelButtonActionPerformed
        try {
            this.conn.close();
        } catch (SQLException e) {
            PopupFactory.showError(this, "Internal Error");
            e.printStackTrace();
        }
        this.dispose();
    }//GEN-LAST:event_CancelButtonActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        try {
            this.conn.close();
        } catch (SQLException e) {
            PopupFactory.showError(this, "Internal Error");
            e.printStackTrace();
        }
    }//GEN-LAST:event_formWindowClosing

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton AcceptButton;
    private javax.swing.JToggleButton CancelButton;
    private javax.swing.JComboBox<String> CategoryCombobox;
    private javax.swing.JFormattedTextField DateInput;
    private javax.swing.JTextField DescriptionInput;
    private javax.swing.JTextField TitleInput;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
