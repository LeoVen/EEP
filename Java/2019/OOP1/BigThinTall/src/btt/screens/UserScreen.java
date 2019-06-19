package btt.screens;

import btt.Main;
import btt.dao.CategoryDAO;
import btt.dao.ToDoDAO;
import btt.db.Macros;
import btt.db.MySqlDbConnection;
import btt.model.ToDo;
import btt.model.UserConfig;
import btt.util.PopupFactory;
import btt.util.StringReceiver;
import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.TreeSet;
import javax.imageio.ImageIO;
import javax.swing.DefaultListModel;


public class UserScreen extends javax.swing.JFrame {

    Connection conn;
    private TreeSet<String> categoryList;
    private ArrayList<ToDo> todoList;
    private UserConfig config;
    private DefaultListModel categories;
    private DefaultListModel todos;
    private String selectedCategory;


    public UserScreen(UserConfig config) {
        initComponents();
        this.config = config;
        this.conn = MySqlDbConnection.getConnection();

        if (conn == null) {
            PopupFactory.showError(this, "Internal Error");
            this.dispose();
        }

        todos = (DefaultListModel) TodoList.getModel();
        categories = (DefaultListModel) CategoryList.getModel();
        CategoryList.setSelectionBackground(new java.awt.Color(13,71,161));

        todoList = new ArrayList<>();
        try {
            categoryList = CategoryDAO.getAll(conn, config.userId);

            categoryList.forEach( (k) -> {
                categories.addElement(k);
            });
        } catch (SQLException e) {
            PopupFactory.showError(this, "Failed to load category list.");
        }

        // Set the icon for this frame
        try {
            this.setIconImage(ImageIO.read(new File("images/icon.png")));
        } catch(IOException e) {
            System.out.println("Icon images/icon.png not found");
            e.printStackTrace();
        }
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        MainBackPanel = new javax.swing.JPanel();
        jPanel1 = new javax.swing.JPanel();
        NewTodoButton = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        TodoList = new javax.swing.JList<>();
        jPanel2 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jSeparator1 = new javax.swing.JSeparator();
        OrderByDateButton = new javax.swing.JButton();
        OrderByTitleButton = new javax.swing.JButton();
        DeleteTodoButton = new javax.swing.JButton();
        EditTodoButton = new javax.swing.JButton();
        TitleBackPanel = new javax.swing.JPanel();
        MainLabel = new javax.swing.JLabel();
        LogoutButton = new javax.swing.JButton();
        ChangePasswordButton = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        CategoryList = new javax.swing.JList<>();
        NewCategoryButton = new javax.swing.JButton();
        DeleteCategoryButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("BigThinTall's To-Do List");
        setResizable(false);

        MainBackPanel.setBackground(new java.awt.Color(255, 255, 255));

        NewTodoButton.setBackground(new java.awt.Color(0, 77, 64));
        NewTodoButton.setForeground(new java.awt.Color(255, 255, 255));
        NewTodoButton.setText("New To-Do");
        NewTodoButton.setFocusPainted(false);
        NewTodoButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NewTodoButtonActionPerformed(evt);
            }
        });

        TodoList.setModel(new DefaultListModel());
        jScrollPane1.setViewportView(TodoList);

        jLabel1.setText("Order by");

        jSeparator1.setOrientation(javax.swing.SwingConstants.VERTICAL);

        OrderByDateButton.setBackground(new java.awt.Color(49, 27, 146));
        OrderByDateButton.setForeground(new java.awt.Color(255, 255, 255));
        OrderByDateButton.setText("Due Date");
        OrderByDateButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                OrderByDateButtonActionPerformed(evt);
            }
        });

        OrderByTitleButton.setBackground(new java.awt.Color(49, 27, 146));
        OrderByTitleButton.setForeground(new java.awt.Color(255, 255, 255));
        OrderByTitleButton.setText("Title");
        OrderByTitleButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                OrderByTitleButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(OrderByDateButton, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(OrderByTitleButton, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 14, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(OrderByDateButton)
                    .addComponent(OrderByTitleButton)))
        );

        DeleteTodoButton.setBackground(new java.awt.Color(198, 40, 40));
        DeleteTodoButton.setForeground(new java.awt.Color(255, 255, 255));
        DeleteTodoButton.setText("Delete Selected To-Do");
        DeleteTodoButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DeleteTodoButtonActionPerformed(evt);
            }
        });

        EditTodoButton.setBackground(new java.awt.Color(13, 71, 161));
        EditTodoButton.setForeground(new java.awt.Color(255, 255, 255));
        EditTodoButton.setText("Edit Selected To-Do");
        EditTodoButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EditTodoButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(NewTodoButton, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(DeleteTodoButton, javax.swing.GroupLayout.DEFAULT_SIZE, 179, Short.MAX_VALUE)
                            .addComponent(EditTodoButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(18, 18, 18)
                        .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane1))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(EditTodoButton, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(4, 4, 4)
                        .addComponent(DeleteTodoButton, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(NewTodoButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 446, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        javax.swing.GroupLayout MainBackPanelLayout = new javax.swing.GroupLayout(MainBackPanel);
        MainBackPanel.setLayout(MainBackPanelLayout);
        MainBackPanelLayout.setHorizontalGroup(
            MainBackPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, MainBackPanelLayout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        MainBackPanelLayout.setVerticalGroup(
            MainBackPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        TitleBackPanel.setBackground(new java.awt.Color(13, 71, 161));

        MainLabel.setFont(new java.awt.Font("Arial", 3, 24)); // NOI18N
        MainLabel.setForeground(new java.awt.Color(255, 255, 255));
        MainLabel.setText(" BigThinTall's To-Do List");

        LogoutButton.setBackground(new java.awt.Color(198, 40, 40));
        LogoutButton.setForeground(new java.awt.Color(255, 255, 255));
        LogoutButton.setText("Logout");
        LogoutButton.setFocusPainted(false);
        LogoutButton.setOpaque(false);
        LogoutButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LogoutButtonActionPerformed(evt);
            }
        });

        ChangePasswordButton.setBackground(new java.awt.Color(255, 111, 0));
        ChangePasswordButton.setForeground(new java.awt.Color(255, 255, 255));
        ChangePasswordButton.setText("Change Password");
        ChangePasswordButton.setFocusPainted(false);
        ChangePasswordButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ChangePasswordButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout TitleBackPanelLayout = new javax.swing.GroupLayout(TitleBackPanel);
        TitleBackPanel.setLayout(TitleBackPanelLayout);
        TitleBackPanelLayout.setHorizontalGroup(
            TitleBackPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(TitleBackPanelLayout.createSequentialGroup()
                .addComponent(MainLabel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGap(9, 9, 9)
                .addComponent(ChangePasswordButton)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(LogoutButton)
                .addContainerGap())
        );
        TitleBackPanelLayout.setVerticalGroup(
            TitleBackPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(TitleBackPanelLayout.createSequentialGroup()
                .addComponent(MainLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
            .addGroup(TitleBackPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(TitleBackPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(LogoutButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ChangePasswordButton))
                .addContainerGap())
        );

        CategoryList.setModel(new DefaultListModel());
        CategoryList.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                CategoryListMouseClicked(evt);
            }
        });
        jScrollPane2.setViewportView(CategoryList);

        NewCategoryButton.setBackground(new java.awt.Color(0, 77, 64));
        NewCategoryButton.setForeground(new java.awt.Color(255, 255, 255));
        NewCategoryButton.setText("New Category");
        NewCategoryButton.setFocusPainted(false);
        NewCategoryButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NewCategoryButtonActionPerformed(evt);
            }
        });

        DeleteCategoryButton.setBackground(new java.awt.Color(198, 40, 40));
        DeleteCategoryButton.setForeground(new java.awt.Color(255, 255, 255));
        DeleteCategoryButton.setText("Delete Category");
        DeleteCategoryButton.setFocusPainted(false);
        DeleteCategoryButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DeleteCategoryButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                            .addComponent(NewCategoryButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(DeleteCategoryButton, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(MainBackPanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addComponent(TitleBackPanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(TitleBackPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(MainBackPanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(NewCategoryButton, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(4, 4, 4)
                        .addComponent(DeleteCategoryButton, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane2)))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void LogoutButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LogoutButtonActionPerformed
        Main m = new Main();
        m.setLocationRelativeTo(null);
        m.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_LogoutButtonActionPerformed

    private void CategoryListMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_CategoryListMouseClicked
        int index = CategoryList.locationToIndex(evt.getPoint());

        if (index < 0) {
            // The list is empty
            return;
        }

        String categoryClicked = new String(CategoryList.getModel().getElementAt(index));
        selectedCategory = categoryClicked + "";

        try {
            ArrayList<ToDo> todoFromDb = ToDoDAO.getFromCategory(conn, categoryClicked);

            todos.clear();
            todoList.clear();
            todoFromDb.forEach( (k) -> {
                todos.add(0, k);
                todoList.add(k);
            });
        } catch (SQLException e) {
            PopupFactory.showError(this, "Internal Error");
            e.printStackTrace();
        }
    }//GEN-LAST:event_CategoryListMouseClicked

    private void NewCategoryButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NewCategoryButtonActionPerformed
        StringReceiver rec = new StringReceiver();

        // Open up window to receive text for the name of the new category
        NewCategory strInput = new NewCategory(this, true, rec);
        strInput.setLocationRelativeTo(null);
        strInput.setVisible(true);

        if (!rec.cancelled && rec.message != null){
            // User did input something
            if (rec.message.equals("")) {
                PopupFactory.showError(this, "Cannot create a category with an empty name");
            } else if (rec.message.length() > Macros.MaxLenCategoryName) {
                PopupFactory.showError(this, "Category name must have at most " + Macros.MaxLenCategoryName + " letters");
            } else {

                try {
                    String categoryName = rec.message.trim();

                    if (CategoryDAO.contains(conn, config.userId, categoryName)) {
                        PopupFactory.showError(this, "Category already exists.");
                    } else {
                        // Add to database
                        CategoryDAO.add(conn, config.userId, categoryName);
                        // Add to JList
                        categories.addElement(categoryName);
                        // Add to TreeMap
                        categoryList.add(categoryName);
                    }
                } catch (SQLException e) {
                    PopupFactory.showError(this, "Internal Error");
                    e.printStackTrace();
                }
            }
        }
    }//GEN-LAST:event_NewCategoryButtonActionPerformed

    private void DeleteCategoryButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DeleteCategoryButtonActionPerformed

        StringReceiver rec = new StringReceiver();

        if (categoryList.isEmpty()) {
            PopupFactory.showError(this, "There are no categories to be deleted.");
            return;
        }

        // Create a window where user can choose which category to delete
        DeleteCategory dlt = new DeleteCategory(this, true, rec, new ArrayList<String>(categoryList));
        dlt.setLocationRelativeTo(this);
        dlt.setVisible(true);

        if (!rec.cancelled && rec.message != null) {
            try {
                String categoryName = rec.message.trim();
                // Remove category from database
                CategoryDAO.delete(conn, config.userId, categoryName);
                // Remove category from the list
                categories.removeElement(categoryName);
                // Remove category from the internal list
                categoryList.remove(categoryName);

                // Clear todo listing if the current category is the one active
                if (selectedCategory != null && selectedCategory.equals(categoryName)) {
                    todos.clear();
                    todoList.clear();
                    selectedCategory = null;
                }
            } catch (SQLException e) {
                PopupFactory.showError(this, "Internal Error");
                e.printStackTrace();
            }
        } else {
            // User didn't select a valid category or cancelled
        }
    }//GEN-LAST:event_DeleteCategoryButtonActionPerformed

    private void ChangePasswordButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ChangePasswordButtonActionPerformed
        // New screen to change the password
        ChangePassword changePassword = new ChangePassword(config);
        changePassword.setLocationRelativeTo(null);
        changePassword.setVisible(true);
    }//GEN-LAST:event_ChangePasswordButtonActionPerformed

    private void NewTodoButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NewTodoButtonActionPerformed
        // Pass in ToDo as null because we are not using the form to update the ToDo
        TodoForm nt = new TodoForm(categoryList, null, this);
        nt.setLocationRelativeTo(null);
        nt.setVisible(true);
    }//GEN-LAST:event_NewTodoButtonActionPerformed

    private void OrderByDateButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_OrderByDateButtonActionPerformed
        todoList.sort((e2, e1) -> {
            return e1.due.compareTo(e2.due);
        });

        todos.clear();
        todoList.forEach(k -> {
            todos.add(0, k);
        });
    }//GEN-LAST:event_OrderByDateButtonActionPerformed

    private void OrderByTitleButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_OrderByTitleButtonActionPerformed
        todoList.sort((e2, e1) -> {
            return e1.title.compareTo(e2.title);
        });

        todos.clear();
        todoList.forEach(k -> {
            todos.add(0, k);
        });
    }//GEN-LAST:event_OrderByTitleButtonActionPerformed

    private void DeleteTodoButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_DeleteTodoButtonActionPerformed
        int index = TodoList.getSelectedIndex();

        if (index < 0) {
            // No to-do selected
            return;
        }

        ToDo td = (ToDo)todos.getElementAt(index);

        try {
            ToDoDAO.delete(conn, td.id);
            reloadToDoList();
        } catch (SQLException e) {
            PopupFactory.showError(this, "Internal Error");
            e.printStackTrace();
        }
    }//GEN-LAST:event_DeleteTodoButtonActionPerformed

    private void EditTodoButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EditTodoButtonActionPerformed
        int index = TodoList.getSelectedIndex();

        if (index < 0) {
            // No to-do selected
            return;
        }

        ToDo td = (ToDo) todos.getElementAt(index);

        TodoForm tf = new TodoForm(categoryList, td, this);
        tf.setLocationRelativeTo(null);
        tf.setVisible(true);
    }//GEN-LAST:event_EditTodoButtonActionPerformed

    public void reloadToDoList() {
        if (selectedCategory != null) {
            try {
                ArrayList<ToDo> todoFromDb = ToDoDAO.getFromCategory(conn, selectedCategory);

                todos.clear();
                todoList.clear();
                todoFromDb.forEach( (k) -> {
                    todos.add(0, k);
                    todoList.add(k);
                });
            } catch (SQLException e) {
                PopupFactory.showError(this, "Internal Error");
                e.printStackTrace();
            }
        }
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JList<String> CategoryList;
    private javax.swing.JButton ChangePasswordButton;
    private javax.swing.JButton DeleteCategoryButton;
    private javax.swing.JButton DeleteTodoButton;
    private javax.swing.JButton EditTodoButton;
    private javax.swing.JButton LogoutButton;
    private javax.swing.JPanel MainBackPanel;
    private javax.swing.JLabel MainLabel;
    private javax.swing.JButton NewCategoryButton;
    private javax.swing.JButton NewTodoButton;
    private javax.swing.JButton OrderByDateButton;
    private javax.swing.JButton OrderByTitleButton;
    private javax.swing.JPanel TitleBackPanel;
    private javax.swing.JList<String> TodoList;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JSeparator jSeparator1;
    // End of variables declaration//GEN-END:variables
}
