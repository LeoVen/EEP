/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.spawn;

import btt.Main;
import btt.dao.CategoryDAO;
import btt.db.MySqlDbConnection;
import btt.util.PopupFactory;
import btt.util.StringInput;
import btt.util.StringInputReceiver;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Map;
import javax.swing.DefaultListModel;

/**
 *
 * @author lvenk
 */
public class UserScreen extends javax.swing.JFrame {

    Map<String, Integer> categoryList;
    int userId;
    DefaultListModel categories;

    /**
     * Creates new form UserScreen
     */
    public UserScreen(int userId) {
        this.userId = userId;
        initComponents();
        categories = (DefaultListModel) CategoryList.getModel();

        try (Connection conn = MySqlDbConnection.getConnection()) {
            categoryList = CategoryDAO.get(conn, userId);

            categoryList.forEach( (k, v) -> {
                categories.addElement(k);
            });
        } catch (SQLException e) {
            e.printStackTrace();
            PopupFactory.showError(this, "Failed to load category list.");
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
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
        TitleBackPanel = new javax.swing.JPanel();
        MainLabel = new javax.swing.JLabel();
        LogoutButton = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        CategoryList = new javax.swing.JList<>();
        NewCategoryButton = new javax.swing.JButton();
        DeleteCategoryButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        MainBackPanel.setBackground(new java.awt.Color(255, 255, 255));

        NewTodoButton.setBackground(new java.awt.Color(13, 71, 161));
        NewTodoButton.setForeground(new java.awt.Color(255, 255, 255));
        NewTodoButton.setText("New To-Do");

        jScrollPane1.setViewportView(TodoList);

        jLabel1.setText("Order by");

        jSeparator1.setOrientation(javax.swing.SwingConstants.VERTICAL);

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel1)
                .addContainerGap(442, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 14, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

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
                        .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane1))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(NewTodoButton, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 34, Short.MAX_VALUE))
                    .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
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

        javax.swing.GroupLayout TitleBackPanelLayout = new javax.swing.GroupLayout(TitleBackPanel);
        TitleBackPanel.setLayout(TitleBackPanelLayout);
        TitleBackPanelLayout.setHorizontalGroup(
            TitleBackPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(TitleBackPanelLayout.createSequentialGroup()
                .addComponent(MainLabel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(LogoutButton)
                .addContainerGap())
        );
        TitleBackPanelLayout.setVerticalGroup(
            TitleBackPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(TitleBackPanelLayout.createSequentialGroup()
                .addComponent(MainLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, TitleBackPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(LogoutButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
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
        NewCategoryButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NewCategoryButtonActionPerformed(evt);
            }
        });

        DeleteCategoryButton.setBackground(new java.awt.Color(198, 40, 40));
        DeleteCategoryButton.setForeground(new java.awt.Color(255, 255, 255));
        DeleteCategoryButton.setText("Delete Category");

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

        String categoryClicked = new String(CategoryList.getModel().getElementAt(index));

        System.out.println(categoryClicked);
    }//GEN-LAST:event_CategoryListMouseClicked

    private void NewCategoryButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NewCategoryButtonActionPerformed
        StringInputReceiver rec = new StringInputReceiver();

        StringInput strInput = new StringInput(this, true, "Insert the new category's name.", rec);
        strInput.setLocationRelativeTo(null);
        strInput.setVisible(true);

        if (!rec.cancelled) {
            // User did input something
            if (rec.message.equals("")) {
                PopupFactory.showError(this, "Can not create a category with an empty name");
            } else {
                try (Connection conn = MySqlDbConnection.getConnection()) {
                    // Add to database
                    CategoryDAO.add(conn, userId, rec.message);
                    // Add to JList
                    categories.addElement(rec.message);
                } catch (SQLException e) {
                    PopupFactory.showError(this, "Internal Error");
                    e.printStackTrace();
                }
            }
        }
    }//GEN-LAST:event_NewCategoryButtonActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JList<String> CategoryList;
    private javax.swing.JButton DeleteCategoryButton;
    private javax.swing.JButton LogoutButton;
    private javax.swing.JPanel MainBackPanel;
    private javax.swing.JLabel MainLabel;
    private javax.swing.JButton NewCategoryButton;
    private javax.swing.JButton NewTodoButton;
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
