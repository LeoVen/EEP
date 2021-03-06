package btt.screens;

import btt.dao.UserDAO;
import btt.db.Macros;
import btt.db.MySqlDbConnection;
import btt.util.PasswordEncryption;
import btt.util.PopupFactory;
import java.sql.Connection;
import java.sql.SQLException;


public class Signup extends javax.swing.JFrame {


    public Signup() {
        initComponents();
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        UserInputEmail = new javax.swing.JTextField();
        UserInputName = new javax.swing.JTextField();
        UserInputPassword = new javax.swing.JPasswordField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        SignupButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("BTT - Signup");

        jPanel1.setPreferredSize(new java.awt.Dimension(400, 250));

        jLabel1.setText("Username");

        jLabel2.setText("Password");

        jLabel3.setText("E-mail");

        SignupButton.setBackground(new java.awt.Color(0, 77, 64));
        SignupButton.setForeground(new java.awt.Color(255, 255, 255));
        SignupButton.setText("Signup");
        SignupButton.setFocusPainted(false);
        SignupButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SignupButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(47, 47, 47)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(30, 30, 30)
                        .addComponent(UserInputName, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addComponent(jLabel2))
                        .addGap(32, 32, 32)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(UserInputPassword, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(UserInputEmail, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(105, 105, 105)
                .addComponent(SignupButton, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(105, 105, 105))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(UserInputName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(25, 25, 25)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(UserInputPassword, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(25, 25, 25)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(UserInputEmail, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 53, Short.MAX_VALUE)
                .addComponent(SignupButton, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(25, 25, 25))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(50, 50, 50)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(50, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(50, 50, 50)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(50, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void SignupButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SignupButtonActionPerformed

        boolean userCreated = false;

        try {
            // Get form content
            String username = UserInputName.getText().trim();
            String email = UserInputEmail.getText().trim();
            String password = new String(UserInputPassword.getPassword());

            String errorMessage = "";

            // Treat username and email maximum length
            if (username.length() > Macros.MaxLenUsername)
                errorMessage = errorMessage + "Username must contain at most " + Macros.MaxLenUsername + " characters.<br>";
            if (email.length() > Macros.MaxLenEmail)
                errorMessage = errorMessage + "Email must contain at most " + Macros.MaxLenEmail + " characters.<br>";

            // Treat the absence of any required field
            if (username.equals(""))
                errorMessage = errorMessage + "User must not be empty.<br>";
            if (email.equals(""))
                errorMessage = errorMessage + "Email must not be emtpy.<br>";
            if (password.equals(""))
                errorMessage = errorMessage + "Password must not be emtpy.<br>";

            if (!errorMessage.equals("")) {
                PopupFactory.showError(this, errorMessage);
            }
            else {
                // Get default connection
                Connection conn = MySqlDbConnection.getConnection();

                // Database connection error
                if (conn == null) {
                    PopupFactory.showError(this, "Database connection error.");
                }
                // Check if user doesn't exist already
                else if (UserDAO.contains(conn, username)) {
                    PopupFactory.showError(this, "User already exists. <br> Please try another username.");
                }
                // Connection to DB is good and user doesn't exist
                else {
                    // Get password hash
                    String encPassword = PasswordEncryption.getSHA1(password);

                    // Create user
                    UserDAO.create(conn, username, email, encPassword);

                    userCreated = true;
                }

                // Closing resources
                if (conn != null)
                    conn.close();
            }

        } catch (NullPointerException e) {
            System.out.println("Document not found in Signup form");
            PopupFactory.showError(this, "Internal Error");
        } catch (SQLException e) {
            System.out.println("Something went wrong with that sql!");
            e.printStackTrace();
            PopupFactory.showError(this, "Internal Error");
        }

        if (userCreated) {
            PopupFactory.showSuccess(this, "User Created Successfully");
            this.dispose();
        }
    }//GEN-LAST:event_SignupButtonActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton SignupButton;
    private javax.swing.JTextField UserInputEmail;
    private javax.swing.JTextField UserInputName;
    private javax.swing.JPasswordField UserInputPassword;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
