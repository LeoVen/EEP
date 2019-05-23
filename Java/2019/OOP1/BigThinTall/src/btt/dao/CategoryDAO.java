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
import java.util.HashMap;

/**
 *
 * @author lvenk
 */
public class CategoryDAO {

    public static HashMap<String, Integer> get(Connection conn, int userId) throws SQLException {
        HashMap<String, Integer> categories = new HashMap<>();

        String query = "SELECT * FROM categories where userid = ?;";
        
        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setInt(1, userId);

            try(ResultSet rs = pStmt.executeQuery()) {
                while (rs.next()) {
                    categories.put(rs.getString("name"), rs.getInt("id"));
                }
            }
        }

        return categories;
    }

    public static void add(Connection conn, int userId, String categoryName) throws SQLException {
        String query = "INSERT INTO categories (userid, name) values (?, ?);";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setInt(1, userId);
            pStmt.setString(2, categoryName);

            pStmt.execute();
        }
    }
}
