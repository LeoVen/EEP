/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.dao;

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

        PreparedStatement pStmt = conn.prepareStatement(query);

        pStmt.setString(1, username);
        pStmt.setString(2, email);
        pStmt.setString(3, password);

        pStmt.execute();

        pStmt.close();
    }
}
