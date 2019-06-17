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
import javafx.util.Pair;

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

        String query = "INSERT INTO users (username, email, password) VALUES (?, ?, ?)";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {

            pStmt.setString(1, username);
            pStmt.setString(2, email);
            pStmt.setString(3, password);

            pStmt.execute();
        }
    }

    public static Pair<Boolean, Integer> validate(Connection conn, String username, String password) throws SQLException {
        // String password must be already encrypted

        String query = "SELECT * FROM users WHERE username = ? AND password = ?;";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setString(1, username);
            pStmt.setString(2, password);

            try(ResultSet rs = pStmt.executeQuery()) {
                boolean hasValue = rs.next();
                return new Pair(hasValue, hasValue ? rs.getInt("id") : 0);
            }
        }
    }

    public static void update(Connection conn, int userId, String password) throws SQLException {
        // String password must be already encrypted

        String query = "UPDATE users SET password = ? WHERE id = ?;";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setString(1, password);
            pStmt.setInt(2,userId);

            pStmt.execute();
        }
    }
}
