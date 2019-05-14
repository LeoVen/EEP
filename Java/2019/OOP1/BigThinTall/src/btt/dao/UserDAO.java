/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.dao;

import btt.util.PasswordEncryption;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author lvenk
 */
public class UserDAO {

    public static boolean contains(Connection conn, String username) throws SQLException {
        
        PreparedStatement pStmt = conn.prepareStatement("SELECT * FROM users WHERE username = ? ;");

        pStmt.setString(1, username);

        ResultSet rs = pStmt.executeQuery();

        boolean result = rs.next();

        rs.close();
        pStmt.close();

        return result;
    }

    public static void create(Connection conn, String username, String email, String password) throws SQLException {

        String query = "INSERT INTO users (username, email, password) values (?, ?, ?)";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {

            pStmt.setString(1, username);
            pStmt.setString(2, email);
            pStmt.setString(3, password);

            pStmt.execute();
        }
    }

    public static boolean validate(Connection conn, String username, String password) throws SQLException {
        // String password must be already encrypted

        String query = "SELECT * FROM users WHERE username = ? and password = ?;";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setString(1, username);
            pStmt.setString(2, password);

            try(ResultSet rs = pStmt.executeQuery()) {
                return rs.next();
            }
        }
    }
}
